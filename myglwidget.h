#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QtWidgets>
#include <QtOpenGL>
#include <Qtgui>
#include <math.h>
#include "Etat.h"

class MyGLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit MyGLWidget(QWidget *parent = 0);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    Etat_3D *state;

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);
public:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private:
    int xRot;
    int yRot;
    int zRot;
    QPoint lastPos;
};

#endif // MYGLWIDGET_H
