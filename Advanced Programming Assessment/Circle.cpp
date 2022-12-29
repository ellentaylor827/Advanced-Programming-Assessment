#include "Circle.h"

Circle::Circle() {

}

float Shape::calculateArea(float radius) {

	float area = 3.14159 * (radius*radius);
}

float Shape::calculatePerimeter(float radius) {

	float perimeter = 2 * 3.14159 * radius;

}

std::vector<int> Shape::calculatePoints(int x, int y, float radius) {

	std::vector<int> points;

	int leftTop = (x, y);
	int rightBottom = (x + 2*radius, y + 2*radius);

	points.push_back(leftTop);
	points.push_back(rightBottom);

	return points;
}