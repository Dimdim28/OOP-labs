#include "ShapeEditor.h"
#include "rect_shape.h"
#include "rect_editor.h"
#include "Resource.h"

void RectEditor::OnMouseMove(HWND hWnd) {
	if (!isPainting) return;
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd); //�������� �������� ���� ��� ���������
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	hPenOld = (HPEN)SelectObject(hdc, hPen); //��������� �� "��������" ���� ������������ ������������ �������
	
	Rectangle(hdc, pcshape[index]->getXStart(), pcshape[index]->getYStart(), pcshape[index]->getXEnd(), pcshape[index]->getYEnd());

	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[index]->SetEnd(pt.x, pt.y); //���������� ������� ����� �������
	Rectangle(hdc, pcshape[index]->getXStart(), pcshape[index]->getYStart(), pcshape[index]->getXEnd(), pcshape[index]->getYEnd());
	//��������� �� "��������" ���� ��� ��������� ������������ �������

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc); //��������� �������� ����
}

void RectEditor::GetShape() {
	pcshape[index] = new RectShape;
};

void RectEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_32771, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32772, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32773, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_32774, MF_UNCHECKED);
	}
}
