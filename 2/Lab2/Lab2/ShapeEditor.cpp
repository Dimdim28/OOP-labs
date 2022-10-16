#include "ShapeEditor.h"

Shape* pcshape[MY_SHAPE_ARRAY_SIZE];


ShapeEditor::ShapeEditor(void) { };

void ShapeEditor::OnLBdown(HWND hWnd) {
	isPainting = true;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	GetPossibleIndex();
	GetShape();
	pcshape[index]->SetEnd(pt.x, pt.y);
	pcshape[index]->SetStart(pt.x, pt.y);
};

void ShapeEditor::OnLBup(HWND hWnd) {
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[index]->SetEnd(pt.x, pt.y);
	InvalidateRect(hWnd, NULL, TRUE);
	isPainting = false;
};

void ShapeEditor::GetPossibleIndex() {
	for (int i = 0; i < MY_SHAPE_ARRAY_SIZE; i++)
		if (!pcshape[i]) {
			index = i;
			break;
		}
};

void ShapeEditor::OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < MY_SHAPE_ARRAY_SIZE; i++)
		if (pcshape[i])
			pcshape[i]->Show(hdc);
		else break;
	EndPaint(hWnd, &ps);
}
	