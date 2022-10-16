#pragma once
#define MY_SHAPE_ARRAY_SIZE 117

class Editor {
public: //а, можливо, ще потрібен віртуальний деструктор?
	//virtual ~Editor() = 0;
	virtual void OnLBdown(HWND) = 0;
	virtual void OnLBup(HWND) = 0;
	virtual void OnMouseMove(HWND) = 0;
	virtual void OnPaint(HWND) = 0;
};

class ShapeEditor : public Editor {
	//protected:
		//... корисні члени, які враховують специфіку Windows-програм
public:
	ShapeEditor(void);
	virtual void OnLBdown(HWND) = 0;
	virtual void OnLBup(HWND) = 0;
	void OnMouseMove(HWND);
	void OnPaint(HWND);
	void OnInitMenuPopup(HWND, WPARAM); //додатковий інтерфейсний метод
};

class PointEditor : public ShapeEditor {
	void OnLBdown(HWND);
	void OnLBup(HWND);
};

class LineEditor : public ShapeEditor {
	void OnLBdown(HWND);
	void OnLBup(HWND);
};

class RectEditor : public ShapeEditor {
	void OnLBdown(HWND);
	void OnLBup(HWND);
};

class EllipseEditor : public ShapeEditor {
	void OnLBdown(HWND);
	void OnLBup(HWND);
};

Shape* type = NULL;
ShapeEditor* pse = NULL;
Shape* pcshape[MY_SHAPE_ARRAY_SIZE];

ShapeEditor::ShapeEditor(void) { };

void ShapeEditor::OnLBdown(HWND) { };
void ShapeEditor::OnLBup(HWND) { };
void ShapeEditor::OnMouseMove(HWND) { };
void ShapeEditor::OnInitMenuPopup(HWND, WPARAM) { };

void ShapeEditor::OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < MY_SHAPE_ARRAY_SIZE; i++)
		if (pcshape[i])
			pcshape[i]->Show(hdc);
	EndPaint(hWnd, &ps);
}

void PointEditor::OnLBdown(HWND hWnd) {
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	type = new PointShape;
	for (int i = 0; i < MY_SHAPE_ARRAY_SIZE; i++)
		if (!pcshape[i]) {
			pcshape[i] = type;
			break;
		}
};
void LineEditor::OnLBdown(HWND hWnd) {};
void RectEditor::OnLBdown(HWND hWnd) {};
void EllipseEditor::OnLBdown(HWND hWnd) {};


void PointEditor::OnLBup(HWND hWnd) {
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	type->SetEnd(pt.x, pt.y);
	InvalidateRect(hWnd, NULL, TRUE);
};
void LineEditor::OnLBup(HWND hWnd) {};
void RectEditor::OnLBup(HWND hWnd) {};
void EllipseEditor::OnLBup(HWND hWnd) {};