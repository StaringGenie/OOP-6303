#include "exc.h"
#include <iostream>

using namespace std;

void badTriangleException::print(){
    cout<<"bad triangle exception" <<endl;
}
void badTrapezeException::print(){
    cout<<"bad trapeze exception"<<endl;
}

void badPentagonException::print(){
    cout<<"bad pentagon exception"<<endl;
}
