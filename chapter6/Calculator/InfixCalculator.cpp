#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int EvalInfixExp(char exp[])
{
    int len = strlen(exp);
    int res;
    char * tmpChar = new char[len+1];
    strcpy(tmpChar, exp);
    ConvToRPNExp(tmpChar);
    res = CalculRPNExp(tmpChar);

    delete tmpChar;
    return res;
}