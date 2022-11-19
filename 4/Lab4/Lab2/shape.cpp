#include "shape.h"

Shape::~Shape() { }


void Shape::SetStart(long xStart, long yStart)
{
	xs1 = xStart;
	ys1 = yStart;
}

void Shape::SetEnd(long xEnd, long yEnd)
{
	xs2 = xEnd;
	ys2 = yEnd;
}



