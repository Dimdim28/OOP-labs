#include "framework.h"
#include "shape.h"

HBRUSH hBrush, hBrushOld;

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

void PointShape::Show(HDC hdc) {
	SetPixel(hdc, xs2, ys2, 0x00000000);
					
	SetPixel(hdc, xs2 - 2, ys2, 0x00000000);
	SetPixel(hdc, xs2 - 1, ys2, 0x00000000);
	SetPixel(hdc, xs2 + 1, ys2, 0x00000000);
	SetPixel(hdc, xs2 + 2, ys2, 0x00000000);
					
	SetPixel(hdc, xs2, ys2 - 2, 0x00000000);
	SetPixel(hdc, xs2, ys2 - 1, 0x00000000);
	SetPixel(hdc, xs2, ys2 + 1, 0x00000000);
	SetPixel(hdc, xs2, ys2 + 2, 0x00000000);
					
	SetPixel(hdc, xs2 - 1, ys2 - 1, 0x00000000);
	SetPixel(hdc, xs2 + 1, ys2 - 1, 0x00000000);
	SetPixel(hdc, xs2 - 1, ys2 + 1, 0x00000000);
	SetPixel(hdc, xs2 + 1, ys2 + 1, 0x00000000);
}

void LineShape::Show(HDC hdc) {
	MoveToEx(hdc, xs1, ys1, NULL);
	LineTo(hdc, xs2, ys2);
}

void RectShape::Show(HDC hdc) {
	hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 128, 0)); //створюється пензль
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush); //пензль -> у hdc

	Rectangle(hdc, xs1, ys1, xs2, ys2);

	SelectObject(hdc, hBrushOld); //відновлюється пензль-попередник
	DeleteObject(hBrush);

}

void EllipseShape::Show(HDC hdc) {
	Ellipse(hdc, xs1, ys1, xs2, ys2);
}