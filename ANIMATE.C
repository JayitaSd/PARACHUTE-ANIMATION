#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

void parachute(int x,int y){
      setcolor(RED);
      setfillstyle(SOLID_FILL,RED);
      circle(x,y,40);
      floodfill(x,y,RED);
      line(x-40,y+10,x-20,y+80);
      line(x+40,y+10,x+20,y+80);

      rectangle(x-20,y+110,x+20,y+80);
      floodfill(x,y+100 , RED);
}

void sun(int x, int y, int radius){
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,YELLOW);
	circle(x,y,radius);
	floodfill(x,y,YELLOW);
}

void sunray(int x,int y,int radius){
	int raylen, angle;
	int x1, y1, x2, y2;
	setcolor(YELLOW);
	setfillstyle(LINE_FILL, YELLOW);
	raylen = radius+30;
	for(angle=0;angle<360;angle+=30){
		x1= x + radius* cos(angle* M_PI/180);
		y1= y + radius* sin(angle* M_PI/180);
		x2= x + raylen* cos(angle* M_PI/180);
		y2= x + raylen* sin(angle* M_PI/180);
		line(x1,y1,x2,y2);
	}
}

void tree( int x, int y){
	setcolor(BROWN);
	rectangle(x-30, y , x+30, y-100);
	setfillstyle(SOLID_FILL,BROWN);
	floodfill(x, y-20, BROWN);

	setcolor(GREEN);
	circle(x, y-110,60);
	setfillstyle(SOLID_FILL, GREEN);
	floodfill(x, y-60,GREEN);
}

void cloud(int x, int y){
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);

	circle(x,y,20);
	floodfill(x,y,WHITE);

	circle(x+25, y-10,25);
	floodfill(x+25, y-10, WHITE);

	circle(x+50, y,20);
	floodfill(x+50, y, WHITE);
}

void main(){                    //endpoint x=590;
	int x=40,y=350;
	int i=0;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	setbkcolor(LIGHTBLUE);
	setfillstyle(SOLID_FILL,BLUE);
	floodfill(100,100,15);

	while(x<=590){
		cleardevice();
		cloud(110,40 + (pow(-1,i)*10));
		cloud(280,70 + (pow(-1,i+1)*10));
		cloud(420,90 + (pow(-1,i)*10));
		cloud(560,25 + (pow(-1,i+1)*10));
		tree(520,470);
		sun(50,50,30);
		sunray(50,50,30);
		parachute(x,y);
		fflush(stdout);
		x=x+20;
		y=y-10;
		i++;
		delay(500);
	}
	getch();
	closegraph();
}