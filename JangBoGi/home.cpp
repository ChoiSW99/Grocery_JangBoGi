#include <stdio.h>
#include <Windows.h>

void title();
void menudraw();
void gotoxy(int x, int y);

int home()
{
	title();
	menudraw();
	return 0;
}

void title()
{
	printf("\n\n\n\n");
	printf("		      ##    ###    ##    ##  ######   ########   #######   ######   #### \n");
	printf("		      ##   ## ##   ###   ## ##    ##  ##     ## ##     ## ##    ##   ##  \n");
	printf("		      ##  ##   ##  ####  ## ##        ##     ## ##     ## ##         ##  \n");
	printf("		      ## ##     ## ## ## ## ##   #### ########  ##     ## ##   ####  ##  \n");
	printf("		##    ## ######### ##  #### ##    ##  ##     ## ##     ## ##    ##   ##  \n");
	printf("		##    ## ##     ## ##   ### ##    ##  ##     ## ##     ## ##    ##   ##  \n");
	printf("		 ######  ##     ## ##    ##  ######   ########   #######   ######   #### \n");
	printf("\n");
}

void menudraw()
{
	gotoxy(50 , 12);
	printf("> �� Ȳ");
	gotoxy(50, 13);
	printf("> �� ��");
	gotoxy(50, 14);
	printf("> �� ��");
	printf("\n");
}

void gotoxy(int x, int y)
{
	HANDLE consoleHandel = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandel, pos);
}

