#pragma once

class LineEditor : public ShapeEditor {
	void GetShape();
	void OnMouseMove(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
};
