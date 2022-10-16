#pragma once
class Shape {
protected:
	long xs1, ys1, xs2, ys2;
public:
	void SetStart(long xStart, long yStart);
	void SetEnd(long xEnd, long yEnd);
	virtual void Show(HDC) = 0;
};

class PointShape : public Shape {
public:
	void Show(HDC);
};

class LineShape : public Shape {
public:
	void Show(HDC);
};

class RectShape : public Shape {
public:
	void Show(HDC);
};

class EllipseShape : public Shape {
public:
	void Show(HDC);
};