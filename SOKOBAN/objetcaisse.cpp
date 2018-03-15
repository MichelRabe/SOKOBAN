#include "objetcaisse.h"


ObjetCaisse::ObjetCaisse(Point p, QPixmap *image): ObjetMobile(p, image){

}

int ObjetCaisse::getType() const{
    return Caisse;
}
