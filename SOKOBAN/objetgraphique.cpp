#include "objetgraphique.h"



ObjetGraphique::ObjetGraphique(Point p, QPixmap *image){
    m_point = p;
    m_image = image;
}

ObjetGraphique::~ObjetGraphique(){

}

const Point &ObjetGraphique::getPoint() const{
    return m_point;
}

const QPixmap &ObjetGraphique::getImage() const{
    return *m_image;
}

void ObjetGraphique::setPoint(Point p){
    m_point = p;
}

void ObjetGraphique::setImage(QPixmap *image){
    m_image = image;
}

void ObjetGraphique::deplacerDe(int dX, int dY){
    m_point.deplacerDe(dX, dY);
}
