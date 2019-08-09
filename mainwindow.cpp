#include "mainwindow.h"
#include <iostream>
#include <unistd.h>
#include "gl/gl.h"
#include "gl/glu.h"
#define FREEGLUT_STATIC
#include "math.h"


#include "automate.h"

AutoCell::AutoCell(QWidget* parent):QWidget(parent)
{

    layout=new QHBoxLayout;

    onglets = new QTabWidget(this);

    page1 = new QWidget;
    page2 = new QWidget;
    page3 = new QWidget;

    //-----------------------PAGE 3-------------------------------


    //initialize with dimension = 8, nbMinVoisins = 2, nbMaxVoisins = 3, nbNaisvoisins = 2
    dimension_3D = 8;

    //-------------jeu 3D-------------
    auto3D = new Auto_3D(2, 3, 2);
    simulation3D = new MyGLWidget(this);

    //------------resize screen-----------
    simulation3D -> resizeGL(800,800);

    hboxSimulation_3D = new QHBoxLayout;
    hboxSimulation_3D -> addWidget(simulation3D);


    //-----------Manual execution-----------
    titre1_3D = new QLabel(this);
    titre1_3D -> setText("Execution manuelle");
    titre1_3D -> setFont(QFont("Arial", 10, QFont::Bold, false));

    random_3D = new QPushButton("Aléatoire", this);
    QObject::connect(random_3D, SIGNAL(clicked()), this, SLOT(launchRandom_3D()));

    oneByOne_3D = new QPushButton("Coup par coup", this);
    QObject::connect(oneByOne_3D, SIGNAL(clicked()), this, SLOT(launchNext_3D()));


    //------------automatic execution---------------
    titre2_3D = new QLabel(this);
    titre2_3D -> setText("Execution automatique");
    titre2_3D -> setFont(QFont("Arial", 10, QFont::Bold, false));

    launch_3D = new QPushButton("Lancer !", this);
    QObject::connect(launch_3D, SIGNAL(clicked()), this, SLOT(launchNonStop_3D()));

    frequency_3D = new QSpinBox(this);
    frequency_3D -> setMinimum(0);
    frequency_3D -> setMaximum(100);

    chooseStep_3D = new QLabel(this);
    chooseStep_3D -> setText("Choisir le pas (sec)");

    titre3_3D = new QLabel(this);
    titre3_3D -> setText("Sauvegarde");
    titre3_3D -> setFont(QFont("Arial", 10, QFont::Bold, false));


    //----------------sauvegarde--------------

    browse_3D = new QTextEdit("C://Documents/blabla.uml",this);
    browse_3D -> setMaximumHeight(30);
    import_3D = new QPushButton("Importer un état");
    xport_3D = new QPushButton("Sauvegarder l'état");


    //--------------Footer----------------
    quit_3D = new QPushButton("Quitter", this);
    QObject::connect(quit_3D, SIGNAL(clicked()), qApp, SLOT(quit()));


    vbox1_3D = new QVBoxLayout;


    //Créer les titres sur la fenetre
    ht1_3D = new QHBoxLayout;
    ht2_3D = new QHBoxLayout;
    ht3_3D = new QHBoxLayout;
    ht1_3D -> addWidget(titre1_3D);
    ht2_3D -> addWidget(titre2_3D);
    ht3_3D -> addWidget(titre3_3D);

    hboxManual_3D = new QHBoxLayout;
    hboxManual_3D -> addWidget(random_3D);
    hboxManual_3D -> addWidget(oneByOne_3D);

    hboxAuto_3D = new QHBoxLayout;
    hboxAuto_3D -> addWidget(chooseStep_3D);
    hboxAuto_3D -> addWidget(frequency_3D);
    hboxAuto_3D -> addWidget(launch_3D);

    hboxSave_3D = new QHBoxLayout;
    hboxSave_3D -> addWidget(browse_3D);
    hboxSave_3D-> addWidget(import_3D);
    hboxSave_3D -> addWidget(xport_3D);

    vbox1_3D -> addLayout(ht1_3D);
    vbox1_3D -> addLayout(hboxManual_3D);
    vbox1_3D -> addLayout(ht2_3D);
    vbox1_3D -> addLayout(hboxAuto_3D);
    vbox1_3D -> addLayout(ht3_3D);
    vbox1_3D -> addLayout(hboxSave_3D);


    //-----------Configuration---------------
    titre4_3D = new QLabel(this);
    titre4_3D -> setText("Configuration");
    titre4_3D -> setFont(QFont("Arial", 10, QFont::Bold, false));


    //change size of cube
    chooseSize_3D = new QLabel(this);
    chooseSize_3D -> setText("Choisir taille du cube");

    size_3D = new QSpinBox(this);
    size_3D -> setMinimum(3);
    size_3D -> setMaximum(15);
    size_3D -> setValue(8);
    QObject::connect(size_3D, SIGNAL(valueChanged(int)),this, SLOT(launchChangeSize_3D(int)));

    //change nombre de voisins max
    chooseNbMaxVoisins_3D = new QLabel(this);
    chooseNbMaxVoisins_3D -> setText("Choisir le nombre maximal de voisins");

    nbMaxVoisins_3D = new QSpinBox(this);
    nbMaxVoisins_3D -> setMinimum(1);
    nbMaxVoisins_3D -> setMaximum(26);
    nbMaxVoisins_3D -> setValue(3);
    QObject::connect(nbMaxVoisins_3D, SIGNAL(valueChanged(int)), this, SLOT(launchChangeMaxVoisins_3D(int)));


    //change nombre de voisins min
    chooseNbMinVoisins_3D = new QLabel(this);
    chooseNbMinVoisins_3D -> setText("Choisir le nombre minimal de voisins");

    nbMinVoisins_3D = new QSpinBox(this);
    nbMinVoisins_3D -> setMinimum(0);
    nbMinVoisins_3D -> setMaximum(26);
    nbMinVoisins_3D -> setValue(2);
    QObject::connect(nbMinVoisins_3D, SIGNAL(valueChanged(int)), this, SLOT(launchChangeMinVoisins_3D(int)));

    chooseNbNaisVoisins_3D = new QLabel(this);
    chooseNbNaisVoisins_3D -> setText("Choisir le nombre maximal de voisins");

    nbNaisVoisins_3D = new QSpinBox(this);
    nbNaisVoisins_3D -> setMinimum(1);
    nbNaisVoisins_3D -> setMaximum(27);
    nbNaisVoisins_3D -> setValue(2);
    QObject::connect(nbNaisVoisins_3D, SIGNAL(valueChanged(int)), this, SLOT(launchChangeNaisVoisins_3D(int)));


    //add widgets and layouts
    hbsize_3D = new QHBoxLayout;
    hbsize_3D -> addWidget(chooseSize_3D);
    hbsize_3D -> addWidget(size_3D);

    hbnbmax_3D = new QHBoxLayout;
    hbnbmax_3D -> addWidget(chooseNbMaxVoisins_3D);
    hbnbmax_3D -> addWidget(nbMaxVoisins_3D);

    hbnbmin_3D = new QHBoxLayout;
    hbnbmin_3D -> addWidget(chooseNbMinVoisins_3D);
    hbnbmin_3D -> addWidget(nbMinVoisins_3D);

    hbnbnais_3D = new QHBoxLayout;
    hbnbnais_3D -> addWidget(chooseNbNaisVoisins_3D);
    hbnbnais_3D -> addWidget(nbNaisVoisins_3D);

    vbconfiguration_3D = new QVBoxLayout;
    vbconfiguration_3D -> addWidget(titre4_3D);
    vbconfiguration_3D -> addLayout(hbsize_3D);
    vbconfiguration_3D -> addLayout(hbnbmax_3D);
    vbconfiguration_3D -> addLayout(hbnbmin_3D);
    vbconfiguration_3D -> addLayout(hbnbnais_3D);

    hbprincipal_3D = new QHBoxLayout;
    hbprincipal_3D -> addLayout(vbconfiguration_3D);
    hbprincipal_3D -> addLayout(vbox1_3D);

    vbprincipal_3D = new QVBoxLayout;
    vbprincipal_3D -> addLayout(hboxSimulation_3D);
    vbprincipal_3D -> addLayout(hbprincipal_3D);
    vbprincipal_3D -> addWidget(quit_3D);
    page3->setLayout(vbprincipal_3D);


    // 4 : ajouter les onglets au QTabWidget, en indiquant la page qu'ils contiennent
    onglets->addTab(page1, "Jeu de la vie");
    onglets->addTab(page2, "Jeu une dimension");
    onglets->addTab(page3, "Jeu Bonus");

    layout->addWidget(onglets);
    this->setLayout(layout);


}
void AutoCell::launchRandom_3D()
{
    //Random an initial cube
    simulation3D -> state -> random3D();
    simulation3D -> paintGL();
    simulation3D -> updateGL();
}

void AutoCell::launchNext_3D()
{
    //Manual execution
    Etat_3D etat_dest = Etat_3D(*(simulation3D -> state));
    auto3D -> appliquerTransition(*(simulation3D->state), etat_dest);
    *(simulation3D -> state) = etat_dest;
    simulation3D -> paintGL();
    simulation3D -> updateGL();
}

void AutoCell::launchNonStop_3D()
{
    //automatic execution
    Etat_3D etat_dest = Etat_3D(*(simulation3D -> state));
    int pas = frequency_3D -> value();
    for (int i = 0; i < pas; i++)
    {
        etat_dest = Etat_3D(*(simulation3D -> state));
        auto3D -> appliquerTransition(*(simulation3D->state), etat_dest);
        *(simulation3D -> state) = etat_dest;
        simulation3D -> paintGL();
        simulation3D -> updateGL();
        sleep(1);
    }
}

void AutoCell::launchChangeSize_3D(int val)
{
    //change size
    dimension_3D = val;
    delete simulation3D -> state;
    simulation3D -> state = new Etat_3D(val, val, val);
    simulation3D -> state -> random3D();
    simulation3D -> paintGL();
    simulation3D -> updateGL();
}

void AutoCell::launchChangeMaxVoisins_3D(int val)
{
    //il faut verifier si la nouvelle valeur est superieure a le nombre voisins min. Si oui, changer la valeur. Si non, la nouvelle nb max voisins est nb min voisins
    if (val >= nbMinVoisins_3D -> value())
    {
        auto3D -> setMaxvoisins(val);
    }
    else
    {
        nbMaxVoisins_3D -> setValue(nbMinVoisins_3D -> value());
        auto3D -> setMaxvoisins(nbMinVoisins_3D -> value());
    }
}

void AutoCell::launchChangeMinVoisins_3D(int val)
{
    //il faut verifier si la nouvelle valeur est inferieure a le nombre voisins max. Si oui, changer la valeur. Si non, la nouvelle nb min voisins est nb max voisins
    if (val <= nbMaxVoisins_3D -> value())
    {
        auto3D -> setMinvoisins(val);
    }
    else
    {
        nbMinVoisins_3D -> setValue(nbMaxVoisins_3D -> value());
        auto3D -> setMinvoisins(nbMinVoisins_3D -> value());
    }
}

void AutoCell::launchChangeNaisVoisins_3D(int val)
{
    auto3D -> setNaisvoisins(val);
}
