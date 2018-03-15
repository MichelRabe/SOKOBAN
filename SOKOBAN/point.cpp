#include "point.h"


Point::Point(int abscisse, int ordonnee){
    m_abscisse = abscisse;
    m_ordonnee = ordonnee;
}

Point::~Point(){}

int Point::getX() const{
    return m_abscisse;
}
int Point::getY() const{
    return m_ordonnee;
}
void Point::setX(int nX){
    m_abscisse = nX;
}
void Point::setY(int nY){
    m_ordonnee = nY;
}

void Point::deplacerDe(int dX, int dY){
    m_abscisse += dX;
    m_ordonnee += dY;
}
