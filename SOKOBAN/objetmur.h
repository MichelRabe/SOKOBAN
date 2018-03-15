#ifndef OBJETMUR_H
#define OBJETMUR_H


#include "objetimmobile.h"

class ObjetMur: public ObjetImmobile{

    public:
        ObjetMur(Point p = Point(0,0), QPixmap *image = 0);
        virtual int getType() const;
};

#endif // OBJETMUR_H
