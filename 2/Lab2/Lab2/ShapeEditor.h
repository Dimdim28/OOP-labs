#pragma once

#include "editor.h"
#include "shape.h"

#define MY_SHAPE_ARRAY_SIZE 117

extern Shape* pcshape[];

class ShapeEditor : public Editor {
protected:
	POINT pt;
	int index = 0;
	void GetPossibleIndex();
	bool isPainting = false;
	//... ������ �����, �� ���������� ��������� Windows-�������
public:
	ShapeEditor(void);
	virtual void OnLBdown(HWND) = 0;
	void OnLBup(HWND); // � �� ����� ���� ���������� �� �� ��������� ��� ��� 4 �������
	virtual void OnMouseMove(HWND) = 0;
	void OnPaint(HWND);
};
