#ifndef EXC_H
#define EXC_H

#include <string>

class BadFigureException{


private:
    std::string figureName;

public:
    BadFigureException(std::string name){
        figureName=name;
    }
    void print();
};


#endif // EXC_H
