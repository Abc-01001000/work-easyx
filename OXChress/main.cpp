#include <graphics.H>

char boardData[3][3] = {
	{'-', '-', '-'},
	{'-', '-', '-'},
	{'-', '-', '-'}
};
char curTip = 'o';

bool checkDraw() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (boardData[i][j] == '-')
				return false;
		}
	}
	return true;
}

bool checkWin(char c) {
	if (boardData[0][0] == c && boardData[0][1] == c && boardData[0][2] == c)
		return true;
	else if (boardData[1][0] == c && boardData[1][1] == c && boardData[1][2] == c)
		return true;
	else if (boardData[2][0] == c && boardData[2][1] == c && boardData[2][2] == c)
		return true;
	else if (boardData[0][0] == c && boardData[1][0] == c && boardData[2][0] == c)
		return true;
	else if (boardData[0][1] == c && boardData[1][1] == c && boardData[2][1] == c)
		return true;
	else if (boardData[0][2] == c && boardData[1][2] == c && boardData[2][2] == c)
		return true;
	else if (boardData[0][0] == c && boardData[1][1] == c && boardData[2][2] == c)
		return true;
	else if (boardData[2][0] == c && boardData[1][1] == c && boardData[0][2] == c)
		return true;
	return false;
}

void drawBoard() {
	line(20, 220, 620, 220);
	line(20, 420, 620, 420);
	line(220, 20, 220, 620);
	line(420, 20, 420, 620);
}

void drawPiece() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			switch (boardData[i][j]) {
			case 'o':
				circle(j * 200 + 120, i * 200 + 120, 80);
				break;
			case 'x':
				line(j * 200 + 40, i * 200 + 40, (j + 1) * 200, (i + 1) * 200);
				line(j * 200 + 40, (i + 1) * 200, (j + 1) * 200, i * 200 + 40);
			}
		}
	}
}

void drawTipText() {
	static TCHAR str[64];
	_stprintf_s(str, _T("当前棋子类型：%c"), curTip);
	settextcolor(RGB(225, 175, 45));
	outtextxy(0, 0, str);
}

int main() {
	initgraph(640, 640);
	BeginBatchDraw();
	bool running = true;
	ExMessage msg;
	while (running) {
		DWORD startTime = GetTickCount();
		while (peekmessage(&msg)) {
			if (msg.message == WM_LBUTTONDOWN) {
				int x = msg.x, y = msg.y;
				int index_x = (x - 20) / 200, index_y = (y - 20) / 200;
				if (boardData[index_y][index_x] == '-') {
					boardData[index_y][index_x] = curTip;
					if (curTip == 'o')
						curTip = 'x';
					else
						curTip = 'o';
				}
			}
		}
		cleardevice();
		drawBoard();
		drawPiece();
		drawTipText();
		FlushBatchDraw();
		if (checkWin('x')) {
			MessageBox(GetHWnd(), _T("X玩家获胜"), _T("游戏结束"), MB_OK);
			running = false;
		} else if (checkWin('o')) {
			MessageBox(GetHWnd(), _T("O玩家获胜"), _T("游戏结束"), MB_OK);
            running = false;
		} else if (checkDraw()) {
			MessageBox(GetHWnd(), _T("平局"), _T("游戏结束"), MB_OK);
			running = false;
		}
		DWORD endTime = GetTickCount();
		DWORD deltaTime = GetTickCount();
		if (deltaTime < 1000 / 30)
			Sleep(1000 / 30 - deltaTime);
	}
	EndBatchDraw();
	return 0;
}