
#define _USE_MATH_DEFINES
#include "Trapeze.h"
#include <cmath>
#include <iostream>
#include "exc.h"
#include <algorithm>

Trapeze::Trapeze(Point a, Point b, Point c, Point d) : _a(a), _b(b), _c(c), _d(d) {

   if (abs((_a.x - _b.x)/(_a.y - _b.y)) == abs((_c.x - _d.x)/(_c.y - _d.y))) {

            } else
            if (abs((_b.x - _c.x)/(_b.y - _c.y)) == abs((_a.x - _d.x)/(_a.y - _d.y))) {

            } else throw BadFigureException("Trapeze");
   _id=Shape::id++;


}


Trapeze::~Trapeze() {
}


int Trapeze::getId() {
    return _id;
}


Point Trapeze::positionCentre() {
    Point centre;

     if (abs((_a.x - _b.x)/(_a.y - _b.y)) == abs((_c.x - _d.x)/(_c.y - _d.y))) {

         double bigBase;
         double smallBase;
         Point bigBaseCentre; Point smallBaseCentre;


         if (sqrt(powf(_a.x - _b.x, 2) + powf(_a.y - _b.y, 2)) > sqrt(powf(_c.x - _d.x, 2) + powf(_c.y - _d.y, 2))) {
             bigBase   = sqrt(powf(_a.x - _b.x, 2) + powf(_a.y - _b.y, 2));
             smallBase = sqrt(powf(_c.x - _d.x, 2) + powf(_c.y - _d.y, 2));


             bigBaseCentre.x = (_a.x + _b.x) / 2;
             bigBaseCentre.y = (_a.y + _b.y) / 2;
             smallBaseCentre.x = (_c.x + _d.x) / 2;
             smallBaseCentre.y = (_c.y + _d.y) / 2;
         } else {
             smallBase   = sqrt(powf(_a.x - _b.x, 2) + powf(_a.y - _b.y, 2));
             bigBase = sqrt(powf(_c.x - _d.x, 2) + powf(_c.y - _d.y, 2));


             smallBaseCentre.x = (_a.x + _b.x) / 2;
             smallBaseCentre.y = (_a.y + _b.y) / 2;
             bigBaseCentre.x = (_c.x + _d.x) / 2;
             bigBaseCentre.y = (_c.y + _d.y) / 2;
         }


         double height = getHeight();

         double dist = (height/3) * ((2 * bigBase + smallBase) / (bigBase + smallBase));

         double med = sqrt(powf(((_c.y + _d.y)/2) - ((_a.y + _b.y)/2), 2) + powf(((_c.y + _d.y)/2) - ((_a.y + _b.y)/2), 2));

         if (smallBaseCentre.x < bigBaseCentre.x) {
             double diff = dist / med;
             centre.x = smallBaseCentre.x + (bigBaseCentre.x - smallBaseCentre.x) * diff;
         } else {
             double diff = (med - dist) / med;
             centre.x = bigBaseCentre.x + (smallBaseCentre.x - bigBaseCentre.x) * diff;
         }

         if (smallBaseCentre.y > bigBaseCentre.y) {
             double diff = dist / med;
             centre.y = bigBaseCentre.y + (smallBaseCentre.y - bigBaseCentre.y) * diff;

         } else {
             double diff = (med - dist) / med;
             centre.y = bigBaseCentre.y - (bigBaseCentre.y - smallBaseCentre.y) * diff;
         }


         return centre;
     }

     if (abs((_b.x - _c.x)/(_a.y - _d.y)) == abs((_b.x - _c.x)/(_a.y - _d.y))){

         double bigBase;
         double smallBase;
         Point bigBaseCentre; Point smallBaseCentre;


         if (sqrt(powf(_b.x - _c.x, 2) + powf(_b.y - _c.y, 2)) > sqrt(powf(_a.x - _d.x, 2) + powf(_a.y - _d.y, 2))) {
             bigBase   = sqrt(powf(_b.x - _c.x, 2) + powf(_b.y - _c.y, 2));
             smallBase = sqrt(powf(_a.x - _d.x, 2) + powf(_a.y - _d.y, 2));


             bigBaseCentre.x = (_b.x + _c.x) / 2;
             bigBaseCentre.y = (_b.y + _c.y) / 2;
             smallBaseCentre.x = (_a.x + _d.x) / 2;
             smallBaseCentre.y = (_a.y + _d.y) / 2;
         } else {
             smallBase   = sqrt(powf(_b.x - _c.x, 2) + powf(_b.y - _c.y, 2));
             bigBase = sqrt(powf(_a.x - _d.x, 2) + powf(_a.y - _d.y, 2));


             smallBaseCentre.x = (_b.x + _c.x) / 2;
             smallBaseCentre.y = (_b.y + _c.y) / 2;
             bigBaseCentre.x = (_a.x + _d.x) / 2;
             bigBaseCentre.y = (_a.y + _d.y) / 2;
         }


         double height = getHeight();

         double dist = (height/3) * ((2 * bigBase + smallBase) / (bigBase + smallBase));

         double med = sqrt(powf(((_a.y + _d.y)/2) - ((_b.y + _c.y)/2), 2) + powf(((_a.y + _d.y)/2) - ((_b.y + _c.y)/2), 2));

         if (smallBaseCentre.x < bigBaseCentre.x) {
             double diff = dist / med;
             centre.x = smallBaseCentre.x + (bigBaseCentre.x - smallBaseCentre.x) * diff;
         } else {
             double diff = (med - dist) / med;
             centre.x = bigBaseCentre.x + (smallBaseCentre.x - bigBaseCentre.x) * diff;
         }

         if (smallBaseCentre.y > bigBaseCentre.y) {
             double diff = dist / med;
             centre.y = bigBaseCentre.y + (smallBaseCentre.y - bigBaseCentre.y) * diff;

         } else {
             double diff = (med - dist) / med;
             centre.y = bigBaseCentre.y - (bigBaseCentre.y - smallBaseCentre.y) * diff;
         }


         return centre;
     }
}


double Trapeze::getHeight(){
    if (abs((_a.x - _b.x)/(_a.y - _b.y)) == abs((_c.x - _d.x)/(_c.y - _d.y))) {


        Point inter;

        double A1 = _a.y - _b.y;
        double B1 = _b.x - _a.x;
        double C1 = _a.x*_b.y - _b.x*_a.y;

        double A2 = _c.y - _d.y;
        double B2 = _d.x - _c.x;
        double C2 = _c.x*_d.y - _d.x*_c.y;


        double delta    = A2                    *  A1       -       B2       *  (-1)*B1;
        double delta_x = (-1)*C2                *  A1       -       B2       *  (A1*_a.y - B1*_a.x);
        double delta_y = (A1*_a.y - B1*_a.x)    *  A2       -       (-1)*C2  *  (-1)*B1;


        inter.x = delta_x / delta;
        inter.y = delta_y / delta;

        return sqrt(powf(_a.x - inter.x, 2) + powf(_a.y - inter.y, 2));


    } else if (abs((_b.x - _c.x)/(_b.y - _c.y)) == abs((_a.x - _d.x)/(_a.y - _d.y))) {
        Point inter;

        double A1 = _b.y - _c.y;
        double B1 = _c.x - _b.x;
        double C1 = _b.x*_c.y - _c.x*_b.y;

        double A2 = _a.y - _d.y;
        double B2 = _d.x - _a.x;
        double C2 = _a.x*_d.y - _d.x*_a.y;


        double delta    = A2  *  A1                   -   B2      *  (-1)*B1;
        double delta_x = (-1)*C2  *  A1              -   B2  *  (A1*_b.y - B1*_b.x);
        double delta_y = A2  *  (A1*_b.y - B1*_b.x)  -  (-1)*C2  *  (-1)*B1;


        inter.x = delta_x / delta;
        inter.y = delta_y / delta;

        return sqrt(powf(_b.x - inter.x, 2) + powf(_b.y - inter.y, 2));

    }

}

void Trapeze::move(const Point newP) {
    Point centre = positionCentre();

    double movedX = newP.x - centre.x;
    double movedY = newP.y - centre.y;
    _a.x += movedX; _a.y += movedY;
    _b.x += movedX; _b.y += movedY;
    _c.x += movedX; _c.y += movedY;
    _d.x += movedX; _d.y += movedY;
}

void Trapeze::turn(double angle){
    Point centre = positionCentre();

    angle =  fmod(angle, 360);
    angle *= M_PI/180;

    Point tmp;

    tmp.x = centre.x + (_a.x - centre.x)*cos(angle) - (_a.y - centre.y)*sin(angle);
    tmp.y = centre.y + (_a.x - centre.x)*sin(angle) + (_a.y - centre.y)*cos(angle);
    _a.x = tmp.x;
    _a.y = tmp.y;


    tmp.x = centre.x + (_b.x - centre.x)*cos(angle) - (_b.y - centre.y)*sin(angle);
    tmp.y = centre.y + (_b.x - centre.x)*sin(angle) + (_b.y - centre.y)*cos(angle);
    _b.x = tmp.x;
    _b.y = tmp.y;


    tmp.x = centre.x + (_c.x - centre.x)*cos(angle) - (_c.y - centre.y)*sin(angle);
    tmp.y = centre.y + (_c.x - centre.x)*sin(angle) + (_c.y - centre.y)*cos(angle);
    _c.x = tmp.x;
    _c.y = tmp.y;


    tmp.x = centre.x + (_d.x - centre.x)*cos(angle) - (_d.y - centre.y)*sin(angle);
    tmp.y = centre.y + (_d.x - centre.x)*sin(angle) + (_d.y - centre.y)*cos(angle);
    _d.x = tmp.x;
    _d.y = tmp.y;
}


void Trapeze::scale(double factor){
    Point centre = positionCentre();

    vector <double> xArray = {_a.x, _b.x, _c.x, _d.x};
    vector <double> yArray = {_a.y, _b.y, _c.y, _d.y};

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

}


void Trapeze::setColor(std::string color) {
	_color = color;
}


string Trapeze::getColor() {
	return _color;
}


ostream& operator<<(ostream& os, const Trapeze& trap) {
    os << '(' << trap._a.x << ':' << trap._a.y << ')' << endl << '(' << trap._b.x << ':' << trap._b.y << ')' << endl << '(' << trap._c.x << ':' << trap._c.y << ')' << endl << '(' << trap._d.x << ':' << trap._d.y << ')' << endl;

	return os;

}
