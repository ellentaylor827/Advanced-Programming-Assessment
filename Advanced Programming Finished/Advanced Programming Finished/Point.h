#pragma once
#include <string>
class Point
{
private:
	float x = 0.0f;
	float y = 0.0f;

public:
	Point();
	Point(float xValue, float yValue);
	float getx();
	float gety();
	void setx(float xValue);
	void sety(float yValue);
	std::string toString();
};

