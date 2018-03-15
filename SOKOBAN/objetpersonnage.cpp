#include "objetpersonnage.h"


ObjetPersonnage::ObjetPersonnage(Point p, QPixmap *image): ObjetMobile(p, image){

}

int ObjetPersonnage::getType() const{
    return Personnage;
}
