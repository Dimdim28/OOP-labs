#include "framework.h"
#include "rect_shape.h"

HBRUSH hBrush, hBrushOld;

void RectShape::Show(HDC hdc) {
	hBrush = (HBRUSH)CreateSolidBrush(RGB(192, 192, 192)); //створюється пензль
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush); //пензль -> у hdc

	long xStart = xs2 - (2 * (xs2 - xs1)); 	 //до правого верхнього кута
	long yStart = ys2 - (2 * (ys2 - ys1));

	Rectangle(hdc, xStart, yStart, xs2, ys2);

	SelectObject(hdc, hBrushOld); //відновлюється пензль-попередник
	DeleteObject(hBrush);

}