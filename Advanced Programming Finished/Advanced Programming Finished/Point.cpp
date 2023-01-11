#include "Point.h"
#include <string>
//Represents a location on a coordinate system
Point::Point() {

}

Point::Point(float xValue, float yValue) {
	x = xValue;
	y = yValue;
}

float Point::getx() {
	
	return x;
}

float Point::gety() {
	return y;
}

//sets a new x value
void Point::setx(float xValue) {
	x = xValue;
}

//sets a new y value
void Point::sety(float yValue) {
	y = yValue;
}



