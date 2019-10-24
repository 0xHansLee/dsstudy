#ifndef __SLOT2_H__
#define __SLOT2_H__

#include "Person.h"

typedef int Key;
typedef Person * Value;

class Slot
{
    public:
        Key key;
        Value val;
};

#endif