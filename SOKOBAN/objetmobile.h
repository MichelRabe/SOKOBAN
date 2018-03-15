#ifndef OBJETMOBILE_H
#define OBJETMOBILE_H


#include "objetgraphique.h"


class ObjetMobile : public ObjetGraphique{

    public:
        ObjetMobile(Point p = Point(0,0), QPixmap *image = 0);
        virtual ~ObjetMobile();
};
#endif // OBJETMOBILE_H
