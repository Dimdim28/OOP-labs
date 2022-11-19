#include "RectShape.h"

void RectShape::Show(HDC hdc)
{
	HBRUSH hBrush, hBrushOld;

	hBrush = (HBRUSH)CreateSolidBrush(RGB(192, 192, 192)); //створюється пензль
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush); //пензль -> у hdc
	MoveToEx(hdc, xs1, ys1, NULL);
	LineTo(hdc, xs1, ys2);
	LineTo(hdc, xs2, ys2);
	LineTo(hdc, xs2, ys1);
	LineTo(hdc, xs1, ys1);
}

void RectShape::DrawRubberBand(HWND hWnd)
{
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd);
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, 0);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	RectShape::Show(hdc);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);

}

Shape* RectShape::copyShape() { return new RectShape; }

void RectShape::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_32771, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32772, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32773, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_32774, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32775, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32776, MF_UNCHECKED);
	}
}