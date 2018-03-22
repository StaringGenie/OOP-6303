#ifndef EXC_H
#define EXC_H

class ex{

public:
    virtual void print()=0;
};

class badTriangleException: public ex{
public:
    void print() override;
};

class badTrapezeException:public ex{
public:
    void print() override;
};

class badPentagonException:public ex
{
public:
    void print() override;
};



#endif // EXC_H
