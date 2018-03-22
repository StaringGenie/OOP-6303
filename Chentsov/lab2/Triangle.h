#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <utility>
#include <iostream>

using namespace std;

class Triangle : public Shape {
public:
    Triangle(Point a, Point b, Point c);
    virtual ~Triangle();


	void move(Point newP) override;
	void turn(double angle) override;
	void scale(double factor) override;
	void setColor(std::string color) override;
     int getId() override;
	string getColor() override;
    friend ostream& operator<<(ostream& os, const Triangle& rect);


private:
	Point positionCentre();


private:
    Point _a;
    Point _b;
    Point _c;
	string _color;
    int _id;

};

#endif /* TRIANGLE_H */
