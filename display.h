#ifndef __DISPLAY__
#define __DISPLAY__

#include <iostream>
#include "map.h"
#include "unit.h"

template <typename T>
void display(Map<T> map) {
	int imax = getMaxRow(map);
	int jmax = getMaxColumn(map);
	for (int i = 0; i <= imax; i++) {
		for (int j = 0; j <= jmax; j++) {
			display(map.get(i, j));
		}
		std::cout << std::endl;
	}
}

void display(Unit *unit) {
	if (unit == NULL) {
		std::cout << " ";
	} else {
		std::cout << "o";
	}
}

void display(int i) {
	if (i == -1) {
		std::cout << " ";
	} else {
		std::cout << "o";
	}
}

#endif
