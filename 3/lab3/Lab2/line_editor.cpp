#include "ShapeEditor.h"
#include "line_shape.h"
#include "line_editor.h"
#include "Resource.h"


void LineEditor::OnMouseMove(HWND hWnd) {
	if (!isPainting) return;
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd); //отримуємо контекст вікна для малювання
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	hPenOld = (HPEN)SelectObject(hdc, hPen); //Малюються лінії "гумового" сліду попереднього розташування курсору

	MoveToEx(hdc, pcshape[index]->getXStart(), pcshape[index]->getYStart(), NULL);
	LineTo(hdc, pcshape[index]->getXEnd(), pcshape[index]->getYEnd());

	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[index]->SetEnd(pt.x, pt.y); //координати поточної точки курсору
	MoveToEx(hdc, pcshape[index]->getXStart(), pcshape[index]->getYStart(), NULL);
	LineTo(hdc, pcshape[index]->getXEnd(), pcshape[index]->getYEnd()); //Малюються лінії "гумового" сліду для поточного розташування курсору

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc); //закриваємо контекст вікна
}

void LineEditor::GetShape() {
	pcshape[index] = new LineShape;
};

void LineEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_32771, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32772, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_32773, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32774, MF_UNCHECKED);
	}
}