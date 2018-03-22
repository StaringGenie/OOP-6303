
#define _USE_MATH_DEFINES
#include "RegularPentagon.h"
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "exc.h"
using namespace std;


RegularPentagon::RegularPentagon(Point a, Point b, Point c, Point d, Point e) : _a(a), _b(b), _c(c), _d(d), _e(e) {

    double m1=round(sqrt(pow(((c.x+d.x)/2-a.x),2)+pow(((c.y+d.y)/2-a.y),2)) * 100)/100;
    double m2=round(sqrt(pow(((d.x+e.x)/2-b.x),2)+pow(((d.y+e.y)/2-b.y),2))*100) /100;
    double m3=round(sqrt(pow(((a.x+e.x)/2-c.x),2)+pow(((a.y+e.y)/2-c.y),2))*100)/100;
    double m4=round(sqrt(pow(((a.x+b.x)/2-d.x),2)+pow(((a.y+b.y)/2-d.y),2))*100)/100;
    double m5=round(sqrt(pow(((c.x+b.x)/2-e.x),2)+pow(((c.y+b.y)/2-e.y),2))*100)/100;

    if(!(m1==m2 && m1==m3 && m1==m4 && m1==m5)){
        throw badPentagonException();
    }

       _id=Shape::id++;
}


RegularPentagon::~RegularPentagon() {
}


int RegularPentagon::getId() {
    return _id;
}

Point RegularPentagon::positionCentre() {
	Point A; Point C;
	
    A.x = min((min(_a.x, _b.x), min(_c.x, _d.x)), _e.x);
    A.y = min((min(_a.y, _b.y), min(_c.y, _d.y)), _e.y);

    C.x = max((max(_a.x, _b.x), max(_c.x, _d.x)), _e.x);
    C.y = max((max(_a.y, _b.y), max(_c.y, _d.y)), _e.y);


	double xc = (C.x - A.x) / 2;
	double yc = (C.y - A.y) / 2;
	Point centre;
	centre.x = xc;
	centre.y = yc;
	return centre;
}


void RegularPentagon::move(Point newP) {
	Point centre = positionCentre();

	double movedX = newP.x;
	double movedY = newP.y;
    _a.x += movedX; _a.y += movedY;
    _b.x += movedX; _b.y += movedY;
    _c.x += movedX; _c.y += movedY;
    _d.x += movedX; _d.y += movedY;
}


void RegularPentagon::turn(double angle) {
	angle *= M_PI / 180;

	Point tmp;

    tmp.x = _a.x*cos(angle) - _a.y*sin(angle);
    tmp.y = _a.x*sin(angle) + _a.y*cos(angle);
    _a.x = tmp.x;
    _a.y = tmp.y;


    tmp.x = _b.x*cos(angle) - _b.y*sin(angle);
    tmp.y = _b.x*sin(angle) + _b.y*cos(angle);
    _b.x = tmp.x;
    _b.y = tmp.y;


    tmp.x = _c.x*cos(angle) - _c.y*sin(angle);
    tmp.y = _c.x*sin(angle) + _c.y*cos(angle);
    _c.x = tmp.x;
    _c.y = tmp.y;


    tmp.x = _d.x*cos(angle) - _d.y*sin(angle);
    tmp.y = _d.x*sin(angle) + _d.y*cos(angle);
    _d.x = tmp.x;
    _d.y = tmp.y;


    tmp.x = _e.x*cos(angle) - _e.y*sin(angle);
    tmp.y = _e.x*sin(angle) + _e.y*cos(angle);
    _e.x = tmp.x;
    _e.y = tmp.y;
}


void RegularPentagon::scale(double factor) {
    _a.x *= factor; _a.y *= factor;
    _b.x *= factor; _b.y *= factor;
    _c.x *= factor; _c.y *= factor;
    _d.x *= factor; _d.y *= factor;
    _e.x *= factor; _e.y *= factor;
}


void RegularPentagon::setColor(std::string color) {
	_color = color;
}


string RegularPentagon::getColor() {
	return _color;
}


ostream& operator<<(ostream& os, const RegularPentagon& pent) {
    os << '(' << pent._a.x << ':' << pent._a.y << ')' << endl << '(' << pent._b.x << ':' << pent._b.y << ')' << endl << '(' << pent._c.x << ':' << pent._c.y << ')' << endl << '(' << pent._d.x << ':' << pent._d.y << ')' << endl << '(' << pent._e.x << ':' << pent._e.y << ')' << endl;
	return os;

}
