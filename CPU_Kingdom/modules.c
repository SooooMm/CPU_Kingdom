#include "modules.h"

// _getch() value of arrow key (chohadam 21-03-11)
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

// move the cursor funtion (chohadam 21-03-11)
void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// find out the pressed key function (chohadam 21-03-11)
int get_key(void) {
	// if keyboard pressed
	if (_kbhit()) {
		// return pressed value
		return _getch();
	}
	return 1;
}

// move to the arrow key function (chohadam 21-03-11)
void move_arrow_key(
	char key,
	int* x,
	int* y,
	int size,
	int y_min,
	int y_max,
	int x_min,
	int x_max
) {
	const int Y_MIN = y_min;
	const int Y_MAX = y_max;
	const int X_MIN = x_min;
	const int X_MAX = x_max;

	switch (key) {
	// pressed ��
	case UP:
		*y -= size;
		if (*y < Y_MIN) *y = Y_MAX;
		break;
	// pressed ��
	case DOWN:
		*y += size;
		if (*y > Y_MAX) *y = Y_MIN;
		break;
	// pressed ��
	case LEFT:
		*x -= size;
		if (*x < X_MIN) *x = X_MAX;
		break;
	// pressed ��
	case RIGHT:
		*x += size;
		if (*x > X_MAX) *x = X_MIN;
		break;
	}
}