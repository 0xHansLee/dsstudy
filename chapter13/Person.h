#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>

// #define STR_LEN     50

class Person 
{
    public:
        int ssn;
        char * name;
        char * addr;

        int GetSSN();
        void ShowPerInfo();
        Person * MakePersonData(int ssn, char * name, char * addr);
};

#endif