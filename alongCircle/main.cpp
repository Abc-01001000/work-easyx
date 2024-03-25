#include <graphics.h>

int main() {
	initgraph(640, 480);
	BeginBatchDraw();
	int x = 100, y = 100;
	ExMessage msg;
	while (true) {
		while (peekmessage(&msg)) {
			if (msg.message == WM_MOUSEMOVE) {
				x = msg.x;
				y = msg.y;
			}
		}
		cleardevice();
		solidcircle(x, y, 50);
		FlushBatchDraw();
	}
	EndBatchDraw();
	return 0;
}