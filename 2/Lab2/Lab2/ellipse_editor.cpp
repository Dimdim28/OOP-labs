#include "ShapeEditor.h"
#include "ellipse_shape.h"
#include "ellipse_editor.h"


void EllipseEditor::OnMouseMove(HWND hWnd) {
	if (!isPainting) return;
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd); //отримуємо контекст вікна для малювання
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	hPenOld = (HPEN)SelectObject(hdc, hPen); //Малюються лінії "гумового" сліду попереднього розташування курсору
	Ellipse(hdc, pcshape[index]->getXStart(), pcshape[index]->getYStart(), pcshape[index]->getXEnd(), pcshape[index]->getYEnd());

	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[index]->SetEnd(pt.x, pt.y); //координати поточної точки курсору

	Ellipse(hdc, pcshape[index]->getXStart(), pcshape[index]->getYStart(), pcshape[index]->getXEnd(), pcshape[index]->getYEnd());
	//Малюються лінії "гумового" сліду для поточного розташування курсору

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc); //закриваємо контекст вікна
}

void EllipseEditor::GetShape() {
	pcshape[index] = new EllipseShape;
};