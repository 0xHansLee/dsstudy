#include <iostream>
#include "Person.h"
#include "Table2.h"

int MyHashFunc(int k)
{
    return k % 100;
}

int main(void)
{
    Table myTbl;
    Person * np;
    Person * sp;
    Person * rp;

    myTbl.Init(MyHashFunc);

    np = np->MakePersonData(900254, "Lee", "Seoul");
    myTbl.Insert(np->GetSSN(), np);

    np = np->MakePersonData(900154, "Kim", "Jeju");
    myTbl.Insert(np->GetSSN(), np);

    np = np->MakePersonData(900827, "Han", "Kangwon");
    myTbl.Insert(np->GetSSN(), np);

    sp = myTbl.Search(900254);
    if(sp != NULL)
        sp->ShowPerInfo();

    sp = myTbl.Search(900154);
    if(sp != NULL)
        sp->ShowPerInfo();

    sp = myTbl.Search(900827);
    if(sp != NULL)
        sp->ShowPerInfo();

    rp = myTbl.Delete(900254);
    if(rp != NULL)
        delete rp;

    rp = myTbl.Delete(900154);
    if(rp != NULL)
        delete rp;

    rp = myTbl.Delete(900827);
    if(rp != NULL)
        delete rp;

    return 0;
}