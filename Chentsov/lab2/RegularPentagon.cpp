
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
        throw BadFigureException("Pentagon");
    }

       _id=Shape::id++;
}


RegularPentagon::~RegularPentagon() {
}


int RegularPentagon::getId() {
    return _id;
}

Point RegularPentagon::positionCentre(){

        Point centre;

        double A1 = ((_a.y + _b.y)/2) - _d.y;
        double B1 =  _d.x - ((_a.x + _b.x)/2);
        double C1 = ((_a.x + _b.x)/2)*_d.y - _d.x*((_a.y + _b.y)/2) ;

        double A2 = (_d.y + _e.y)/2 - _b.y;
        double B2 = _b.x - (_d.x + _e.x)/2 ;
        double C2 = ((_d.x + _e.x)/2)*_b.y - _b.x*((_d.y + _e.y)/2) ;

        double delta    = A1 * B2 - B1 * A2;
        double delta_x  = (-1)*C1 * B2 - B1 * (-1)*C2;
        double delta_y  = A1 * (-1)*C2 - (-1)*C1 * A2;

        centre.x = delta_x / delta;
        centre.y = delta_y / delta;



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


void RegularPentagon::turn(double angle){
    Point centre = positionCentre();

    angle =  fmod(angle, 360);
    angle *= M_PI/180;

    Point tmp;

    tmp.x = centre.x + (_a.x - centre.x)*cos(angle) - (_a.y - centre.y)*sin(angle);
    tmp.y = centre.y + (_a.x - centre.x)*sin(angle) + (_a.y - centre.y)*cos(angle);
    _a.x = round(tmp.x*10000)/10000;
    _a.y = round(tmp.y*10000)/10000;


    tmp.x = centre.x + (_b.x - centre.x)*cos(angle) - (_b.y - centre.y)*sin(angle);
    tmp.y = centre.y + (_b.x - centre.x)*sin(angle) + (_b.y - centre.y)*cos(angle);
    _b.x = round(tmp.x*10000)/10000;
    _b.y = round(tmp.y*10000)/10000;


    tmp.x = centre.x + (_c.x - centre.x)*cos(angle) - (_c.y - centre.y)*sin(angle);
    tmp.y = centre.y + (_c.x - centre.x)*sin(angle) + (_c.y - centre.y)*cos(angle);
    _c.x = round(tmp.x*10000)/10000;
    _c.y = round(tmp.y*10000)/10000;


    tmp.x = centre.x + (_d.x - centre.x)*cos(angle) - (_d.y - centre.y)*sin(angle);
    tmp.y = centre.y + (_d.x - centre.x)*sin(angle) + (_d.y - centre.y)*cos(angle);
    _d.x = round(tmp.x*10000)/10000;
    _d.y = round(tmp.y*10000)/10000;


    tmp.x = centre.x + (_e.x - centre.x)*cos(angle) - (_e.y - centre.y)*sin(angle);
    tmp.y = centre.y + (_e.x - centre.x)*sin(angle) + (_e.y - centre.y)*cos(angle);
    _e.x = round(tmp.x*10000)/10000;
    _e.y = round(tmp.y*10000)/10000;
}


void RegularPentagon::scale(double factor){
Point centre = positionCentre();

    vector <double> xArray = {_a.x, _b.x, _c.x, _d.x, _e.x};
    vector <double> yArray = {_a.y, _b.y, _c.y, _d.y, _e.y};

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
    _d.x = xArray[3]; _d.y = yArray[3];
    _e.x = xArray[4]; _e.y = yArray[4];
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
