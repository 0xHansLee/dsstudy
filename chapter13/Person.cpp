#include <iostream>
#include <string>
#include "Person.h"

int Person::GetSSN()
{
    return this->ssn;
}

void Person::ShowPerInfo()
{
    std::cout << "주민등록번호 : " << this->GetSSN() << std::endl;
    std::cout << "이름 : " << this->name << std::endl;
    std::cout << "주소 : " << this->addr << std::endl;
}

Person * Person::MakePersonData(int ssn, std::string name, std::string addr)
{
    Person * newP = new Person;
    newP->ssn = ssn;
    newP->name = name;
    newP->addr = addr;
    return newP;
}
