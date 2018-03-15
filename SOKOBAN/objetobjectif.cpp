#include "objetobjectif.h"


ObjetObjectif::ObjetObjectif(Point p, QPixmap *image): ObjetImmobile(p, image){

}

int ObjetObjectif::getType() const{
    return Objectif;
}
