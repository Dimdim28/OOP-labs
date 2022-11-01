#include "ShapeEditor.h"
#include "point_shape.h"
#include "point_editor.h"
#include "Resource.h"


void PointEditor::OnMouseMove(HWND hWnd) {
}

void PointEditor::GetShape() {
	pcshape[index] = new PointShape;
};

void PointEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_32771, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_32772, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32773, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32774, MF_UNCHECKED);
	}
}