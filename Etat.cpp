#include "Etat.h"
#include <GL/glu.h>
#include <iostream>

Etat_3D::Etat_3D(unsigned int h, unsigned int l, unsigned int p)
{
    valeurs = new int[h*l*p];
    setLargeur(l);
    setHauteur(h);
    setProfondeur(p);
}
Etat_3D::Etat_3D(const Etat_3D& etat)
{
    setHauteur(etat.getHauteur());
    setLargeur(etat.getLargeur());
    setProfondeur(etat.getProfondeur());
    int dimension = getHauteur()*getLargeur()*getProfondeur();
    valeurs = new int[dimension];
    for (unsigned int k = 0; k < getProfondeur(); k++)
    {
        for (unsigned int i = 0; i < getHauteur(); i++)
        {
            for (unsigned int j = 0; j < getLargeur(); j++)
            {
                valeurs[k*getProfondeur()*getProfondeur() + i*getHauteur() +j] = etat.valeurs[k*getProfondeur()*getProfondeur() + i*getHauteur() +j];
            }
        }
    }
}
Etat_3D& Etat_3D::operator = (const Etat_3D& e)
{
    if (this != &e)
    {
        if (hauteur != e.hauteur)
        {
            int* newvaleur = new int[e.hauteur * e.hauteur * e.hauteur];
            for (unsigned int k = 0; k < getProfondeur(); k++)
            {
                for (unsigned int i = 0; i < getHauteur(); i++)
                {
                    for (unsigned int j = 0; j < getLargeur(); j++)
                    {
                        newvaleur[k*getProfondeur()*getProfondeur() + i*getHauteur() +j] = e.valeurs[k*getProfondeur()*getProfondeur() + i*getHauteur() +j];
                    }
                }
            }
            int* old = valeurs;
            valeurs = newvaleur;
            hauteur = e.hauteur;
            setLargeur(e.getLargeur());
            profondeur = e.profondeur;
            delete[] old;
        }
        else
            for (unsigned int k = 0; k < getProfondeur(); k++)
            {
                for (unsigned int i = 0; i < getHauteur(); i++)
                {
                    for (unsigned int j = 0; j < getLargeur(); j++)
                    {
                        valeurs[k*getProfondeur()*getProfondeur() + i*getHauteur() +j] = e.valeurs[k*getProfondeur()*getProfondeur() + i*getHauteur() +j];
                    }
                }
            }
    }
    return *this;
}
void Etat_3D::random3D()
{
    unsigned int p = getProfondeur();
    unsigned int h = getHauteur();
    unsigned int l = getLargeur();
    for (unsigned int k = 0; k < p; k++)
    {
        for (unsigned int i = 0; i < h; i++)
        {
            for (unsigned int j = 0; j < l; j++)
            {
                setCellule(i, j, k, rand() % 2 - rand() % 2); //use rand() % 2 - rand() %2 to creat more 0 than 1
            }
        }
    }
}
int Etat_3D::getCellule(int index_hauteur, int index_largeur, int index_profondeur) const
{
    return valeurs[index_hauteur*getHauteur()+index_largeur+index_profondeur*getProfondeur()*getProfondeur()];
}

void Etat_3D::setCellule(int index_hauteur, int index_largeur, int index_profondeur, int value)
{
    valeurs[index_hauteur*getHauteur()+index_largeur+index_profondeur*getProfondeur()*getProfondeur()] = value;
}

void Etat_3D::draw()
{

    glPushMatrix();

        for (unsigned int k = 0; k < getProfondeur(); k++)
        {
            for (unsigned int i = 0; i < getHauteur(); i++)
            {
                for (unsigned int j = 0; j < getLargeur(); j++)
                {
                     if (getCellule(i,j,k) == 1)
                    {
                         //draw fill
                        glColor3f(1.0f, 0.5f, 0.0f);
                        glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

                        //front
                        glBegin(GL_QUADS);
                        glVertex3d( i, j, k);
                        glVertex3d(i+1, j, k);
                        glVertex3d((i+1), (j+1), k);
                        glVertex3d(i, (j+1), k);

                        //back
                        glVertex3d(i, j,(k+1));
                        glVertex3d((i+1), j,(k+1));
                        glVertex3d((i+1), (j+1),(k+1));
                        glVertex3d(i, (j+1),(k+1));

                        //top
                        glVertex3d(i, (j+1),k);
                        glVertex3d((i+1), (j+1),k);
                        glVertex3d((i+1), (j+1),(k+1));
                        glVertex3d(i, (j+1),(k+1));

                        //bottom
                        glVertex3d(i, j,k);
                        glVertex3d((i+1), j,k);
                        glVertex3d((i+1), j,(k+1));
                        glVertex3d(i, j,(k+1));

                        //left
                        glVertex3d(i, j,k);
                        glVertex3d(i, j,(k+1));
                        glVertex3d(i, (j+1),(k+1));
                        glVertex3d(i, (j+1),k);

                        //right
                        glVertex3d((i+1), j,k);
                        glVertex3d((i+1), j,(k+1));
                        glVertex3d((i+1), (j+1),(k+1));
                        glVertex3d((i+1), (j+1),k);
                        glEnd();


                        //draw line
                        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
                        glColor3f(1.0f, 1.0f, 1.0f);
                        glBegin(GL_QUADS);
                        glVertex3d( i, j, k);
                        glVertex3d(i+1, j, k);
                        glVertex3d((i+1), (j+1), k);
                        glVertex3d(i, (j+1), k);

                        //back
                        glVertex3d(i, j,(k+1));
                        glVertex3d((i+1), j,(k+1));
                        glVertex3d((i+1), (j+1),(k+1));
                        glVertex3d(i, (j+1),(k+1));

                        //top
                        glVertex3d(i, (j+1),k);
                        glVertex3d((i+1), (j+1),k);
                        glVertex3d((i+1), (j+1),(k+1));
                        glVertex3d(i, (j+1),(k+1));

                        //bottom
                        glVertex3d(i, j,k);
                        glVertex3d((i+1), j,k);
                        glVertex3d((i+1), j,(k+1));
                        glVertex3d(i, j,(k+1));

                        //left
                        glVertex3d(i, j,k);
                        glVertex3d(i, j,(k+1));
                        glVertex3d(i, (j+1),(k+1));
                        glVertex3d(i, (j+1),k);

                        //right
                        glVertex3d((i+1), j,k);
                        glVertex3d((i+1), j,(k+1));
                        glVertex3d((i+1), (j+1),(k+1));
                        glVertex3d((i+1), (j+1),k);
                        glEnd();
                    }
                }
            }
        }
    glPopMatrix();
}
