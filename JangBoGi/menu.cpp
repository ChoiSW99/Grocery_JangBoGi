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

using namespace std;

refrigerator::refrigerator(string position = "NULL", int cursor = 0) {
	this->position = position;
	this->cursor = cursor;
}

void refrigerator::setPosition(string position) {
	this->position = position;
}

void refrigerator::textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void refrigerator::setFood(vector<string> arr, string food) {
	arr.push_back(food);
}

void refrigerator::getKey() {
	char c;
	if (_kbhit()) {
		c = _getch();
		//if (c == 13) {
		//	//���ͷ� ������ �̵�
		//}
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
				else if (position == "vege") {
					position = "fish";
				}
				else if (position == "fruit") {
					position = "vege";
				}
				else if (position == "sauce") {
					position = "fruit";
				}
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
					position = "vege";
				}
				else if (position == "vege") {
					position = "fruit";
				}
				else if (position == "fruit") {
					position = "sauce";
				}
				break;

			case UP:
				if (cursor > 0) {
					cursor -= 1;
				}
				break;
			case DOWN:
				if (cursor < 20) {
					if (position == "fridge" || position == "freezer" || position == "room") {
						cursor += 1;
					}
					else if (position == "meat" || position == "fish" || position == "vege" || position == "fruit" || position == "sauce") {
						cursor += 1;
					}
				}
				break;
			}
		}
	}
}

void refrigerator::show_inventory() //����, �õ�, �ǿ� ����Ʈ�� ���ڷ� �ް� ���
{
	cout << "|";
	if (position == "fridge" && cursor == 0) {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       �����";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       �����";
	}

	cout << "|";
	if (position == "freezer" && cursor == 0) {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       �õ���";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       �õ���";
	}

	cout << "|";
	if (position == "room" && cursor == 0) {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       �ǿ�";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       �ǿ�";
	}
	cout << "|";
	cout << endl;

	cout << "===============================================================\n";
	for (int i = 1; i <= 20; i++) {
		if (position == "fridge" && cursor == i) {
			textcolor(WHITE, RED);
			cout << "|" << left << setw(20) << "       ��������" << "|";
			textcolor(WHITE, BLACK);
		}
		else {
			cout << "|" << left << setw(20) << "       ��������" << "|";
		}

		if (position == "freezer" && cursor == i) {
			textcolor(WHITE, RED);
			cout << left << setw(20) << "       �õ�����" << "|";
			textcolor(WHITE, BLACK);
		}
		else {
			cout << left << setw(20) << "       �õ�����" << "|";
		}

		if (position == "room" && cursor == i) {
			textcolor(WHITE, RED);
			cout << left << setw(20) << "       �ǿ�����" << "|" << endl;
			textcolor(WHITE, BLACK);
		}
		else {
			cout << left << setw(20) << "       �ǿ�����" << "|" << endl;
		}
	}
}

void refrigerator::show_ingredient() {
	cout << "|";
	if (position == "meat" && cursor == 0) {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       ���";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       ���";
	}

	cout << "|";
	if (position == "fish" && cursor == 0) {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       ����";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       ����";
	}

	cout << "|";
	if (position == "vege" && cursor == 0) {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       ä��";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       ä��";
	}

	cout << "|";
	if (position == "fruit" && cursor == 0) {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       ����";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       ����";
	}

	cout << "|";
	if (position == "sauce" && cursor == 0) {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       �ҽ�";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       �ҽ�";
	}
	cout << "|";
	cout << endl;

	cout << "==========================================================================================================\n";
	for (int i = 1; i <= 20; i++) {
		if (position == "meat" && cursor == i) {
			textcolor(WHITE, RED);
			cout << "|" << left << setw(20) << "       ������" << "|";
			textcolor(WHITE, BLACK);
		}
		else {
			cout << "|" << left << setw(20) << "       ������" << "|";
		}

		if (position == "fish" && cursor == i) {
			textcolor(WHITE, RED);
			cout << left << setw(20) << "       �������" << "|";
			textcolor(WHITE, BLACK);
		}
		else {
			cout << left << setw(20) << "       �������" << "|";
		}

		if (position == "vege" && cursor == i) {
			textcolor(WHITE, RED);
			cout << left << setw(20) << "       ä�����" << "|" ;
			textcolor(WHITE, BLACK);
		}
		else {
			cout << left << setw(20) << "       ä�����" << "|";
		}

		if (position == "fruit" && cursor == i) {
			textcolor(WHITE, RED);
			cout << left << setw(20) << "       �������" << "|";
			textcolor(WHITE, BLACK);
		}
		else {
			cout << left << setw(20) << "       �������" << "|";
		}

		if (position == "sauce" && cursor == i) {
			textcolor(WHITE, RED);
			cout << left << setw(20) << "       �ҽ����" << "|" << endl;
			textcolor(WHITE, BLACK);
		}
		else {
			cout << left << setw(20) << "       �ҽ����" << "|" << endl;
		}
	}
}