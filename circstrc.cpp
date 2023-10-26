#include "msoftcon.h"

struct Circle {
	int xCo, yCo;
	int radius;
	color fillcolor;
	fstyle fillstyle;
};

void circ_draw(Circle c) {
	set_color(c.fillcolor);
	set_fill_style(c.fillstyle);
	draw_circle(c.xCo, c.yCo, c.radius);
}

int main() {
	init_graphics();
	Circle c1 = { 15, 7, 5, cBLUE, X_FILL };
	Circle c2 = { 41, 12, 7, cRED, O_FILL };
	Circle c3 = { 65, 18, 4, cGREEN, MEDIUM_FILL };
	circ_draw(c1);
	circ_draw(c2);
	circ_draw(c3);
	set_cursor_pos(1, 25);
	return 0;
}