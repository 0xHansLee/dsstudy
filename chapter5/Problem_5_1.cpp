#include <iostream>
// #include <string> -> can use c++ standard string 
#include "CLinkedList.cpp"

 
int main(void)
{
    CList list;
    Employee employee;
    
    list.Init();

    employee.SetEmployee(111,"A");
    list.Insert(employee);

    employee.SetEmployee(222,"B");
    list.Insert(employee);

    employee.SetEmployee(333,"C");
    list.Insert(employee);

    employee.SetEmployee(444,"D");
    list.Insert(employee);

    list.SearchDuty("A",8);
}