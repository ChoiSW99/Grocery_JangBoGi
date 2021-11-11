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

	vector<Food> refrigeration;
	init(refrigeration, "����");
	vector<Food> freeze;
	init(freeze, "�õ�");
	vector<Food> room;
	init(room, "���");

	while (1)
	{
		init();
		title();
		int menucode = menudraw();
		if (menucode == 0)
		{
			ref->setPosition("fridge");
			while (1) {
				ref->show_inventory(refrigeration, freeze, room);
				ref->getKey(meat, fish, veget, sauce, drink, other);
				Sleep(500);
				system("cls");
			}
		}
		else if (menucode == 1)
		{
			ref->setPosition("meat");
			while (1) {
				ref->show_ingredient(meat, fish, veget, sauce, drink, other);
				ref->getKey(meat, fish, veget, sauce, drink, other);
				Sleep(500);
				system("cls");
			}
		}
		else if (menucode == 2)
		{
			while (1)
			{
				add();
				system("cls");
			}
			
		}
		else if (menucode == 3)
		{
			return 0;
			system("cls");
		}
	}
	return 0;
}