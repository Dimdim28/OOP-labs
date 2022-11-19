#include "EllipseShape.h"

void EllipseShape::Show(HDC hdc)
{
    long xStart = xs2 - 2 * (xs2 - xs1); 
    long yStart = ys2 - 2 * (ys2 - ys1);

    HBRUSH hBrush, hBrushOld;
    hBrush = (HBRUSH)CreateSolidBrush(RGB(192, 192, 192));
    hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

    Ellipse(hdc, xStart, yStart, xs2, ys2);
    SelectObject(hdc, hBrushOld);
    DeleteObject(hBrush);
}

void EllipseShape::DrawRubberBand(HWND hWnd)
{
    HPEN hPenOld, hPen;
    HDC hdc;
    hdc = GetDC(hWnd);
    SetROP2(hdc, R2_NOTXORPEN);
    hPen = CreatePen(PS_DOT, 1, 0);
    hPenOld = (HPEN)SelectObject(hdc, hPen);

    int sizeX = xs1 - xs2;
    int sizeY = ys1 - ys2;
    Ellipse(hdc, xs1 - sizeX, ys1 - sizeY, xs1 + sizeX, ys1 + sizeY);

    SelectObject(hdc, hPenOld);
    DeleteObject(hPen);
    ReleaseDC(hWnd, hdc);
}

Shape* EllipseShape::copyShape() { return new EllipseShape; }

void EllipseShape::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
    HMENU hMenu, hSubMenu;
    hMenu = GetMenu(hWnd);
    hSubMenu = GetSubMenu(hMenu, 1);
    if ((HMENU)wParam == hSubMenu)
    {
        CheckMenuItem(hSubMenu, ID_32771, MF_UNCHECKED);
        CheckMenuItem(hSubMenu, ID_32772, MF_UNCHECKED);
        CheckMenuItem(hSubMenu, ID_32773, MF_UNCHECKED);
        CheckMenuItem(hSubMenu, ID_32774, MF_CHECKED);
        CheckMenuItem(hSubMenu, ID_32775, MF_UNCHECKED);
        CheckMenuItem(hSubMenu, ID_32776, MF_UNCHECKED);
    }
}