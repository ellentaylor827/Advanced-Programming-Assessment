#include "Rectangle.h"
#include "Point.h"
#include <iomanip> 

Rectangle::Rectangle(int xinput, int yinput, int h, int w) : Shape{ Point(x, y) } {
	height = h;
	width = w;
	leftTop.setx(xinput);
	leftTop.sety(yinput);
}

void Rectangle::calculateArea() {

	area = height * width;

}

void Rectangle::calculatePerimeter() {

	perimeter = (height * 2) + (width * 2);

}

std::vector<Point> Rectangle::calculatePoints() {

	std::vector<Point> points;
	
	//calculates all the points based on the position of left top
	rightTop = Point(leftTop.getx() + width, leftTop.gety());
	rightBottom= Point(leftTop.getx() + width, leftTop.gety() + height);
	leftBottom = Point(leftTop.getx(), leftTop.gety() + height);

	points.push_back(leftTop);
	points.push_back(rightTop);
	points.push_back(rightBottom);
	points.push_back(leftBottom);

	return points;
}

//prints out all the Shape information
std::string Rectangle::toString() {

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
	stream << std::fixed << std::setprecision(1) << "Rectangle[Height = " << height << "][" << "Width = " << width << "]"
		<< "\nPoints[" << pointsString << "]" << "\nArea = " << area << "\nPerimeter = " << perimeter;
	finalString.append(stream.str());
	return finalString;

}

void Rectangle::scale(float scalex, float scaley) {
	//uses the scale amounts to calculate the new scaled height and width
	height = height * scalex;
	width = width * scaley;

}