#include "CubeShape.h"

void CubeShape::Show(HDC hdc)
{
	long x1, x2, y1, y2;

	RectShape::Show(hdc);

	x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;

	LineShape::SetStart(x1, y1);
	LineShape::SetEnd( x1 + 30, y1 - 30);
	LineShape::Show(hdc);

	LineShape::SetStart(x1 + 30, y1 - 30);
	LineShape::SetEnd(x2 + 30, y1 - 30);
	LineShape::Show(hdc);

	LineShape::SetStart(x2, y1);
	LineShape::SetEnd(x2 + 30, y1 - 30);
	LineShape::Show(hdc);

	LineShape::SetStart(x2, y2);
	LineShape::SetEnd(x2 + 30, y2 - 30);
	LineShape::Show(hdc);

	LineShape::SetStart(x2 + 30, y1 - 30);
	LineShape::SetEnd(x2 + 30, y2 - 30);
	LineShape::Show(hdc);

	LineShape::SetStart(x1, y2);
	LineShape::SetEnd(x1 + 30, y2 - 30);
	LineShape::Show(hdc);

	LineShape::SetStart(x1 + 30, y2 - 30);
	LineShape::SetEnd(x2 + 30, y2 - 30);
	LineShape::Show(hdc);

	LineShape::SetStart(x1 + 30, y1 - 30);
	LineShape::SetEnd(x1 + 30, y2 - 30);
	LineShape::Show(hdc);

	xs1 = x1; ys1 = y1; xs2 = x2; ys2 = y2;
}


void CubeShape::DrawRubberBand(HWND hWnd)
{
	HDC hdc;
	hdc = GetDC(hWnd);

	long x1, x2, y1, y2;

	RectShape::DrawRubberBand(hWnd);

	x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;

	LineShape::SetStart(x1, y1);
	LineShape::SetEnd(x1 + 30, y1 - 30);
	LineShape::DrawRubberBand(hWnd);
	LineShape::SetStart(x1 + 30, y1 - 30);
	LineShape::SetEnd(x2 + 30, y1 - 30);
	LineShape::DrawRubberBand(hWnd);
	LineShape::SetStart(x2, y1);
	LineShape::SetEnd(x2 + 30, y1 - 30);
	LineShape::DrawRubberBand(hWnd);
	LineShape::SetStart(x2, y2);
	LineShape::SetEnd(x2 + 30, y2 - 30);
	LineShape::DrawRubberBand(hWnd);
	LineShape::SetStart(x2 + 30, y1 - 30);
	LineShape::SetEnd(x2 + 30, y2 - 30);
	LineShape::DrawRubberBand(hWnd);
	LineShape::SetStart(x1, y2);
	LineShape::SetEnd(x1 + 30, y2 - 30);
	LineShape::DrawRubberBand(hWnd);
	LineShape::SetStart(x1 + 30, y2 - 30);
	LineShape::SetEnd(x2 + 30, y2 - 30);
	LineShape::DrawRubberBand(hWnd);
	LineShape::SetStart(x1 + 30, y1 - 30);
	LineShape::SetEnd(x1 + 30, y2 - 30);
	LineShape::DrawRubberBand(hWnd);

	xs1 = x1; ys1 = y1; xs2 = x2; ys2 = y2;
}

Shape* CubeShape::copyShape() { return new CubeShape; }

void CubeShape::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_32771, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32772, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32773, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32774, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32775, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_32776, MF_UNCHECKED);
	}
}