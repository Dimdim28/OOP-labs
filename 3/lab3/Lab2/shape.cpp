#include "framework.h"
#include "shape.h"

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

long Shape::getXStart()
{
	return xs1;
}

long Shape::getXEnd()
{
	return xs2;
}

long Shape::getYStart()
{
	return ys1;
}

long Shape::getYEnd()
{
	return ys2;
}


