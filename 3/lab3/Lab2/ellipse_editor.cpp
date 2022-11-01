#include "ShapeEditor.h"
#include "ellipse_shape.h"
#include "ellipse_editor.h"
#include "Resource.h"


void EllipseEditor::OnMouseMove(HWND hWnd) {
	if (!isPainting) return;
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd); //отримуємо контекст вікна для малювання
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	hPenOld = (HPEN)SelectObject(hdc, hPen); //Малюються лінії "гумового" сліду попереднього розташування курсору
	
	long xStart = pcshape[index]->getXEnd() - (2 * (pcshape[index]->getXEnd() - pcshape[index]->getXStart()));
	long yStart = pcshape[index]->getYEnd() - (2 * (pcshape[index]->getYEnd() - pcshape[index]->getYStart()));
	
	Ellipse(hdc, xStart, yStart, pcshape[index]->getXEnd(), pcshape[index]->getYEnd());

	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[index]->SetEnd(pt.x, pt.y); //координати поточної точки курсору


	 xStart = pcshape[index]->getXEnd() - (2 * (pcshape[index]->getXEnd() - pcshape[index]->getXStart()));
	 yStart = pcshape[index]->getYEnd() - (2 * (pcshape[index]->getYEnd() - pcshape[index]->getYStart()));

	Ellipse(hdc, xStart, yStart, pcshape[index]->getXEnd(), pcshape[index]->getYEnd());
	//Малюються лінії "гумового" сліду для поточного розташування курсору

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc); //закриваємо контекст вікна
}

void EllipseEditor::GetShape() {
	pcshape[index] = new EllipseShape;
};

void EllipseEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_32771, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32772, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32773, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32774, MF_CHECKED);

	}
}