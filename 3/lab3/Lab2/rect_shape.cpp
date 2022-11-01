#include "framework.h"
#include "rect_shape.h"

HBRUSH hBrush, hBrushOld;

void RectShape::Show(HDC hdc) {
	hBrush = (HBRUSH)CreateSolidBrush(RGB(192, 192, 192)); //створюється пензль
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush); //пензль -> у hdc
	MoveToEx(hdc, xs1, ys1, NULL);
	LineTo(hdc, xs1, ys2); 
	LineTo(hdc, xs2, ys2); 
	LineTo(hdc, xs2, ys1); 
	LineTo(hdc, xs1, ys1);

	SelectObject(hdc, hBrushOld); //відновлюється пензль-попередник
	DeleteObject(hBrush);
}