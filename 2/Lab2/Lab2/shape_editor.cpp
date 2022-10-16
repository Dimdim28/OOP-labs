#include "framework.h"
#include "shape_editor.h"
#include "shape.h"
#include "editor.h"

ShapeObjectsEditor::ShapeObjectsEditor(void) {}
ShapeObjectsEditor::~ShapeObjectsEditor() {}
void ShapeObjectsEditor::StartPointEditor() {
	if (pse) delete pse;
	pse = new PointEditor;
	//if (type) delete type;
    //type = new PointShape;
}

void ShapeObjectsEditor::StartLineEditor() {
	if (pse) delete pse;
	pse = new LineEditor;
	//if (type) delete type;
	//type = new LineShape;
}

void ShapeObjectsEditor::StartRectEditor() {
	if (pse) delete pse;
	pse = new RectEditor;
	//if (type) delete type;
	//type = new RectShape;
}

void ShapeObjectsEditor::StartEllipseEditor() {
	if (pse) delete pse;
	pse = new EllipseEditor;
	//if (type) delete type;
	//type = new EllipseShape;
}

void ShapeObjectsEditor::OnLBdown(HWND hWnd) {
	if (pse) pse->OnLBdown(hWnd);
}

void ShapeObjectsEditor::OnLBup(HWND hWnd) {
	if (pse) pse->OnLBup(hWnd);
}

void ShapeObjectsEditor::OnMouseMove(HWND hWnd) {
	if (pse) pse->OnMouseMove(hWnd);
}

void ShapeObjectsEditor::OnPaint(HWND hWnd) {
	if (pse) pse->OnPaint(hWnd);
}

void ShapeObjectsEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
	if (pse) pse->OnInitMenuPopup(hWnd, wParam);
} //відповідно варіанту завдання
