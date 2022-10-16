#include "ShapeEditor.h"
#include "rect_shape.h"
#include "rect_editor.h"

void RectEditor::OnMouseMove(HWND hWnd) {
	if (!isPainting) return;
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd); //отримуємо контекст вікна для малювання
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	hPenOld = (HPEN)SelectObject(hdc, hPen); //Малюються лінії "гумового" сліду попереднього розташування курсору
	long xStart = pcshape[index]->getXEnd() - (2 * (pcshape[index]->getXEnd() - pcshape[index]->getXStart())); 	 //до правого верхнього кута
	long yStart = pcshape[index]->getYEnd() - (2 * (pcshape[index]->getYEnd() - pcshape[index]->getYStart()));
	Rectangle(hdc, xStart, yStart, pcshape[index]->getXEnd(), pcshape[index]->getYEnd());

	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[index]->SetEnd(pt.x, pt.y); //координати поточної точки курсору
	xStart = pcshape[index]->getXEnd() - (2 * (pcshape[index]->getXEnd() - pcshape[index]->getXStart())); 	 //до правого верхнього кута
	yStart = pcshape[index]->getYEnd() - (2 * (pcshape[index]->getYEnd() - pcshape[index]->getYStart()));
	Rectangle(hdc, xStart, yStart, pcshape[index]->getXEnd(), pcshape[index]->getYEnd());
	//Малюються лінії "гумового" сліду для поточного розташування курсору

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc); //закриваємо контекст вікна
}

void RectEditor::OnLBdown(HWND hWnd) {
	isPainting = true;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	GetPossibleIndex();
	pcshape[index] = new RectShape;
	pcshape[index]->SetEnd(pt.x, pt.y);
	pcshape[index]->SetStart(pt.x, pt.y);
};