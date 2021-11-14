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

//Ű �Է� �ޱ� (����Ű 4��) ���ʹ� �ּ�ó��
bool refrigerator::getKey(vector<Food> meat, vector<Food> fish, vector<Food> veget, vector<Food> sauce, vector<Food> drink, vector<Food> other, vector<Food> refrigeration, vector<Food> freeze, vector<Food> room) {
	char c; // Ű �Է�
	int i; // ��� ����(����, �õ�, ���)
	int y = 0, m = 0, d = 0;
	if (_kbhit()) {
		c = _getch();
		if (c == 88 || c == 120) {
			return false;
		}
		if (c == 13) {
			if (position == "meat")
			{
					cout << "����� ���¸� �Է��ϼ���: (1.���� 2.�õ� 3.���) ";
					cin >> i;
					cout << "����� ��������� �Է��ϼ���(ex: 2022 03 01): ";
					cin >> y >> m >> d;
					while(1) {
						if (y <= 2020 || m <= 0 || d <= 0) {
							cout << "����� ��������� ���Է��ϼ���(ex: 2022 03 01): ";
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
							fprintf(writeFile, to_string(y).c_str()); // ��� 1 2 3 2000
							fprintf(writeFile, " ");// ��� 1 2 3 2000 
							fprintf(writeFile, to_string(m).c_str()); // ��� 1 2 3 2000 2
							fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
							fprintf(writeFile, to_string(d).c_str()); // ��� 1 2 3 2000 2 2 2
							fclose(writeFile);
							return true;
						}
						else
						{
							cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
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
							fprintf(writeFile, to_string(y).c_str()); // ��� 1 2 3 2000
							fprintf(writeFile, " ");// ��� 1 2 3 2000 
							fprintf(writeFile, to_string(m).c_str()); // ��� 1 2 3 2000 2
							fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
							fprintf(writeFile, to_string(d).c_str()); // ��� 1 2 3 2000 2 2 2
							fclose(writeFile);
							return true;
						}
						else
						{
							cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
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
							fprintf(writeFile, to_string(y).c_str()); // ��� 1 2 3 2000
							fprintf(writeFile, " ");// ��� 1 2 3 2000 
							fprintf(writeFile, to_string(m).c_str()); // ��� 1 2 3 2000 2
							fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
							fprintf(writeFile, to_string(d).c_str()); // ��� 1 2 3 2000 2 2 2
							fclose(writeFile);
							return true;
						}
						else
						{
							cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
							Sleep(100);
							return true;
						}
					}
					else
					{
						cout << "�߸��� �����Դϴ�.";
						Sleep(100);
						return true;
					}

			}
			else if (position == "fish")
			{
					cout << "����� ���¸� �Է��ϼ���: (1.���� 2.�õ� 3.���) ";
					cin >> i;
					cout << "����� ��������� �Է��ϼ���(ex: 2022 03 01): ";
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
							fprintf(writeFile, to_string(y).c_str()); // ��� 1 2 3 2000
							fprintf(writeFile, " ");// ��� 1 2 3 2000 
							fprintf(writeFile, to_string(m).c_str()); // ��� 1 2 3 2000 2
							fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
							fprintf(writeFile, to_string(d).c_str()); // ��� 1 2 3 2000 2 2 2
							fclose(writeFile);
							return true;
						}
						else
						{
							cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
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
							fprintf(writeFile, to_string(y).c_str()); // ��� 1 2 3 2000
							fprintf(writeFile, " ");// ��� 1 2 3 2000 
							fprintf(writeFile, to_string(m).c_str()); // ��� 1 2 3 2000 2
							fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
							fprintf(writeFile, to_string(d).c_str()); // ��� 1 2 3 2000 2 2 2
							fclose(writeFile);
							return true;
						}
						else
						{
							cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
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
							fprintf(writeFile, to_string(y).c_str()); // ��� 1 2 3 2000
							fprintf(writeFile, " ");// ��� 1 2 3 2000 
							fprintf(writeFile, to_string(m).c_str()); // ��� 1 2 3 2000 2
							fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
							fprintf(writeFile, to_string(d).c_str()); // ��� 1 2 3 2000 2 2 2
							fclose(writeFile);
							return true;
						}
						else
						{
							cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
							Sleep(100);
							return true;
						}
					}
					else
					{
						cout << "�߸��� �����Դϴ�.";
						Sleep(100);
						return true;
					}

			}
			else if (position == "veget")
			{
				cout << "����� ���¸� �Է��ϼ���: (1.���� 2.�õ� 3.���) ";
				cin >> i;
				cout << "����� ��������� �Է��ϼ���(ex: 2022 03 01): ";
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
						fprintf(writeFile, to_string(y).c_str()); // ��� 1 2 3 2000
						fprintf(writeFile, " ");// ��� 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // ��� 1 2 3 2000 2
						fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // ��� 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
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
						fprintf(writeFile, to_string(y).c_str()); // ��� 1 2 3 2000
						fprintf(writeFile, " ");// ��� 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // ��� 1 2 3 2000 2
						fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // ��� 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
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
						fprintf(writeFile, to_string(y).c_str()); // ��� 1 2 3 2000
						fprintf(writeFile, " ");// ��� 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // ��� 1 2 3 2000 2
						fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // ��� 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
						Sleep(100);
						return true;
					}
				}
				else
				{
					cout << "�߸��� �����Դϴ�.";
					Sleep(100);
					return true;
				}
			}
			else if (position == "drink")
			{
				cout << "����� ���¸� �Է��ϼ���: (1.���� 2.�õ� 3.���) ";
				cin >> i;
				cout << "����� ��������� �Է��ϼ���(ex: 2022 03 01): ";
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
						fprintf(writeFile, to_string(y).c_str()); // ��� 1 2 3 2000
						fprintf(writeFile, " ");// ��� 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // ��� 1 2 3 2000 2
						fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // ��� 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
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
						fprintf(writeFile, to_string(y).c_str()); // ��� 1 2 3 2000
						fprintf(writeFile, " ");// ��� 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // ��� 1 2 3 2000 2
						fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // ��� 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
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
						fprintf(writeFile, to_string(y).c_str()); // ��� 1 2 3 2000
						fprintf(writeFile, " ");// ��� 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // ��� 1 2 3 2000 2
						fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // ��� 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
						Sleep(100);
						return true;
					}
				}
				else
				{
					cout << "�߸��� �����Դϴ�.";
					Sleep(100);
					return true;
				}
			}
			else if (position == "sauce")
			{
				cout << "����� ���¸� �Է��ϼ���: (1.���� 2.�õ� 3.���) ";
				cin >> i;
				cout << "����� ��������� �Է��ϼ���(ex: 2022 03 01): ";
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
						fprintf(writeFile, to_string(y).c_str()); // ��� 1 2 3 2000
						fprintf(writeFile, " ");// ��� 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // ��� 1 2 3 2000 2
						fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // ��� 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
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
						fprintf(writeFile, to_string(y).c_str()); // ��� 1 2 3 2000
						fprintf(writeFile, " ");// ��� 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // ��� 1 2 3 2000 2
						fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // ��� 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
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
						fprintf(writeFile, to_string(y).c_str()); // ��� 1 2 3 2000
						fprintf(writeFile, " ");// ��� 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // ��� 1 2 3 2000 2
						fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // ��� 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
						Sleep(100);
						return true;
					}
				}
				else
				{
					cout << "�߸��� �����Դϴ�.";
					Sleep(100);
					return true;
				}
			}
			else if (position == "other")
			{
				cout << "����� ���¸� �Է��ϼ���: (1.���� 2.�õ� 3.���) ";
				cin >> i;
				cout << "����� ��������� �Է��ϼ���(ex: 2022 03 01): ";
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
						fprintf(writeFile, to_string(y).c_str()); // ��� 1 2 3 2000
						fprintf(writeFile, " ");// ��� 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // ��� 1 2 3 2000 2
						fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // ��� 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
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
						fprintf(writeFile, to_string(y).c_str()); // ��� 1 2 3 2000
						fprintf(writeFile, " ");// ��� 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // ��� 1 2 3 2000 2
						fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // ��� 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
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
						fprintf(writeFile, to_string(y).c_str()); // ��� 1 2 3 2000
						fprintf(writeFile, " ");// ��� 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // ��� 1 2 3 2000 2
						fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // ��� 1 2 3 2000 2 2 2
						fclose(writeFile);
						return true;
					}
					else
					{
						cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
						Sleep(100);
						return true;
					}
				}
				else
				{
					cout << "�߸��� �����Դϴ�.";
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

void refrigerator::show_inventory(vector<Food> refrigeration, vector<Food> freeze, vector<Food> room) //����, �õ�, �ǿ� ����Ʈ�� ���ڷ� �ް� ���
{
	int i;
	cout << "+==============================================================+\n";
	cout << "|";
	if (position == "fridge") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       �����";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       �����";
	}

	cout << "|";
	if (position == "freezer") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       �õ���";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       �õ���";
	}

	cout << "|";
	if (position == "room") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       �ǿ�";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       �ǿ�";
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
				cout << "|" << left << setw(20) << refrigeration[i].getName();  //�� �κп� ����� ���� �־������.
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
				cout << refrigeration[cursor].getName() << "�� �����Ǵ� ";
				if (refrigeration[cursor].getRecipe() != "")
					cout << refrigeration[cursor].getRecipe() << "�Դϴ�." << endl;
				else
					cout << "�����ϴ�." << endl;

				cout << "��������� " << refrigeration[cursor].getFYear() << "�� " << refrigeration[cursor].getFMonth() << "�� " << refrigeration[cursor].getFDay() << "��" << "�����Դϴ�." << " ";
				refrigeration[cursor].showLeftDate();
			}
		}
		else if (position == "freezer" && cursor == i) {
			if (i < freeze.size()) {
				cout << freeze[cursor].getName() << "�� �����Ǵ� ";
				if (freeze[cursor].getRecipe() != "")
					cout << freeze[cursor].getRecipe() << "�Դϴ�." << endl;
				else
					cout << "�����ϴ�." << endl;

				cout << "��������� " << freeze[cursor].getFYear() << "�� " << freeze[cursor].getFMonth() << "�� " << freeze[cursor].getFDay() << "��" << "�����Դϴ�." << " ";
				freeze[cursor].showLeftDate();
			}
		}
		else if (position == "room" && cursor == i) {
			if (i < room.size()) {
				cout << room[cursor].getName() << "�� �����Ǵ� ";
				if (room[cursor].getRecipe() != "")
					cout << room[cursor].getRecipe() << "�Դϴ�." << endl;
				else
					cout << "�����ϴ�." << endl;

				cout << "��������� " << room[cursor].getFYear() << "�� " << room[cursor].getFMonth() << "�� " << room[cursor].getFDay() << "��" << "�����Դϴ�." << " ";
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

void refrigerator::deleteData(vector<Food>& food, int index) //index�� cursor��.
{
	food.erase(food.begin() + index);
	writeInFile(food);
}
