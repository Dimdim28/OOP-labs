#pragma once
#include "framework.h"
#include <string>
#include <random>
#include <sstream>
#include <codecvt>

class MatrixBuild
{
private:
	MatrixBuild() {}
	MatrixBuild(const MatrixBuild& root) = delete;
	MatrixBuild& operator = (const MatrixBuild&) = delete;

	int N = 0;
	int min = 0;
	int max = 0;

	int** matrix = 0;
	std::string matrixText = "";
public:
	static MatrixBuild& getInstance()
	{
		static MatrixBuild instance;
		return instance;
	}

	void OnCopyData(HWND, WPARAM, LPARAM);
	void OnPaint(HWND, HDC);
	int** CreateMatrix(int, int, int);
	std::string GetMatrixString(int**, int);
	int PutToClipboard(HWND, const char*);
};