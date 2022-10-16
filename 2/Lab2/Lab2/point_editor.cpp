#include "ShapeEditor.h"
#include "point_shape.h"
#include "point_editor.h"


void PointEditor::OnMouseMove(HWND hWnd) {
}

void PointEditor::OnLBdown(HWND hWnd) {
	GetPossibleIndex();
	pcshape[index] = new PointShape;
};

