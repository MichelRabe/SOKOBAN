#ifndef POINT_H
#define POINT_H


class Point{
protected:
        int m_abscisse;
        int m_ordonnee;
    public:
        Point(int abscisse = 0, int ordonnee = 0);
        virtual ~Point();

        //getter
        int getX() const;
        int getY() const;
        //setter
        void setX(int nX);
        void setY(int nY);

        void deplacerDe(int dX, int dY);
};

#endif // POINT_H
