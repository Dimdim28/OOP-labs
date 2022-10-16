#include "ShapeEditor.h"
#include "point_shape.h"
#include "point_editor.h"


void PointEditor::OnMouseMove(HWND hWnd) {
}

void PointEditor::GetShape() {
	pcshape[index] = new PointShape;
};