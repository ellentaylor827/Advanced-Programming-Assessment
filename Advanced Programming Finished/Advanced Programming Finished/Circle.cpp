#include "Circle.h"
#include "Movable.h"

Circle::Circle(int xinput, int yinput, int r) : Shape{ Point(x, y) } {
	radius = r;
	leftTop.setx(xinput);
	leftTop.sety(yinput);
}

void Circle::calculateArea() {

	area = pi * (radius * radius);

}

void Circle::calculatePerimeter() {

	perimeter = 2 * pi * radius;

}

std::vector<Point> Circle::calculatePoints() {

	std::vector<Point> points; //holds all Point objects
	
	rightBottom = Point(leftTop.getx() + 2 * radius, leftTop.gety() + 2 * radius);

	points.push_back(leftTop);
	points.push_back(rightBottom);

	return points;
}

//prints out all the shape information
std::string Circle::toString() {

	calculateArea();
	calculatePerimeter();
	points = calculatePoints();

	std::string finalString;
	std::stringstream stream;
	std::string pointsString;

	//uses a string stream to create a string of all the points
	for (int i = 0; i < points.size(); i++) {
		std::stringstream tempStream;
		tempStream << std::fixed << std::setprecision(1) << "(" << points[i].getx() << "," << points[i].gety() << ")";
		pointsString.append(tempStream.str());
	}

	//prints out all shape info
	stream << std::fixed << std::setprecision(1) << "Circle[Radius = " << radius<< "]"
		<< "\nPoints[" << pointsString << "]" << "\nArea = " << area << "\nPerimeter = " << perimeter;
	finalString.append(stream.str());
	return finalString;

}

void Circle::scale(float scalex, float scaley) {
	//takes the biggest number and scales the shape using it
	if (scalex >= scaley) {
		radius = radius * scalex;
	}
	else {
		radius = radius * scaley;
	}

}