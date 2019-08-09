#pragma once
#include <QGLWidget>
#include <QtWidgets>
#include <QtOpenGL>
#include <Qtgui>
#include <math.h>

class Etat
{
private:
	unsigned int largeur;
public:
	unsigned int getLargeur() const { return largeur; }
    void setLargeur(unsigned int value) { largeur = value; }
    void setCellule();
	int getCellule ();
};

class Etat_3D : public Etat
{
private:
    unsigned int hauteur;
    unsigned int profondeur;
    int* valeurs;
public:
    Etat_3D();
    Etat_3D(const Etat_3D& etat);
    Etat_3D(unsigned int h, unsigned int l, unsigned int p);
    unsigned int getHauteur() const { return hauteur; }
    void setHauteur(unsigned int value) { hauteur = value; }
    unsigned int getProfondeur() const { return profondeur; }
    void setProfondeur(unsigned int value) { profondeur = value; }
    Etat_3D& operator = (const Etat_3D& e);
    ~Etat_3D()
    {
        delete[] valeurs;
    }
    void random3D();
    void setCellule(int index_hauteur, int index_largeur, int index_profondeur, int value);
    int getCellule(int index_hauteur, int index_largeur, int index_profondeur) const;
    void draw();
};



