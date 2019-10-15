#include <iostream>
#include <string>
#include "Person.h"
#include <string.h>

int Person::GetSSN()
{
    return this->ssn;
}

void Person::ShowPerInfo()
{
    std::cout << "ssn : " << this->GetSSN() << std::endl;
    std::cout << "name : " << this->name << std::endl;
    std::cout << "addr : " << this->addr << std::endl;
}

Person * Person::MakePersonData(int ssn, std::string name, std::string addr)
{
    Person * newP = new Person();
    newP->ssn = ssn;
    // strcpy(newP->name, name);
    // strcpy(newP->addr, addr);
    newP->name = name;
    newP->addr = addr;
    return newP;
}
