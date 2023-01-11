#include "Square.h"
#include <string>

Square::Square(int xinput, int yinput, int e) : Shape{ Point(x, y) } {
	leftTop.setx(xinput);
	leftTop.sety(yinput);
	edge = e;
}

void Square::calculateArea() {

	area = edge * edge;

}

void Square::calculatePerimeter() {

	perimeter = edge * 4;

}

std::vector<Point> Square::calculatePoints() {
	std::vector<Point> points;

	//calculates all points based on the location of leftTop
	rightTop = Point(leftTop.getx() + edge, leftTop.gety());
	rightBottom = Point(leftTop.getx() + edge, leftTop.gety() + edge);
	leftBottom = Point(leftTop.getx(), leftTop.gety() + edge);

	points.push_back(leftTop);
	points.push_back(rightTop);
	points.push_back(rightBottom);
	points.push_back(leftBottom);

	return points;

}
//prints out all the Shape information
std::string Square::toString() {

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
	stream << std::fixed << std::setprecision(1) << "Square[Edge = " << edge << "]"
		<< "\nPoints[" << pointsString << "]" << "\nArea = " << area << "\nPerimeter = " << perimeter;
	finalString.append(stream.str());
	return finalString;
}

void Square::scale(float scalex, float scaley) {
	//takes the biggest number and scales the shape using it
	if (scalex >= scaley){
		edge = edge * scalex;
	}
	else {
		edge = edge * scaley;
	}
}
