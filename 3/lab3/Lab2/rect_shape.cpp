#include "framework.h"
#include "rect_shape.h"

HBRUSH hBrush, hBrushOld;

void RectShape::Show(HDC hdc) {
	hBrush = (HBRUSH)CreateSolidBrush(RGB(192, 192, 192)); //����������� ������
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush); //������ -> � hdc
	MoveToEx(hdc, xs1, ys1, NULL);
	LineTo(hdc, xs1, ys2); 
	LineTo(hdc, xs2, ys2); 
	LineTo(hdc, xs2, ys1); 
	LineTo(hdc, xs1, ys1);

	SelectObject(hdc, hBrushOld); //������������ ������-����������
	DeleteObject(hBrush);
}