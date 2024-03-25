#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265359

int height, thinkness, width, layer, k, h, color;
// char elem;

//菜单
void menu() {
	printf("//=== 1 isosceles right triangle.\n");
	printf("//=== 2 isosceles right triangle(handstand).\n");
	printf("//=== 3 square.\n");
	printf("//=== 4 rectangle.\n");
	printf("//=== 5 pyramid.\n");
	printf("//=== 6 linear function.\n");
	printf("//=== 7 EasyX star.\n");
	printf("//=== 8 EasyX HuaJi.\n");
	printf("//=== 0 esc.\n");
}
//功能选择
int getChoice() {
	printf("Please input your choice: ");
	int choice = 0;
	//过滤非法值
	while (scanf("%d", &choice) != 1) {
		scanf("%*[^\n]%*c");	//fflush()不被vs2022支持
		printf("Error input...Please do it again.\n");
		printf("Please input your choice: ");
	}
	return choice;
}
//选择控制台输出颜色
void selectColor() {
	printf("Please choose a kind of color following.\n");
	printf("    1 == Pale green.\n");
	printf("    2 == Cyan\n");
	printf("    3 == Pale red\n");
	printf("    4 == Pale purple\n");
	printf("    5 == Pale yello\n");
	printf("    6 == Bright white\n");
	printf("    Other == Default\n");
	printf("Input your choice: ");
	while (scanf("%d", &color) != 1) {
		scanf("%*[^\n]%*c");
		printf("Error input...Please do it again.\n");
		printf("Input your choice: ");
	}
	switch (color) {
	case 1:
		system("color A");
		break;
	case 2:
		system("color B");
		break;
	case 3:
		system("color C");
		break;
	case 4:
		system("color D");
		break;
	case 5:
		system("color E");
		break;
	case 6:
		system("color F");
		break;
	default:
		break;
	}
}
//设置等腰直角三角形、正方形的数据
void getData_1() {
	do {
		printf("Please input the height of the graph: ");
		while (scanf("%d", &height) != 1) {
			scanf("%*[^\n]%*c");
			printf("Error input...Please do it again.\n");
			printf("Please input the height of the graph: ");
		}
		if (height < 2 || height > 120)
			printf("Error input...Please do it again.\n");
	} while (height < 2 || height > 120);
	do {
		printf("Please input the thinkness of the graph: ");
		while (scanf("%d", &thinkness) != 1) {
			scanf("%*[^\n]%*c");
			printf("Error input...Please do it again.\n");
			printf("Please input the thinkness of the graph: ");
		}
		if ((thinkness << 1) > height || thinkness <= 0)
			printf("Error input...Please do it again...\n");
	} while ((thinkness << 1) > height || thinkness <= 0);
	// printf("Please input the element to make the graph: ");
	// getchar();
	// scanf("%c", &elem);
	selectColor();
}
//设置矩形的数据
void getData_2() {
	do {
		printf("Please input the height of the graph: ");
		while (scanf("%d", &height) != 1) {
			scanf("%*[^\n]%*c");
			printf("Error input...Please do it again.\n");
			printf("Please input the height of the graph: ");
		}
		if (height < 2 || height > 120)
			printf("Error input...Please do it again.\n");
	} while (height < 2 || height > 120);
	do {
		printf("Please input the width of the graph: ");
		while (scanf("%d", &width) != 1) {
			scanf("%*[^\n]%*c");
			printf("Error input...Please do it again.\n");
			printf("Please input the width of the graph: ");
		}
		if (width < 2 || width > 100)
			printf("Error input...Please do it again.\n");
	} while (width < 2 || width > 100);
	do {
		printf("Please input the thinkness of the graph: ");
		while (scanf("%d", &thinkness) != 1) {
			scanf("%*[^\n]%*c");
			printf("Error input...Please do it again.\n");
			printf("Please input the thinkness of the graph: ");
		}
		if ((thinkness << 1) > height || (thinkness << 1) > width || thinkness <= 0)
			printf("Error input...Please do it again...\n");
	} while ((thinkness << 1) > height || (thinkness << 1) > width ||
		thinkness <= 0);
	// printf("Please input the element to make the graph: ");
	// getchar();
	// scanf("%c", &elem);
	selectColor();
}
//设置金字塔的数据
void getData_3() {
	do {
		printf("Please input the height of the graph: ");
		while (scanf("%d", &height) != 1) {
			scanf("%*[^\n]%*c");
			printf("Error input...Please do it again.\n");
			printf("Please input the height of the graph: ");
		}
		if (height < 2 || height > 120)
			printf("Error input...Please do it again.\n");
	} while (height < 2 || height > 120);
	do {
		printf("Please input the layer of the graph: ");
		while (scanf("%d", &layer) != 1) {
			scanf("%*[^\n]%*c");
			printf("Error input...Please do it again.\n");
			printf("Please input the layer of the graph: ");
		}
		if (layer < 1 || layer * height > 120)
			printf("Error input...Please do it again...\n");
	} while (layer < 1 || layer * height > 120);
	selectColor();
}
//设置一次函数的数据
void getData_4() {
	do {
		printf("Please input k of the linear function: ");
		while (scanf("%d", &k) != 1) {
			scanf("%*[^\n]%*c");
			printf("Error input...Please do it again.\n");
			printf("Please input k of the linear function: ");
		}
		if (k >= 5)
			printf("The k is too large. Please do it again.\n");
	} while (k >= 5);
	do {
		printf("Please input h of the linear function: ");
		while (scanf("%d", &h) != 1) {
			scanf("%*[^\n]%*c");
			printf("Error input...Please do it again.\n");
			printf("Please input h of the linear function: ");
		}
		if (h > 30)
			printf("The h is too large. Please do it again.\n");
	} while (h > 30);
	selectColor();
}
//设置EasyX图形的数据
void getData_5() {
	do {
		printf("Please input the height(px) of the star: ");
		while (scanf("%d", &height) != 1) {
			scanf("%*[^\n]%*c");
			printf("Error input.. Please do it again.\n");
			printf("Please input the height(px) of the star: ");
		}
		if (height > 500)
			printf("Too big...Please do it again.\n");
	} while (height > 500);
	printf("Please select one color.\n");
	printf("	0 == yello.\n");
	printf("	other number == red.\n");
	printf("Your choice: ");
	while (scanf("%d", &color) != 1) {
		scanf("%*[^\n]%*c");
		printf("Error input...Please do it again.\n");
		printf("Your choice: ");
	}
	height >>= 2;
}
//等腰直角三角形的输出（_h为倒立）
void iRightTraingle() {
	for (int i = 0; i < thinkness; ++i) {
		for (int j = 0; j < thinkness; ++j)
			printf("#");
		// printf("%c", elem);
		printf("\n");
	}
	int tempLayer = thinkness + 1;
	for (int i = 0; i < thinkness && i < height - 2 * thinkness; ++i) {
		for (int j = 0; j < tempLayer; ++j)
			printf("#");
		// printf("%c", elem);
		printf("\n");
		++tempLayer;
	}
	int block = 1;
	for (int i = 0; i < height - tempLayer - thinkness + 1; ++i) {
		for (int j = 0; j < thinkness; ++j)
			printf("#");
		// printf("%c", elem);
		for (int j = 0; j < block; ++j)
			printf(" ");
		for (int j = 0; j < thinkness; ++j)
			printf("#");
		// printf("%c", elem);
		printf("\n");
		++block;
	}
	for (int i = 0; i < thinkness; ++i) {
		for (int j = 0; j < height; ++j)
			printf("#");
		// printf("%c", elem);
		printf("\n");
	}
}
void iRightTraingle_h() {
	for (int i = 0; i < thinkness; ++i) {
		for (int j = 0; j < height; ++j)
			printf("#");
		// printf("%c", elem);
		printf("\n");
	}
	int block = height - 3 * thinkness;
	while (block > 0) {
		for (int j = 0; j < thinkness; ++j)
			printf("#");
		// printf("%c", elem);
		for (int j = 0; j < block; ++j)
			printf(" ");
		for (int j = 0; j < thinkness; ++j)
			printf("#");
		// printf("%c", elem);
		printf("\n");
		--block;
	}
	int tempLayer;
	block = height - 3 * thinkness;
	if (block > 0)
		tempLayer = height - 2 * thinkness - block;
	else
		tempLayer = height - 2 * thinkness;
	while (tempLayer--) {
		for (int i = 0; i < thinkness + tempLayer + 1; ++i)
			printf("#");
		// printf("%c", elem);
		printf("\n");
	}
	for (int i = 0; i < thinkness; ++i) {
		for (int j = 0; j < thinkness; ++j)
			printf("#");
		// printf("%c", elem);
		printf("\n");
	}
}
//正方形和矩形的输出
void rectangle() {
	for (int i = 0; i < thinkness; ++i) {
		for (int j = 0; j < width; ++j)
			printf("#");
		// printf("%c", elem);
		printf("\n");
	}
	int block = width - 2 * thinkness;
	for (int i = 0; i < height - 2 * thinkness; ++i) {
		for (int j = 0; j < thinkness; ++j)
			printf("#");
		// printf("%c", elem);
		for (int j = 0; j < block; ++j)
			printf(" ");
		for (int j = 0; j < thinkness; ++j)
			printf("#");
		// printf("%c", elem);
		printf("\n");
	}
	for (int i = 0; i < thinkness; ++i) {
		for (int j = 0; j < width; ++j)
			printf("#");
		// printf("%c", elem);
		printf("\n");
	}
}
//金字塔的输出
void pyramid() {
	int delta = height * layer;
	for (int i = 0; i < delta; ++i) {
		for (int j = 0; j < delta << 1; ++j) {
			if (j == -i + delta - 1)
				printf("/");
			else if (j == i + delta)
				printf("\\");
			else if (j > -i + delta - 1 && j < i + delta) {
				if (0 == (i + delta - j) % (height << 1))
					printf("\\");
				else if ((j + i - delta + 1) % (height << 1) == 0)
					printf("/");
				else if ((i + 1) % height == 0)
					printf("_");
				else
					printf(" ");
			}
			else
				printf(" ");
		}
		printf("\n");
	}
}
//一次函数的输出
void test() {
	for (int i = -20; i < 21; ++i) {
		for (int j = -30; j < 31; ++j) {
			if (i == 0)
				printf("-");
			else if (j == 0)
				printf("|");
			else if (i + k * j + h == 0)
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
}
//用EasyX画一个五角星
void drawStar() {
	initgraph(640, 480);
	//line(100, 100, 100, 200);
	POINT pts[5];
	double a = PI / 2;
	double r = 2.0 * height * pow(cos(PI / 5), 2);
	// h * tan(pi / 5) = r * sin(2 * pi / 5)
	// r = h * 2 * cos ^ 2(pi / 5);
	for (int i = 0; i < 5; ++i) {
		pts[i].x = int(320 + cos(a) * r);
		pts[i].y = int(240 - sin(a) * r);
		a += PI * 4 / 5;
	}
	setpolyfillmode(WINDING);
	if (color)
		setfillcolor(YELLOW);
	else
		setfillcolor(RED);
	solidpolygon(pts, 5);
	closegraph();
}
//用EasyX加载滑稽的表情图片并旋转直到淡出
void drawHuaJi() {
	initgraph(1080, 640);
	IMAGE img, imgout;
	double radius = 0;
	ExMessage msg;
	bool flag = true;
	BeginBatchDraw();
	while (flag) {
		DWORD beginTime = GetTickCount();
		loadimage(&img, _T(".\\resource\\img\\OIP-C.png"));
		radius += PI / 60;
		rotateimage(&imgout, &img, radius);
		while (peekmessage(&msg)) {
			if (msg.message == WM_KEYDOWN)
				flag = false;
		}
	/*	img = imgout;*/
		cleardevice();
		outtextxy(0, 600, _T("按任意键继续..."));
		putimage(150, 200, &imgout);
		putimage(650, 200, &imgout);
		FlushBatchDraw();
		DWORD endTime = GetTickCount();
		DWORD delta = endTime - beginTime;
		if (delta < 1000 / 60)
			Sleep(1000 / 60 - delta);
	}
	closegraph();
}

//程序入口
int main() {
	while (1) {
		system("cls");	//每次绘制完图形都要清理屏幕
		system("color 7");	//还原到默认字体颜色
		menu();
		switch (getChoice()) {
		case 1:
			getData_1();
			iRightTraingle();
			system("pause");
			break;
		case 2:
			getData_1();
			iRightTraingle_h();
			system("pause");
			break;
		case 3:
			getData_1();
			width = height;	//正方形是特殊的矩形
			rectangle();
			system("pause");
			break;
		case 4:
			getData_2();
			rectangle();
			system("pause");
			break;
		case 5:
			getData_3();
			pyramid();
			system("pause");
			break;
		case 6:
			getData_4();
			test();
			system("pause");
			break;
		case 7:
			getData_5();
			drawStar();
			system("pause");
			break;
		case 8:
			drawHuaJi();
			system("pause");
			break;
		case 0:
			printf("See you...\n");
			return 0;
		default:
			printf("Error...Wrong input...\n");
			system("pause");
			break;
		}
	}
}
