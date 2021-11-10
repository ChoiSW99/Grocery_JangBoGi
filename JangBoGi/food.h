#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#pragma once

#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>
#include <cstring>
using namespace std;

class Food
{
	string name; // ����̸�
	string recipe[3]; // ���� �� �ִ� �丮 ����
	int f_year = 0, f_month = 0, f_day = 0; // �������
	string state = "��"; // ��� ���� ����( ����, �õ�, ���)

	time_t today = time(NULL);
	struct tm* t = localtime(&today);
	int thisYear = t->tm_year + 1900;

public:
	//Food() :name(), makeFood(), f_year(), f_month(), f_day(), state() {}
	Food(string name, string recipe1 = "NO", string recipe2 = "NO", string recipe3 = "NO", int f_year = 0, int f_month = 0, int f_day = 0, string state = "��")
	{
		this->name = name;
		this->f_year = f_year;
		this->f_month = f_month;
		this->f_day = f_day;

		recipe[0] = recipe1;
		recipe[1] = recipe2;
		recipe[2] = recipe3;
		this->state = state;
	}
	// constructor

	string getName() const { return name; }// �̸�����
	string getRecipe() const; // ���� �� �ִ� ���� ����
	//string getRecipe() const;
	string getState() const { return state; } // state ����
	int getFYear() const { return f_year; } // ������� ��
	int getFMonth() const { return f_month; } // ������� ��
	int getFDay() const { return f_day; } // ������� ��

	void setName(string name); // �̸� ����
	void setShelfDate(int f_year, int f_month, int f_day); // ������� ����
	//void setMakeFood(string recipe1, string recipe2, string recipe3); // ���� �� �ִ� �丮 ����
	void setMakeFood();
	void setState(); // �������� ����
	void showMakeFood();

	void showLeftDate(); //������� ��ĥ ���Ҵ���
	void showState(); //���� ��������
	void CheckAll(); //������, �������, �������� ���

};

void ShowAllFood(vector<Food>& food); //�ش� Food����� ��ü ������ ���
void addData(vector<Food>& food);
void addIn(vector<Food>& food, string name, string r1, string r2, string r3);
void addIn(vector<Food>& food, string name);
void writeInFile(vector<Food>& food);
void readInFile(vector<Food>& food); // -->����
void init(vector<Food>& food, string s);
