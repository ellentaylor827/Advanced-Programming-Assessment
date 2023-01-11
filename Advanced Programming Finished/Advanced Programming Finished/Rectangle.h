#pragma once
#include "Shape.h"
#include "Movable.h"
#include "Point.h"
class Rectangle : public Shape, public Movable
{
public:
	Rectangle(int x, int y, int height, int width);
	virtual void calculateArea();
	virtual void calculatePerimeter();
	virtual std::vector<Point> calculatePoints();
	virtual std::string toString();
	virtual void scale(float scalex, float scaley);
private:
	int x = 0;
	int y = 0;
	int height = 0;
	int width = 0;
	float area = 0.0f;
	float perimeter = 0.0f;
	Point leftBottom;
	Point rightTop;
	Point rightBottom;
};
