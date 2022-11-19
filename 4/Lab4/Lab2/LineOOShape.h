#pragma once
#include "LineShape.h"
#include "EllipseShape.h"

class LineOOShape : public LineShape, public EllipseShape
{
public:
	virtual void Show(HDC);
	void DrawRubberBand(HWND);
	Shape* copyShape();
	void OnInitMenuPopup(HWND, WPARAM);
};