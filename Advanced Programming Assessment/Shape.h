#pragma once
#include <iostream>;
#include <vector>;
class Shape
{
public:
	Shape();

	float area;
	bool isCircular = false; //checks if a shape is circular
	float leftTop; //keeps top left coordinate
	float perimeter;
	std::vector<float> points;//stores all shape points

	virtual float calculateArea(float height, float width);
	virtual float calculateArea(float width);

	virtual float calculatePerimeter(float height, float width);
	virtual float calculatePerimeter(float width);

	virtual std::vector<int> calculatePoints(int x, int y, float height, float width);
	virtual std::vector<int> calculatePoints(int x, int y, float width);

	std::string toString();
};

