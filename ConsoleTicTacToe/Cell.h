#pragma once
#ifndef CELL_H
#define CELL_H
class Cell {
public:
	Cell();
	
	void setColor(int _color);
	int getColor();
private:
	int color;
};
#endif