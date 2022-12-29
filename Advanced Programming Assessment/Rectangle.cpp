#include "Rectangle.h"

Rectangle::Rectangle() {

}

float Shape::calculateArea(float height, float width) {

	float area = height * width;
}

float Shape::calculatePerimeter(float height, float width) {

	float perimeter = (height * 2) + (width * 2);

}

std::vector<int> Shape::calculatePoints(int x, int y, float height, float width) {

	std::vector<int> points;

	int leftTop = (x, y);
	int rightTop = (x + width, y);
	int rightBottom = (x + width, y + height);
	int leftBottom = (x, y + height);

	//push back coordinates here

	return points;
}