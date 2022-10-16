#pragma once
class Shape {
protected:
	long xs1, ys1, xs2, ys2;
public:
	void SetStart(long xStart, long yStart);
	void SetEnd(long xEnd, long yEnd);
	long getXStart(), getXEnd(), getYStart(), getYEnd();
	virtual void Show(HDC) = 0;
};
