#pragma once

#include "editor.h"
#include "shape.h"

#define MY_SHAPE_ARRAY_SIZE 118


class ShapeEditor : public Editor {
protected:
	POINT pt;
	HMENU hMenu, hSubMenu;
	int index = 0;
	void GetPossibleIndex();
	static Shape** pcshape;
	bool isPainting = false;
	virtual void GetShape() = 0; 
	//... ������ �����, �� ���������� ��������� Windows-�������
public:
	ShapeEditor(void);
    void OnLBdown(HWND); // � �� ����� ���� ���������� �� �� ��������� ��� ��� 4 �������
	void OnLBup(HWND);  // ��� �� ����� �� ��� ������� ��������� �� ���������� ����������� ������ GetShape()
	virtual void OnMouseMove(HWND) = 0;
	void OnPaint(HWND);
	virtual void OnInitMenuPopup(HWND, WPARAM) = 0;
};
