#include "ShapeEditor.h"
#include "line_shape.h"
#include "line_editor.h"


void LineEditor::OnMouseMove(HWND hWnd) {
	if (!isPainting) return;
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd); //�������� �������� ���� ��� ���������
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	hPenOld = (HPEN)SelectObject(hdc, hPen); //��������� �� "��������" ���� ������������ ������������ �������

	MoveToEx(hdc, pcshape[index]->getXStart(), pcshape[index]->getYStart(), NULL);
	LineTo(hdc, pcshape[index]->getXEnd(), pcshape[index]->getYEnd());

	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[index]->SetEnd(pt.x, pt.y); //���������� ������� ����� �������
	MoveToEx(hdc, pcshape[index]->getXStart(), pcshape[index]->getYStart(), NULL);
	LineTo(hdc, pcshape[index]->getXEnd(), pcshape[index]->getYEnd()); //��������� �� "��������" ���� ��� ��������� ������������ �������

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc); //��������� �������� ����
}

void LineEditor::GetShape() {
	pcshape[index] = new LineShape;
};