#ifndef OBJETNULL_H
#define OBJETNULL_H

#include "objetmobile.h"

class ObjetNull: public ObjetMobile{
    public:
        ObjetNull();
        virtual int getType() const;
};

#endif // OBJETNULL_H
