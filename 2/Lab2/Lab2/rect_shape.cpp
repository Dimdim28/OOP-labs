#include "framework.h"
#include "rect_shape.h"

HBRUSH hBrush, hBrushOld;

void RectShape::Show(HDC hdc) {
	hBrush = (HBRUSH)CreateSolidBrush(RGB(192, 192, 192)); //����������� ������
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush); //������ -> � hdc

	long xStart = xs2 - (2 * (xs2 - xs1)); 	 //�� ������� ��������� ����
	long yStart = ys2 - (2 * (ys2 - ys1));

	Rectangle(hdc, xStart, yStart, xs2, ys2);

	SelectObject(hdc, hBrushOld); //������������ ������-����������
	DeleteObject(hBrush);

}