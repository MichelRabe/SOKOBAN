#include "objetnull.h"

ObjetNull::ObjetNull(){
    m_point = Point(0,0);
    m_image = 0;
}

int ObjetNull::getType() const{
    return Vide;
}
