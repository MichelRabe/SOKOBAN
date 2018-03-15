#ifndef OBJETOBJECTIF_H
#define OBJETOBJECTIF_H

#include "objetimmobile.h"

class ObjetObjectif: public ObjetImmobile{
    public:
        ObjetObjectif(Point p = Point(0,0), QPixmap *image = 0);
        virtual int getType() const;
};

#endif // OBJETOBJECTIF_H
