#include "PointShape.h"

void PointShape::Show(HDC hdc)
{
	SetPixel(hdc, xs1, ys1, RGB(255, 0, 0));
}

void PointShape::DrawRubberBand(HWND hWnd) { }

Shape* PointShape::copyShape() { return new PointShape; }

void PointShape::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_32771, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_32772, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32773, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32774, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32775, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32776, MF_UNCHECKED);
	}
}