#include "Cell.h"
//#include "pch.h"


Cell::Cell() {
	setColor(-1);
}

void Cell::setColor(int _color) {
	color = _color;
}

int Cell::getColor() {
	return color;
}