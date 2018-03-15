#ifndef OBJETIMMOBILE_H
#define OBJETIMMOBILE_H

#include "objetgraphique.h"


// Classe abstraite par heritage de la methode virtuelle pure non redefinie
class ObjetImmobile : public ObjetGraphique{
public:
    ObjetImmobile(Point p = Point(0,0), QPixmap *image = 0);
    virtual ~ObjetImmobile();
};

#endif // OBJETIMMOBILE_H
