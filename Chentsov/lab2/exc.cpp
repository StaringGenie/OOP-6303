#include "exc.h"
#include <iostream>

using namespace std;

void BadFigureException::print(){
    cout<<"bad "+figureName+" exception"<<endl;
}
