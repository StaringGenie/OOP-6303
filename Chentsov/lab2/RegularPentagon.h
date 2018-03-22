#ifndef REGULARPENTAGON_H
#define REGULARPENTAGON_H

#include "Shape.h"
#include <utility>

using namespace std;

class RegularPentagon : public Shape {
public:
    RegularPentagon(Point a, Point b, Point c, Point d, Point e);
	virtual ~RegularPentagon();

	void move(Point newP) override;
	void turn(double angle) override;
	void scale(double factor) override;
	void setColor(std::string color) override;
	string getColor() override;
     int getId() override;
	friend ostream& operator<<(ostream& os, const RegularPentagon& pent);

private:
	Point positionCentre();


private:
    Point _a;
    Point _b;
    Point _c;
    Point _d;
    Point _e;
	string _color;
    int _id;
};

#endif /* REGULARPENTAGON_H */
