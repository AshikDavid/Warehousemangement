#include<ctype.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
int a=0;
void design(int d=2);
void password();
#include<WCLASS.H>
#include<wpass.h>
#include<WFUNC.H>
#include<WMENU.H>

void main()
{
	clrscr();
	int gd=EGA,gm=1;
	initgraph(&gd,&gm,"../BGI");
	setbkcolor(1);
	design();
	setlinestyle(0,SOLID_FILL,3);
	settextstyle(8,0,6);
	delay(500);
	outtextxy(200,90,"WELCOME");
	settextstyle(1,0,2);
	delay(1000);
	outtextxy(150,200,"WAREHOUSE MANAGEMENT SYSTEM");
	settextstyle(1,0,1);
	delay(500);
	outtextxy(530,311,"loading");
	setlinestyle(0,CLOSE_DOT_FILL,3);
    for(int j=0,c=59;j<1;j++,c+=2)
	{
		for(int i=0;i<56;i+=5)
		{
			setcolor(c);
			line(540+i,335,545+i,340);
			line(545+i,340,540+i,345);
			delay(500);
		}
	}
		int choice;
		cleardevice();
		setbkcolor(1);
		design(1);
		settextstyle(2,0,2);
		setcolor(1);
		outtextxy(590,334,"CREATIVE ART");
		design(1);
		settextstyle(1,0,2);
		rectangle(80,130,450,287);
		
		outtextxy(110,130,"1.Administator");
		outtextxy(110,160,"2.Customer");
		outtextxy(110,190,"3.Credits");
		outtextxy(110,220,"4.Exit");
		outtextxy(150,260,"Enter your choice: ");
		gotoxy(44,20);cin>>choice;

		switch(choice)
		{
			case 1:
					admn_menu();
					break;
			case 2:
					cust();
					break;
			case 3:
						cleardevice();
						settextstyle(1,0,4);
						outtextxy(240,40,"CREDITS");
						delay(500);
						outtextxy(150,80,"Ashik David Abraham");
						delay(500);
						outtextxy(150,110,"Ruben Kuruvilla Thomas");
						delay(500);
						outtextxy(150,140,"Jefin P Rajan");
						delay(500);
						outtextxy(150,170,"Rohan Thomas Reji");
						delay(500);
						outtextxy(150,200,"Jabez Abraham");
						delay(1000);
						break;
			case 4:
				cleardevice();
				design(1);
				outtextxy(270,200,"Enter any key");
				getch();
				break;


			default:
					outtextxy(10,10,"Invalid choice");
		}
		closegraph();

}