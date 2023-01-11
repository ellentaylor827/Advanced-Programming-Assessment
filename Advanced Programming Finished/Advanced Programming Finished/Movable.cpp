#include "Movable.h"
#include <iostream>
#include <vector>

//takes in the current x and y positions and updates them with the new positions
std::vector<float> Movable::move(float newx, float newy) {

	float x = newx;
	float y = newy;

	std::vector<float> newCoords = { x, y };
	return newCoords;

}
