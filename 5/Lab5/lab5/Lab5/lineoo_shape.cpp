#include "lineoo_shape.h"

LineOOShape::LineOOShape() {}

Shape* LineOOShape::copyShape()
{
	return new LineOOShape;
}

std::wstring LineOOShape::getName()
{
	return L"Гантеля";
}

void LineOOShape::Draw(HDC hdc)
{
	long x1 = xstart, y1 = ystart, x2 = xend, y2 = yend;

	LineShape::Draw(hdc);

	Set(x1, y1, x1 + 10, y1 + 10);
	EllipseShape::Draw(hdc);

	Set(x2, y2, x2 + 10, y2 + 10);
	EllipseShape::Draw(hdc);

	Set(x1, y1, x2, y2);
}

void LineOOShape::Gum(HDC hdc)
{
	Draw(hdc);
}