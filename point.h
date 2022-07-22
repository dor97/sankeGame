#pragma once
#include"raylib.h"
#include"shape.h"

class point {

	int row, col;


public:

	point() {}
	point(int row, int col): row(row), col(col) {}

	int getRow() { return row; }
	int getCol() { return col; }

	void setRow(int row) { this->row = row; }
	void setCol(int col) { this->col = col; }


	~point() {}



};