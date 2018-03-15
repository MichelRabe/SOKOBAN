#ifndef OBJETCAISSE_H
#define OBJETCAISSE_H


#include "objetmobile.h"

class ObjetCaisse: public ObjetMobile{
    private:
        bool m_caissePlace;
    public:
        ObjetCaisse(Point p = Point(0,0), QPixmap *image = 0);
        virtual int getType() const;
};

#endif // OBJETCAISSE_H
