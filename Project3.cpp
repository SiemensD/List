#include "printer.h"
#include <iostream>
#include<string.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    printer first;
    first.add("Николай", 4);
    first.add("Антон", 3);
    first.add("Сергей", 2);
    first.getqueue();
    

    return 0;
}