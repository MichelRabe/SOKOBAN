#ifndef OBJETGRAPHIQUE_H
#define OBJETGRAPHIQUE_H


#include <QtWidgets>
#include "point.h"


enum Type {Vide, Mur, Objectif, Caisse, Personnage};
enum Direction {Haut, Bas, Gauche, Droite};


// Classe abstraite
class ObjetGraphique{
    protected:
        Point m_point;
        QPixmap *m_image;
    public:
        ObjetGraphique(Point p = Point(0,0), QPixmap *image = 0);
        virtual ~ObjetGraphique();

        //getter
        const Point& getPoint() const;
        const QPixmap &getImage() const;
        virtual int getType() const = 0;	// Methode virtuelle pure
        //setter
        void setPoint(Point p);
        void setImage(QPixmap *image);

        void deplacerDe(int dX, int dY);

};

#endif // OBJETGRAPHIQUE_H
