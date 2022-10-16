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
	virtual void GetShape() = 0; 
	//... корисні члени, які враховують специфіку Windows-програм
public:
	ShapeEditor(void);
    void OnLBdown(HWND); // Я не робив його віртуальним бо він однаковий для всіх 4 нащадків
	void OnLBup(HWND);  // теж не робив бо зміг зробити однаковим за домпомогою віртуального метода GetShape()
	virtual void OnMouseMove(HWND) = 0;
	void OnPaint(HWND);
};
