
#define _USE_MATH_DEFINES

#include "Triangle.h"
#include <cmath>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "exc.h"
#include <algorithm>



using namespace std;




Triangle::Triangle(Point a, Point b, Point c) : _a(a), _b(b), _c(c) {


    if((c.y-a.y)/(b.y-a.y)==(c.x-a.x)/(b.x-a.x)){
        throw BadFigureException("Triangle");
    }

    _id=Shape::id++;


}

Triangle::~Triangle() {
}


int Triangle::getId() {
    return _id;
}

Point Triangle::positionCentre() {
    double xc = (_a.x+_b.x+_c.x) / 3;
    double yc = (_a.y+_b.y+_c.y) / 3;
	Point centre;
	centre.x = xc;
	centre.y = yc;
	return centre;
}

void Triangle::move(Point newP) {

	Point centre = positionCentre();

	double movedX = newP.x - centre.x;
	double movedY = newP.y - centre.y;
    _a.x += movedX; _a.y += movedY;
    _b.x += movedX; _b.y += movedY;
    _c.x += movedX; _c.y += movedY;
}


void Triangle::turn(double angle) {
	angle *= M_PI / 180;

	Point tmp;

    tmp.x = _a.x*cos(angle) - _a.y*sin(angle);
    tmp.y = _a.x*sin(angle) + _a.y*cos(angle);
    _a.x = round(tmp.x*1000)/1000;
    _a.y = round(tmp.y*1000)/1000;


    tmp.x = _b.x*cos(angle) - _b.y*sin(angle);
    tmp.y = _b.x*sin(angle) + _b.y*cos(angle);
    _b.x = round(tmp.x*1000)/1000;
    _b.y = round(tmp.y*1000)/1000;


    tmp.x = _c.x*cos(angle) - _c.y*sin(angle);
    tmp.y = _c.x*sin(angle) + _c.y*cos(angle);
    _c.x = round(tmp.x*1000)/1000;
    _c.y = round(tmp.y*1000)/1000;



}


void Triangle::scale(double factor) {
    Point centre = positionCentre();

    vector <double> xArray = {_a.x, _b.x, _c.x};
    vector <double> yArray = {_a.y, _b.y, _c.y};

    for (int i = 0; i < xArray.capacity() ; i++) {
        if (xArray[i] > centre.x) {

            xArray[i] = centre.x + (xArray[i] - centre.x) * factor;

        } else {

            xArray[i] = centre.x - (centre.x - xArray[i]) * factor;
        }
    }

    for (int i = 0; i < yArray.capacity() ; i++) {
        if (yArray[i] > centre.y) {
            yArray[i] = centre.y + (yArray[i] - centre.y) * factor;
        } else {
            yArray[i] = centre.y - (centre.y - yArray[i]) * factor;
        }
    }


    _a.x = xArray[0]; _a.y = yArray[0];
    _b.x = xArray[1]; _b.y = yArray[1];
    _c.x = xArray[2]; _c.y = yArray[2];

}

void Triangle::setColor(std::string color) {
	_color = color;
}

string Triangle::getColor() {
	return _color;
}

ostream& operator<<(ostream& os, const Triangle& rect) {
    os << '(' << rect._a.x << ':' << rect._a.y << ')' << endl << '(' << rect._b.x << ':' << rect._b.y << ')' << endl << '(' << rect._c.x << ':' << rect._c.y << ')' << endl;

	return os;

}
