#include "LineOOShape.h"

void LineOOShape::Show(HDC hdc)
{
	long x1, x2, y1, y2;

	x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;

	LineShape::SetStart(x1 - 10, y1 - 10);
	LineShape::SetEnd(x2 - 10, y2 - 10);
	LineShape::Show(hdc);

	EllipseShape::SetStart(x1 - 10, y1 - 10);
	EllipseShape::SetEnd(x1 + 10, y1 + 10);

	EllipseShape::Show(hdc);

	EllipseShape::SetStart(x2 - 10, y2 - 10);
	EllipseShape::SetEnd(x2 + 10, y2 + 10);
	EllipseShape::Show(hdc);

	xs1 = x1; ys1 = y1; xs2 = x2; ys2 = y2;
}

void LineOOShape::DrawRubberBand(HWND hWnd)
{
	HDC hdc;
	hdc = GetDC(hWnd);

	long x1, x2, y1, y2;

	x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;

	LineShape::SetStart(x1 - 10, y1 - 10);
	LineShape::SetEnd(x2 - 10, y2 - 10);
	LineShape::DrawRubberBand(hWnd);

	EllipseShape::SetStart(x1 - 10, y1 - 10);
	EllipseShape::SetEnd(x1 + 10, y1 + 10);
	EllipseShape::DrawRubberBand(hWnd);

	EllipseShape::SetStart(x2 - 10, y2 - 10);
	EllipseShape::SetEnd(x2 + 10, y2 + 10);
	EllipseShape::DrawRubberBand(hWnd);

	xs1 = x1; ys1 = y1; xs2 = x2; ys2 = y2;
}

Shape* LineOOShape::copyShape() { return new LineOOShape; }

void LineOOShape::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
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
		CheckMenuItem(hSubMenu, ID_32775, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32776, MF_CHECKED);
	}
}