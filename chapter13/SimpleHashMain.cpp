#include <iostream>
#include "Person.h"
#include "Table.h"

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

    myTbl.TBLInit(MyHashFunc);
    

    np = np->MakePersonData(20120003, "Lee", "Seoul");
    myTbl.TBLInsert(np->GetSSN(), np);

    np = np->MakePersonData(20120012, "Kim", "Jeju");
    myTbl.TBLInsert(np->GetSSN(), np);

    np = np->MakePersonData(20120049, "Han", "Kangwon");
    myTbl.TBLInsert(np->GetSSN(), np);

    sp = myTbl.TBLSearch(20120003);
    if(sp != NULL)
        sp->ShowPerInfo();

    sp = myTbl.TBLSearch(20120012);
    if(sp != NULL)
        sp->ShowPerInfo();

    sp = myTbl.TBLSearch(20120049);
    if(sp != NULL)
        sp->ShowPerInfo();

    rp = myTbl.TBLDelete(20120003);
    if(rp != NULL)
        free(rp);

    rp = myTbl.TBLDelete(20120012);
    if(rp != NULL)
        free(rp);

    rp = myTbl.TBLDelete(20120049);
    if(rp != NULL)
        free(rp);

    return 0;
}