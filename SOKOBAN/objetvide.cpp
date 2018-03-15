#include "objetvide.h"



ObjetVide::ObjetVide(Point p, QPixmap *image): ObjetImmobile(p, image){

}

int ObjetVide::getType() const{
    return Vide;
}
