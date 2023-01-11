#pragma once
#include "Shape.h"
#include "Movable.h"
#include "Point.h"

class Square : public Shape, public Movable
{
public:
	Square(int x, int y, int edge);
	virtual void calculateArea();
	virtual void calculatePerimeter();
	virtual std::vector<Point> calculatePoints();
	virtual std::string toString();
	virtual void scale(float scalex, float scaley);
private:
	int x = 0;
	int y = 0.;
	int edge = 0;
	float area = 0.0f;
	float perimeter = 0.0f;
	Point rightTop;
	Point rightBottom;
	Point leftBottom;
};

