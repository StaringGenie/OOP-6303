#ifndef SHAPE_H
#define SHAPE_H

#include <string>

using namespace std;

struct Point {
	double x;
	double y;
	Point() : x(0.0), y(0.0) {}
    Point(double x_, double y_): x(x_), y(y_) {}
};

class Shape {
public:
	virtual void move(Point newP) = 0;
	virtual void turn(double angle) = 0;
	virtual void scale(double factor) = 0;
	virtual void setColor(string color) = 0;
	virtual string getColor() = 0;
    virtual  int getId() = 0;
protected:
        static int id;

};

#endif /* SHAPE_H */
