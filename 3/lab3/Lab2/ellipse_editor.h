#pragma once

class EllipseEditor : public ShapeEditor {
	void GetShape();
	void OnMouseMove(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
};