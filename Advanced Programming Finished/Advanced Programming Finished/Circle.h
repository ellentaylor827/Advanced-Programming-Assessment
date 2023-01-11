#pragma once
#include "Shape.h"
#include "Movable.h"
#include "Point.h"
class Circle : public Shape, public Movable
{
public:
	Circle(int x, int y, int radius);
	virtual void calculateArea();
	virtual void calculatePerimeter();
	virtual std::vector<Point> calculatePoints();
	virtual std::string toString();
	virtual void scale(float scalex, float scaley);
private:
	int x = 0;
	int y = 0;
	int radius = 0;
	float pi = 3.14159f;
	float area = 0.0f;
	float perimeter = 0.0f;
	Point rightBottom;
};

