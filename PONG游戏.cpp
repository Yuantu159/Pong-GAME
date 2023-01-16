#include<stdio.h>
#include<stdlib.h>
#include<easyx.h>
#include<conio.h>


int main() {

	printf("P1：w=上，s=下\nP2:8=上，2=下\n");
	system("pause");

	//创建窗体
	initgraph(800,600);
	setorigin(400,300);
	setaspectratio(1,-1);

	//小球的初始化
	int r = 10;		//圆的半径
	int x = 0, y = 0;
	int vx = -5, vy = 5;

	//挡板的初始化
	int x1 = -400, y1 = 150;		//挡板的左上角坐标
	int x2 = -380, y2 = -150;	//挡板的右下角坐标

	//第二个挡板的初始化
	int _2x1 = 380, _2y1 = 150;		//挡板的左上角坐标
	int _2x2 = 400, _2y2 = -150;	//挡板的右下角坐标

	solidcircle(x,y,r);

	
	while (1) {

		//小球的运动
		cleardevice();
		solidcircle(x, y, r);
		x += vx;
		y += vy;

		//小球的碰撞
		if (y >= 300 - r) {
			vy = -vy;
		}
		else if (y <= -300 + r) {
			vy = -vy;
		}
		else if (x2 >= x && x1 <= x && y1 >= y && y2 <= y) {	//撞到挡板后的移动
			vx = -vx;
		}
		else if (_2x2 >= x && _2x1 <= x && _2y1 >= y && _2y2 <= y) {	//撞到挡板后的移动
			vx = -vx;
		}
		

		//挡板的绘制
		
		solidrectangle(x1,y1,x2,y2);

		//第二块挡板的绘制
		solidrectangle(_2x1, _2y1, _2x2, _2y2);


		//挡板的移动
		if (_kbhit() != 0) {
			char a1 = _getch();
			switch (a1) {
			case 'w':
				if ( y1<= 300) {
					y1 += 20;
					y2 += 20;
				}
				break;
			case 's':
				if (y2 >= -300) {
					y1 -= 20;
					y2 -= 20;
				}
				break;
			case '8':
				if (_2y1 <= 300) {
					_2y1 += 20;
					_2y2 += 20;
				}
				break;
			case'2':
				if (_2y2 >= -300) {
					_2y1 -= 20;
					_2y2 -= 20;
				}
				break;
			}
		}





		if (x >= 400 || x <= -400) {	//撞到两边
			//小球的初始化
			 r = 10;		//圆的半径

			 x = rand() % 401 - 200;	//随机圆的位置
			 y = rand() % 301 - 150;

			 vx = 5;
			 vy = 5;		//移动方向随机
			 if (rand() % 2 == 0) {
				 vx = -vx;
			 }
			 if (rand() % 2 == 0) {
				 vy = -vy;
			 }

			//挡板的初始化
			 x1 = -400, y1 = 150;		//挡板的左上角坐标
			 x2 = -380, y2 = -150;	//挡板的右下角坐标

			//第二个挡板的初始化
			 _2x1 = 380, _2y1 = 150;		//挡板的左上角坐标
			 _2x2 = 400, _2y2 = -150;	//挡板的右下角坐标
		}

		Sleep(1);

	}

	getchar();
	closegraph();
	return 0;
}