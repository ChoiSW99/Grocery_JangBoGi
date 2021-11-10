#include "home.h"
#include "menu.h"
#include "food.h"
#include "add.h"

int main()
{
	refrigerator* ref = new refrigerator("NULL", 0);
	vector<Food> meat;
	init(meat, "육류");
	vector<Food> fish;
	init(fish, "어류");
	vector<Food> veget;
	init(veget, "채소");
	vector<Food> sauce;
	init(sauce, "소스");
	vector<Food> drink;
	init(drink, "음료");
	vector<Food> other;
	init(other, "기타");

	vector<Food> fridge; //냉장
	vector<Food> freezer; //냉동
	vector<Food> room;//상온

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