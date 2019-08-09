#include "myglwidget.h"
#include <iostream>
#include "GL/glu.h"
#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE 0x809D
#endif
MyGLWidget::MyGLWidget(QWidget *parent) : QGLWidget( parent)
{
    //initialize with cube dimension = 8
    state = new Etat_3D(8, 8, 8);
    xRot = 0;
    yRot = 0;
    zRot = 0;
    state->random3D();
}

QSize MyGLWidget::minimumSizeHint() const
{
    return QSize(50,50);
}

QSize MyGLWidget::sizeHint() const
{
    return QSize(400,400);
}

static void calculAngle(int &angle)
{
    //calculate a new angle of rotation
    while (angle < 0)
    {
        angle += 360 * 16;
    }
    while (angle > 360)
    {
        angle -= 360 * 16;
    }
}

void MyGLWidget::setXRotation(int angle)
{
    calculAngle(angle);
    if (angle != xRot)
    {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setYRotation(int angle)
{
    calculAngle(angle);
    if (angle != yRot)
    {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setZRotation(int angle)
{
    calculAngle(angle);
    if (angle != zRot)
    {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-2.0, -2.0, -10.0);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
    state -> draw();
}

void MyGLWidget::resizeGL(int w, int h)
{
    if (h == 0)
    {
        h = 1;
    }
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)w/(GLfloat)h, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event -> pos();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    //control mouse event
    int dx = event -> x() - lastPos.x();
    int dy = event -> y() - lastPos.y();

    if (event -> buttons() & Qt::LeftButton)
    {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    }
    else if (event ->buttons() & Qt::RightButton)
    {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }

    lastPos = event -> pos();
}

