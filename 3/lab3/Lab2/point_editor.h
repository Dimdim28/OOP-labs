#pragma once
class PointEditor : public ShapeEditor {
	void GetShape();
	void OnMouseMove(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
};