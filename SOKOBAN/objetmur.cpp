#include "objetmur.h"


ObjetMur::ObjetMur(Point p, QPixmap *image): ObjetImmobile(p,image){

}

int ObjetMur::getType() const{
    return Mur;
}
