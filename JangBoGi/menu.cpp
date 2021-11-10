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

refrigerator::refrigerator(string position = "NULL", int cursor = 0) { //������
	this->position = position;
	this->cursor = cursor;
}

void refrigerator::setPosition(string position) { //Ŀ���� ��ġ�� ����
	this->position = position;
}

void refrigerator::textcolor(int foreground, int background) //���ڿ� ���� �����ֱ�
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void refrigerator::getKey() { //Ű �Է� �ޱ� (����Ű 4��) ���ʹ� �ּ�ó��
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
					else if (position == "meat" || position == "fish" || position == "veget" || position == "sauce" || position == "drink" || position == "other") {
						cursor += 1;
					}
				}
				break;
			}
		}
	}
}

void refrigerator::show_inventory(vector<Food> fridge, vector<Food> freezer, vector<Food> room) //����, �õ�, �ǿ� ����Ʈ�� ���ڷ� �ް� ���
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

	cout << "+==============================================================+\n";
	for (int i = 0; i < 20; i++) {
		if (position == "fridge" && cursor == i) {

			if (fridge.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(20) << fridge[i].getName();
				textcolor(WHITE, BLACK);
			}
		}
		else {
			if (fridge.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				cout << "|" << left << setw(20) << fridge[i].getName();
			}
		}

		if (position == "freezer" && cursor == i) {

			if (freezer.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(20) << freezer[i].getName();
				textcolor(WHITE, BLACK);
			}
		}
		else {
			if (freezer.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				cout << "|" << left << setw(20) << freezer[i].getName();
			}
		}

		if (position == "room" && cursor == i) {
			if (room.size() <= i) {
				cout << "|" << left << setw(20) << "" << "|" << endl;
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(20) << room[i].getName() << "|" << endl;
				textcolor(WHITE, BLACK);
			}
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

}

void refrigerator::show_ingredient(vector<Food> meat, vector<Food> fish, vector<Food> veget, vector<Food> sauce, vector<Food> drink, vector<Food> other) {
	cout << "+=============================================================================================================================+\n";
	cout << "|";
	if (position == "meat") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       ���";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       ���";
	}

	cout << "|";
	if (position == "fish") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       ����";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       ����";
	}

	cout << "|";
	if (position == "veget") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       ä��";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       ä��";
	}

	cout << "|";
	if (position == "sauce") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       �ҽ�";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       �ҽ�";
	}


	cout << "|";
	if (position == "drink") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       ����";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       ����";
	}

	cout << "|";
	if (position == "other") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       �� ��";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       �� ��";
	}
	cout << "|";
	cout << endl;

	cout << "|=============================================================================================================================|\n";
	for (int i = 0; i < 20; i++) {
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

void refrigerator::deleteData(vector<Food>& food, int index)
{
	food.erase(food.begin() + index);
	writeInFile(food);
}
