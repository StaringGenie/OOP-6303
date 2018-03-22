#ifndef TRAPEZE_H
#define TRAPEZE_H
#include "Shape.h"
#include <utility>

using namespace std;

class Trapeze : public Shape {
public:
    Trapeze(Point a, Point b, Point c, Point d);
	virtual ~Trapeze();

	void move(Point newP) override;
	void turn(double angle) override;
	void scale(double factor) override;
	void setColor(std::string color) override;
	string getColor() override;
     int getId() override;
	friend ostream& operator<<(ostream& os, const Trapeze& rect);

private:
	Point positionCentre();

private:
    Point _a;
    Point _b;
    Point _c;
    Point _d;
    string _color;
    int _id;
};

#endif /* TRAPEZE_H */
