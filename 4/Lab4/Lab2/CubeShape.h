#pragma once
#include "LineShape.h"
#include "RectShape.h"

class CubeShape : public LineShape, public RectShape
{
public:
	virtual void Show(HDC);
	void DrawRubberBand(HWND);
	Shape* copyShape();
	void OnInitMenuPopup(HWND, WPARAM);
};