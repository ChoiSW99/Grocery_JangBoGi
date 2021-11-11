#pragma once

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>
#include "food.h"

using namespace std;

class refrigerator {
private:
	std::string position;
	int cursor;

public:
	refrigerator(string, int);
	void setPosition(string);
	void textcolor(int, int);
	bool getKey(vector<Food> meat, vector<Food> fish, vector<Food> veget, vector<Food> sauce, vector<Food> drink, vector<Food> other);
	void show_inventory(vector<Food> fridge, vector<Food> freezer, vector<Food> room);
	void show_ingredient(vector<Food> meat, vector<Food> fish, vector<Food> veget, vector<Food> sauce, vector<Food> drink, vector<Food> other);
	void deleteData(vector<Food>& food, int index); //Food ���Ϳ��� index�� �ش��ϴ� ����� ���� �� txt���Ͽ����� ���� 
};