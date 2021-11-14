#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

#include "menu.h"
#include "add.h"

using namespace std;

refrigerator::refrigerator(string position = "NULL", int cursor = 0) { //생성자
	this->position = position;
	this->cursor = cursor;
}

void refrigerator::setPosition(string position) { //커서의 위치값 수정
	this->position = position;
}

void refrigerator::textcolor(int foreground, int background) //글자에 색과 배경색넣기
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//키 입력 받기 (방향키 4개) 엔터는 주석처리
bool refrigerator::getKey(vector<Food> meat, vector<Food> fish, vector<Food> veget, vector<Food> sauce, vector<Food> drink, vector<Food> other, vector<Food> refrigeration, vector<Food> freeze, vector<Food> room) {
	char c; // 키 입력
	int i; // 재료 상태(냉장, 냉동, 상온)
	int y = 0, m = 0, d = 0;
	if (_kbhit()) {
		c = _getch();
		if (c == 88 || c == 120) {
			return false;
		}
		if (c == 13) {
			if (position == "meat")
			{
					cout << "재료의 상태를 입력하세요: (1.냉장 2.냉동 3.상온) ";
					cin >> i;
					cout << "재료의 유통기한을 입력하세요(ex: 2022 03 01): ";
					cin >> y >> m >> d;
					while(1) {
						if (y <= 2020 || m <= 0 || d <= 0) {
							cout << "재료의 유통기한을 재입력하세요(ex: 2022 03 01): ";
							cin >> y >> m >> d;
						}
						else 
							break;
					}

					if (i == 1)
					{
						if (!isexist_refri(meat[cursor].getName()))
						{
							FILE* writeFile = fopen("refrigeration.txt", "a");
							fprintf(writeFile, "\n");
							fprintf(writeFile, meat[cursor].getName().c_str());
							fprintf(writeFile, " ");
							fprintf(writeFile, meat[cursor].getRecipe1().c_str());
							fprintf(writeFile, " ");
							fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
							fprintf(writeFile, " ");// 재료 1 2 3 2000 
							fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
							fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
							fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
							fclose(writeFile);
							return true;
						}
						else
						{
							cout << "이미 존재하는 식재료 입니다.\n";
							Sleep(100);
							return true;
						}

					}
					else if (i == 2)
					{
						if (!isexist_freeze(meat[cursor].getName()))
						{
							FILE* writeFile = fopen("freeze.txt", "a");
							fprintf(writeFile, "\n");
							fprintf(writeFile, meat[cursor].getName().c_str());
							fprintf(writeFile, " ");
							fprintf(writeFile, meat[cursor].getRecipe1().c_str());
							fprintf(writeFile, " ");
							fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
							fprintf(writeFile, " ");// 재료 1 2 3 2000 
							fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
							fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
							fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
							fclose(writeFile);
							return true;
						}
						else
						{
							cout << "이미 존재하는 식재료 입니다.\n";
							Sleep(100);
							return true;
						}
					}
					else if (i == 3)
					{
						if (!isexist_room(meat[cursor].getName()))
						{
							FILE* writeFile = fopen("room.txt", "a");
							fprintf(writeFile, "\n");
							fprintf(writeFile, meat[cursor].getName().c_str());
							fprintf(writeFile, " ");
							fprintf(writeFile, meat[cursor].getRecipe1().c_str());
							fprintf(writeFile, " ");
							fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
							fprintf(writeFile, " ");// 재료 1 2 3 2000 
							fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
							fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
							fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
							fclose(writeFile);
							return true;
						}
						else
						{
							cout << "이미 존재하는 식재료 입니다.\n";
							Sleep(100);
							return true;
						}
					}
					else
					{
						cout << "잘못된 상태입니다.";
						Sleep(100);
						return true;
					}

			}
			else if (position == "fish")
			{
					cout << "재료의 상태를 입력하세요: (1.냉장 2.냉동 3.상온) ";
					cin >> i;
					cout << "재료의 유통기한을 입력하세요(ex: 2022 03 01): ";
					cin >> y >> m >> d;
					if (i == 1)
					{
						if (!isexist_refri(fish[cursor].getName()))
						{
							FILE* writeFile = fopen("refrigeration.txt", "a");
							fprintf(writeFile, "\n");
							fprintf(writeFile, fish[cursor].getName().c_str());
							fprintf(writeFile, " ");
							fprintf(writeFile, fish[cursor].getRecipe1().c_str());
							fprintf(writeFile, " ");
							fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
							fprintf(writeFile, " ");// 재료 1 2 3 2000 
							fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
							fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
							fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
							fclose(writeFile);
							return true;
						}
						else
						{
							cout << "이미 존재하는 식재료 입니다.\n";
							Sleep(100);
							return true;
						}

					}
					else if (i == 2)
					{
						if (!isexist_freeze(fish[cursor].getName()))
						{
							FILE* writeFile = fopen("freeze.txt", "a");
							fprintf(writeFile, "\n");
							fprintf(writeFile, fish[cursor].getName().c_str());
							fprintf(writeFile, " ");
							fprintf(writeFile, fish[cursor].getRecipe1().c_str());
							fprintf(writeFile, " ");
							fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
							fprintf(writeFile, " ");// 재료 1 2 3 2000 
							fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
							fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
							fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
							fclose(writeFile);
							return true;
						}
						else
						{
							cout << "이미 존재하는 식재료 입니다.\n";
							Sleep(100);
							return true;
						}
					}
					else if (i == 3)
					{
						if (!isexist_room(fish[cursor].getName()))
						{
							FILE* writeFile = fopen("room.txt", "a");
							fprintf(writeFile, "\n");
							fprintf(writeFile, fish[cursor].getName().c_str());
							fprintf(writeFile, " ");
							fprintf(writeFile, fish[cursor].getRecipe1().c_str());
							fprintf(writeFile, " ");
							fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
							fprintf(writeFile, " ");// 재료 1 2 3 2000 
							fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
							fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
							fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
							fclose(writeFile);
							return true;
						}
						else
						{
							cout << "이미 존재하는 식재료 입니다.\n";
							Sleep(100);
							return true;
						}
					}
					else
					{
						cout << "잘못된 상태입니다.";
						Sleep(100);
						return true;
					}

			}
			else if (position == "veget")
			{
				cout << "재료의 상태를 입력하세요: (1.냉장 2.냉동 3.상온) ";
				cin >> i;
				cout << "재료의 유통기한을 입력하세요(ex: 2022 03 01): ";
				cin >> y >> m >> d;
				if (i == 1)
				{
					if (!isexist_refri(veget[cursor].getName()))
					{
						FILE* writeFile = fopen("refrigeration.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, veget[cursor].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}

				}
				else if (i == 2)
				{
					if (!isexist_freeze(veget[cursor].getName()))
					{
						FILE* writeFile = fopen("freeze.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, veget[cursor].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
				else if (i == 3)
				{
					if (!isexist_room(veget[cursor].getName()))
					{
						FILE* writeFile = fopen("room.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, veget[cursor].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
				else
				{
					cout << "잘못된 상태입니다.";
					Sleep(100);
					return true;
				}
			}
			else if (position == "drink")
			{
				cout << "재료의 상태를 입력하세요: (1.냉장 2.냉동 3.상온) ";
				cin >> i;
				cout << "재료의 유통기한을 입력하세요(ex: 2022 03 01): ";
				cin >> y >> m >> d;
				if (i == 1)
				{
					if (!isexist_refri(drink[cursor].getName()))
					{
						FILE* writeFile = fopen("refrigeration.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, drink[cursor].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}

				}
				else if (i == 2)
				{
					if (!isexist_freeze(drink[cursor].getName()))
					{
						FILE* writeFile = fopen("freeze.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, drink[cursor].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
				else if (i == 3)
				{
					if (!isexist_room(drink[cursor].getName()))
					{
						FILE* writeFile = fopen("room.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, drink[cursor].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
				else
				{
					cout << "잘못된 상태입니다.";
					Sleep(100);
					return true;
				}
			}
			else if (position == "sauce")
			{
				cout << "재료의 상태를 입력하세요: (1.냉장 2.냉동 3.상온) ";
				cin >> i;
				cout << "재료의 유통기한을 입력하세요(ex: 2022 03 01): ";
				cin >> y >> m >> d;
				if (i == 1)
				{
					if (!isexist_refri(sauce[cursor].getName()))
					{
						FILE* writeFile = fopen("refrigeration.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, sauce[cursor].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
				else if (i == 2)
				{
					if (!isexist_freeze(sauce[cursor].getName()))
					{
						FILE* writeFile = fopen("freeze.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, sauce[cursor].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
				else if (i == 3)
				{
					if (!isexist_room(sauce[cursor].getName()))
					{
						FILE* writeFile = fopen("room.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, sauce[cursor].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
				else
				{
					cout << "잘못된 상태입니다.";
					Sleep(100);
					return true;
				}
			}
			else if (position == "other")
			{
				cout << "재료의 상태를 입력하세요: (1.냉장 2.냉동 3.상온) ";
				cin >> i;
				cout << "재료의 유통기한을 입력하세요(ex: 2022 03 01): ";
				cin >> y >> m >> d;
				if (i == 1)
				{
					if (!isexist_refri(other[cursor].getName()))
					{
						FILE* writeFile = fopen("refrigeration.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, other[cursor].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
	
				}
				else if (i == 2)
				{
					if (!isexist_freeze(other[cursor].getName()))
					{
						FILE* writeFile = fopen("freeze.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, other[cursor].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
				else if (i == 3)
				{
					if (!isexist_room(other[cursor].getName()))
					{
						FILE* writeFile = fopen("room.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, other[cursor].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
				else
				{
					cout << "잘못된 상태입니다.";
					Sleep(100);
					return true;
				}
			}
		}
		if (c == -32) {
			c = _getch();

			switch (c) {
			case LEFT:
				if (position == "freezer") {
					position = "fridge";
				}
				else if (position == "room") {
					position = "freezer";
				}
				else if (position == "fish") {
					position = "meat";
				}
				else if (position == "veget") {
					position = "fish";
				}
				else if (position == "sauce") {
					position = "veget";
				}
				else if (position == "drink") {
					position = "sauce";
				}
				else if (position == "other") {
					position = "drink";
				}
				return true;
				break;

			case RIGHT:
				if (position == "fridge") {
					position = "freezer";
				}
				else if (position == "freezer") {
					position = "room";
				}
				else if (position == "meat") {
					position = "fish";
				}
				else if (position == "fish") {
					position = "veget";
				}
				else if (position == "veget") {
					position = "sauce";
				}
				else if (position == "sauce") {
					position = "drink";
				}
				else if (position == "drink") {
					position = "other";
				}
				return true;
				break;

			case UP:
				if (cursor > 0) {
					cursor -= 1;
				}
				return true;
				break;
			case DOWN:
				if (cursor < 20) {
					if (position == "fridge" || position == "freezer" || position == "room") {
						cursor += 1;
					}
					else if (position == "meat" || position == "fish" || position == "veget" || position == "sauce" || position == "drink" || position == "other") {
						cursor += 1;
					}
				}
			}
		}
		if (c == 'd' || c == 'D') {
			if(position == "meat")
				deleteData(meat, cursor);
			else if (position == "fish")
				deleteData(fish, cursor);
			else if (position == "veget")
				deleteData(veget, cursor);
			else if (position == "sauce")
				deleteData(sauce, cursor);
			else if (position == "drink")
				deleteData(drink, cursor);
			else if (position == "other")
				deleteData(other, cursor);

			else if (position == "fridge")
				deleteData(refrigeration, cursor);
			else if (position == "freezer")
				deleteData(freeze, cursor);
			else if (position == "room") 
				deleteData(room, cursor);
			else
				return true;
			return true;
		}
	}
	return true;
}

void refrigerator::show_inventory(vector<Food> refrigeration, vector<Food> freeze, vector<Food> room) //냉장, 냉동, 실온 리스트를 인자로 받고 출력
{
	int i;
	cout << "+==============================================================+\n";
	cout << "|";
	if (position == "fridge") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       냉장고";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       냉장고";
	}

	cout << "|";
	if (position == "freezer") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       냉동실";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       냉동실";
	}

	cout << "|";
	if (position == "room") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       실온";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       실온";
	}
	cout << "|";
	cout << endl;

	cout << "|==============================================================|\n";
	for (i = 1; i <= 20; i++) {
		if (position == "fridge" && cursor == i) {
			if (refrigeration.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(20) << refrigeration[i].getName();  //이 부분에 출력할 값을 넣어줘야함.
				textcolor(WHITE, BLACK);
			}
		}
		else {
			if (refrigeration.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				cout << "|" << left << setw(20) << refrigeration[i].getName();
			}
		}

		if (position == "freezer" && cursor == i) {
			if (freeze.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(20) << freeze[i].getName();
				textcolor(WHITE, BLACK);
			}
		}
		else {
			if (freeze.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				cout << "|" << left << setw(20) << freeze[i].getName();
			}
		}

		if (position == "room" && cursor == i) {
			if (room.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(20) << room[i].getName();
				textcolor(WHITE, BLACK);
			}
			cout << "|" << endl;
		}
		else {
			if (room.size() <= i) {
				cout << "|" << left << setw(20) << "" << "|" << endl;
			}
			else {
				cout << "|" << left << setw(20) << room[i].getName() << "|" << endl;
			}
		}
	}
	cout << "+==============================================================+\n";
	for (int i = 1; i <= 20; i++) {
		//cout << refrigeration.size(); ==> 1
		if (position == "fridge" && cursor == i) {
			if (i < refrigeration.size()) {
				cout << refrigeration[cursor].getName() << "의 레시피는 ";
				if (refrigeration[cursor].getRecipe() != "")
					cout << refrigeration[cursor].getRecipe() << "입니다." << endl;
				else
					cout << "없습니다." << endl;

				cout << "유통기한은 " << refrigeration[cursor].getFYear() << "년 " << refrigeration[cursor].getFMonth() << "월 " << refrigeration[cursor].getFDay() << "일" << "까지입니다." << " ";
				refrigeration[cursor].showLeftDate();
			}
		}
		else if (position == "freezer" && cursor == i) {
			if (i < freeze.size()) {
				cout << freeze[cursor].getName() << "의 레시피는 ";
				if (freeze[cursor].getRecipe() != "")
					cout << freeze[cursor].getRecipe() << "입니다." << endl;
				else
					cout << "없습니다." << endl;

				cout << "유통기한은 " << freeze[cursor].getFYear() << "년 " << freeze[cursor].getFMonth() << "월 " << freeze[cursor].getFDay() << "일" << "까지입니다." << " ";
				freeze[cursor].showLeftDate();
			}
		}
		else if (position == "room" && cursor == i) {
			if (i < room.size()) {
				cout << room[cursor].getName() << "의 레시피는 ";
				if (room[cursor].getRecipe() != "")
					cout << room[cursor].getRecipe() << "입니다." << endl;
				else
					cout << "없습니다." << endl;

				cout << "유통기한은 " << room[cursor].getFYear() << "년 " << room[cursor].getFMonth() << "월 " << room[cursor].getFDay() << "일" << "까지입니다." << " ";
				room[cursor].showLeftDate();
			}
		}
	}
}

void refrigerator::show_ingredient(vector<Food> meat, vector<Food> fish, vector<Food> veget, vector<Food> sauce, vector<Food> drink, vector<Food> other) {
	cout << "+=============================================================================================================================+\n";
	cout << "|";
	if (position == "meat") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       고기";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       고기";
	}

	cout << "|";
	if (position == "fish") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       생선";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       생선";
	}

	cout << "|";
	if (position == "veget") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       채소";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       채소";
	}

	cout << "|";
	if (position == "sauce") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       소스";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       소스";
	}


	cout << "|";
	if (position == "drink") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       음료";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       음료";
	}

	cout << "|";
	if (position == "other") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       그 외";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       그 외";
	}
	cout << "|";
	cout << endl;

	cout << "|=============================================================================================================================|\n";
	for (int i = 1; i <= 20; i++) {
		if (position == "meat" && cursor == i) {

			if (meat.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(20) << meat[i].getName();
				textcolor(WHITE, BLACK);
			}
		}
		else {
			if (meat.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				cout << "|" << left << setw(20) << meat[i].getName();
			}
		}

		if (position == "fish" && cursor == i) {
			if (fish.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(20) << fish[i].getName();
				textcolor(WHITE, BLACK);
			}
		}
		else {
			if (fish.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				cout << "|" << left << setw(20) << fish[i].getName();
			}
		}

		if (position == "veget" && cursor == i) {
			if (veget.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(20) << veget[i].getName();
				textcolor(WHITE, BLACK);
			}
		}
		else {
			if (veget.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				cout << "|" << left << setw(20) << veget[i].getName();
			}
		}

		if (position == "sauce" && cursor == i) {
			if (sauce.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(20) << sauce[i].getName();
				textcolor(WHITE, BLACK);
			}
		}
		else {
			if (sauce.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				cout << "|" << left << setw(20) << sauce[i].getName();
			}
		}

		if (position == "drink" && cursor == i) {
			if (drink.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(20) << drink[i].getName();
				textcolor(WHITE, BLACK);
			}
		}
		else {
			if (drink.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				cout << "|" << left << setw(20) << drink[i].getName();
			}
		}

		if (position == "other" && cursor == i) {
			if (other.size() <= i) {
				cout << "|" << left << setw(20) << "" << "|" << endl;
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(20) << other[i].getName() << "|" << endl;
				textcolor(WHITE, BLACK);
			}
		}
		else {
			if (other.size() <= i) {
				cout << "|" << left << setw(20) << "" << "|" << endl;
			}
			else {
				cout << "|" << left << setw(20) << other[i].getName() << "|" << endl;
			}
		}
	}
	cout << "+=============================================================================================================================+\n";
}

void refrigerator::deleteData(vector<Food>& food, int index) //index는 cursor임.
{
	food.erase(food.begin() + index);
	writeInFile(food);
}
