#include "ellipse_shape.h"

EllipseShape::EllipseShape() {}

Shape* EllipseShape::copyShape()
{
	return new EllipseShape;
}

std::wstring EllipseShape::getName()
{
	return L"Ελ³ορ";
}

void EllipseShape::Draw(HDC hdc)
{
	Ellipse(hdc, xstart * 2 - xend, ystart * 2 - yend, xend, yend);
}

void EllipseShape::Gum(HDC hdc)
{
	Draw(hdc);
}