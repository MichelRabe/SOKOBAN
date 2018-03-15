#ifndef OBJETVIDE_H
#define OBJETVIDE_H


#include "objetimmobile.h"

// Classe pas abstraite car methode virtuelle redefinie
class ObjetVide: public ObjetImmobile{

    public:
        ObjetVide(Point p = Point(0,0), QPixmap *image = 0);
        virtual int getType() const;
};

#endif // OBJETVIDE_H
