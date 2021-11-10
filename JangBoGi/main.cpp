#include "home.h"
#include "menu.h"
#include "food.h"
#include "add.h"

int main()
{
	refrigerator* ref = new refrigerator("NULL", 0);
	vector<Food> meat;
	init(meat, "����");
	vector<Food> fish;
	init(fish, "���");
	vector<Food> veget;
	init(veget, "ä��");
	vector<Food> sauce;
	init(sauce, "�ҽ�");
	vector<Food> drink;
	init(drink, "����");
	vector<Food> other;
	init(other, "��Ÿ");

	vector<Food> fridge; //����
	vector<Food> freezer; //�õ�
	vector<Food> room;//���

	while (1)
	{
		init();
		title();
		int menucode = menudraw();
		if (menucode == 0)
		{
			ref->setPosition("fridge");
			while (1) {
				ref->show_inventory(fridge, freezer, room);
				ref->getKey();
				Sleep(500);
				system("cls");
			}
		}
		else if (menucode == 1)
		{
			ref->setPosition("meat");
			while (1) {
				ref->show_ingredient(meat, fish, veget, sauce, drink, other);
				ref->getKey();
				Sleep(500);
				system("cls");
			}
		}
		else if (menucode == 2)
		{
			add();
			system("cls");
		}
		else if (menucode == 3)
		{
			return 0;
			system("cls");
		}
	}
	return 0;
}