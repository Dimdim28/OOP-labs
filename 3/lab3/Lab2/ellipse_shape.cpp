#include "framework.h"
#include "ellipse_shape.h"

void EllipseShape::Show(HDC hdc) {

	long xStart = xs2 - 2 * (xs2 - xs1);  //до будь-якого кута
	long yStart = ys2 - 2 * (ys2 - ys1);


	HBRUSH hBrush, hBrushOld;
	hBrush = (HBRUSH)CreateSolidBrush(RGB(192, 192, 192));
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	Ellipse(hdc, xStart, yStart, xs2, ys2);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}

