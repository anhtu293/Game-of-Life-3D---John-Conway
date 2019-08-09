#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QSpinBox>
#include <QLineEdit>
#include <QLabel>
#include <QIntValidator>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QTextEdit>
#include <QHeaderView>
#include <QAbstractItemView>
#include <QPushButton>
#include <QFont>
#include <QApplication>
#include <QFormLayout>
#include <QObject>
#include <QtWidgets>
#include "automate.h"
#include "myglwidget.h"
#include <QSlider>

class AutoCell : public QWidget
{
Q_OBJECT

    QHBoxLayout *layout;

    QTabWidget *onglets;

    QWidget *page1;
    QWidget *page2;
    QWidget *page3;

    QTableWidget *simulation;

    QVBoxLayout *vbox1_3D; //Box Vertical Partie Droite

    QHBoxLayout *hboxSimulation_3D;
    QHBoxLayout *hboxAuto_3D;
    QHBoxLayout *hboxManual_3D;
    QHBoxLayout *hboxSave_3D;

    //Execution Manuelle
    QPushButton *random_3D;
    QPushButton *oneByOne_3D;

    //Execution automatique
    QPushButton *launch_3D;
    QSpinBox* frequency_3D;
    QLabel* chooseStep_3D;

    //Partie sauvegarde
    QTextEdit* browse_3D;
    QPushButton* import_3D;
    QPushButton* xport_3D;

    //Quitter
    QPushButton *quit_3D;

    //title of tab Jeu bonus
    QLabel* titre1_3D;
    QLabel* titre2_3D;
    QLabel* titre3_3D;

    //Configuration
    QLabel* titre4_3D;
    QLabel* chooseSize_3D;
    QLabel* chooseNbMaxVoisins_3D;
    QLabel* chooseNbMinVoisins_3D;
    QLabel* chooseNbNaisVoisins_3D;
    QSpinBox* size_3D;
    QSpinBox* nbMaxVoisins_3D;
    QSpinBox* nbMinVoisins_3D;
    QSpinBox* nbNaisVoisins_3D;
    QHBoxLayout* hbsize_3D;
    QHBoxLayout* hbnbmax_3D;
    QHBoxLayout* hbnbmin_3D;
    QHBoxLayout* hbnbnais_3D;
    QVBoxLayout* vbconfiguration_3D; //Layout of Configuration

    QHBoxLayout* hbprincipal_3D;
    QVBoxLayout* vbprincipal_3D;


    unsigned int dimension_3D;

    Auto_3D *auto3D;
    MyGLWidget *simulation3D;
    QSlider *xSlider_3D;
    QSlider *ySlider_3D;
    QSlider *zSlider_3D;

    //Titres fenetre 1
    QHBoxLayout *ht1_3D;
    QHBoxLayout *ht2_3D;
    QHBoxLayout *ht3_3D;






private slots:
    void launchRandom_3D();
    void launchNext_3D();
    void launchNonStop_3D();
    void launchChangeSize_3D(int val);
    void launchChangeMaxVoisins_3D(int val);
    void launchChangeMinVoisins_3D(int val);
    void launchChangeNaisVoisins_3D(int val);
public:

    explicit AutoCell(QWidget* parent = nullptr);
};


#endif
