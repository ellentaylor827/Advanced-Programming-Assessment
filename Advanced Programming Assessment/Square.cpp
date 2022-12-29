#include "Square.h"

Square::Square() {

}

float Shape::calculateArea(float edge) {

	float area = edge * edge;
}

float Shape::calculatePerimeter(float edge) {

	float perimeter = edge * 4;

}

std::vector<int> Shape::calculatePoints(int x, int y, float edge) {
	std::vector<int> points;

	int leftTop = (x, y);
	int rightTop = (x + edge, y);
	int rightBottom = (x + edge, y + edge);
	int leftBottom = (x, y + edge);

	//push points to vectore here

	return points;
}