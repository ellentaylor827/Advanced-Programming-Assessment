#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip> 
#include "Point.h"

class Shape
{
public:
	int x;
	int y;
	int height;
	int width;
	Shape(Point pointValue);
	Point leftTop; //location of the left top coordinate of the shape

	bool isCircular = false; //checks if a shape is circular
	float area;
	float perimeter;
	std::vector<Point> points;//stores all shape points

	virtual void calculateArea() = 0;
	virtual void calculatePerimeter() = 0;
	virtual std::vector<Point> calculatePoints() = 0;
	virtual std::string toString() = 0;

	//operator overloading which runs toString() when a shape object is outputted
	friend std::ostream& operator<<(std::ostream& out, Shape* shape)
	{
		std::string printAll = shape->toString();
		out << printAll << std::endl;
		return out;
	}
};

