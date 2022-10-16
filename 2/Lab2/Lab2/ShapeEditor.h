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
	//... корисні члени, які враховують специфіку Windows-програм
public:
	ShapeEditor(void);
	virtual void OnLBdown(HWND) = 0;
	void OnLBup(HWND); // Я не робив його віртуальним бо він однаковий для всіх 4 нащадків
	virtual void OnMouseMove(HWND) = 0;
	void OnPaint(HWND);
};
