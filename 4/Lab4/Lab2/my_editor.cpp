#include "framework.h"
#include "my_editor.h"

Shape* MyEditor::pcshape[shape_size];
int MyEditor::nCurrentIndex = 0;

void MyEditor::Start(HWND hWnd, Shape* shape, LPARAM lParam)
{
	currShape = shape;
	toolbar.OnTool(hWnd, lParam);
}

void MyEditor::OnLBdown(HWND hWnd)
{
	if (!currShape) return;
	isPainting = true;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[nCurrentIndex] = currShape->copyShape();
	pcshape[nCurrentIndex]->SetStart(pt.x, pt.y);
	pcshape[nCurrentIndex]->SetEnd(pt.x, pt.y);
}

void MyEditor::OnLBup(HWND hWnd)
{
	if (!isPainting || !currShape) return;
	isPainting = false;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[nCurrentIndex]->SetEnd(pt.x, pt.y);
	nCurrentIndex = (++nCurrentIndex) % shape_size;
	InvalidateRect(hWnd, NULL, TRUE);
}

void MyEditor::OnMouseMove(HWND hWnd)
{
	if (!isPainting || !currShape) return;
	pcshape[nCurrentIndex]->DrawRubberBand(hWnd);
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[nCurrentIndex]->SetEnd(pt.x, pt.y);
	pcshape[nCurrentIndex]->DrawRubberBand(hWnd);

}

void MyEditor::OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < shape_size; i++)
		if (pcshape[i]) pcshape[i]->Show(hdc);
	EndPaint(hWnd, &ps);
}

void MyEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	if (currShape) currShape->OnInitMenuPopup(hWnd, wParam);
}

void MyEditor::OnCreate(HWND hWnd, HINSTANCE hInst)
{
	toolbar.OnCreate(hWnd, hInst);
}

void MyEditor::OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	toolbar.OnNotify(hWnd, wParam, lParam);
}

void MyEditor::OnSize(HWND hWnd)
{
	toolbar.OnSize(hWnd);
}