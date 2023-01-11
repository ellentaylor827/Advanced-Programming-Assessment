#pragma once
#include <vector>
class Movable
{
public:
	int x;
	int y;
	std::vector<float> move(float newx, float newy);//shift a shape to new coordinates
	virtual void scale(float scalex, float scaley) = 0;//scales the shape in two dimensions
};

