#ifndef OBJETPERSONNAGE_H
#define OBJETPERSONNAGE_H

#include "objetmobile.h"

class ObjetPersonnage: public ObjetMobile{
    public:
        ObjetPersonnage(Point p = Point(0,0), QPixmap *image = 0);
        virtual int getType() const;
};

#endif // OBJETPERSONNAGE_H
