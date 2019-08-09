#ifndef AUTOMATE_H
#define AUTOMATE_H
#include "Etat.h"

class Automate
{
private:
    int largeur;
public:
    Automate();
    //virtual void appliquerTransition(Etat& etat_depart, Etat etat_dest) = 0;
};


class Auto_3D : public Automate
{
private:
    int voisins_min_vivre;
    int voisins_max_vivre;
    int voisins_necessaires_naissance;
public:
    Auto_3D(unsigned int mini, unsigned int maxi, unsigned int nait);
    void setMaxvoisins(int val) { voisins_max_vivre = val; }
    void setMinvoisins(int val) { voisins_min_vivre = val; }
    void setNaisvoisins(int val) { voisins_necessaires_naissance = val; }
    void appliquerTransition(Etat_3D&  etat_depart, Etat_3D& etat_dest);
    explicit Auto_3D();
};
int nombreVoisins3D(Etat_3D etat, int index_ligne, int index_colonne, int index_profondeur);


#endif // AUTOMATE_H
