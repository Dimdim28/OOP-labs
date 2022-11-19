#pragma once
#include "framework.h"
#include "resource.h"



class Shape
{
protected:
	long xs1, ys1, xs2, ys2;
public:
	virtual ~Shape();
	void SetStart(long xStart, long yStart);
	void SetEnd(long xEnd, long yEnd);
	virtual void Show(HDC) = 0;
	virtual void DrawRubberBand(HWND) = 0;
	virtual Shape* copyShape() = 0;
	virtual void OnInitMenuPopup(HWND, WPARAM) = 0;
};
