#include "automate.h"
#include <iostream>
Automate::Automate()
{

}
Auto_3D::Auto_3D()
{
    voisins_min_vivre = 2;
    voisins_max_vivre = 3;
    voisins_necessaires_naissance = 2;
}
Auto_3D::Auto_3D(unsigned int mini, unsigned int maxi, unsigned int nait )
{
    voisins_min_vivre = mini;
    voisins_max_vivre = maxi;
    voisins_necessaires_naissance = nait;
}

int nombreVoisins3D(Etat_3D etat, int index_ligne, int index_colonne, int index_profondeur)
{
    int h = etat.getHauteur();
    int l = etat.getLargeur();
    int p = etat.getProfondeur();
    unsigned int compteur = 0;
    for(int a = index_ligne - 1; a < index_ligne+2; a++)
    {
        for(int b = index_colonne - 1; b < index_colonne+2; b++)
        {
            for (int c = index_profondeur - 1; c < index_profondeur+2; c++)
            {
                if(etat.getCellule((a+h)%h, (b+l)%l, (c + p)%p) == 1)
                    compteur++;
            }
        }
    }
    if(etat.getCellule(index_ligne,index_colonne, index_profondeur)==1)
        compteur--;
    return compteur;
}

void Auto_3D::appliquerTransition(Etat_3D& etat_depart, Etat_3D& etat_dest)
{
    //etat_dest = etat_depart;
    unsigned int h = etat_depart.getHauteur();
    unsigned int l = etat_depart.getLargeur();
    unsigned int p = etat_depart.getProfondeur();
    for (unsigned int k = 0; k < p; k++)
    {
        for (unsigned int i = 0; i < h; i++)
        {
            for (unsigned int j = 0; j < l; j++)
            {
                etat_dest.setCellule(i, j, k, etat_depart.getCellule(i,j,k));
            }
        }
    }
    int nombreVoisins;
    for (unsigned int k = 0; k < p; k++)
    {
        for (unsigned int i = 0; i < h; i++)
        {
            for (unsigned int j = 0; j < l; j++)
            {
                nombreVoisins=nombreVoisins3D(etat_depart, i, j, k);
                if((nombreVoisins == voisins_necessaires_naissance) && (etat_depart.getCellule(i, j, k) == 0))
                {
                    etat_dest.setCellule(i, j, k, 1);
                }
                if((nombreVoisins < voisins_min_vivre || nombreVoisins > voisins_max_vivre) && etat_depart.getCellule(i, j, k) == 1)
                {
                    etat_dest.setCellule(i, j, k, 0);
                }
            }
        }
    }
}
