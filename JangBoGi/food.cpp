#define _CRT_SECURE_NO_WARNINGS 

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
		//this->recipe = recipe;
		recipe[0] = recipe1;
		recipe[1] = recipe2;
		recipe[2] = recipe3;
		this->state = state;
	}
	// constructor

	string getName() const { return name; }// �̸�����
	string getRecipe() const; // ���� �� �ִ� ���� ����
	string getState() const { return state; } // state ����
	int getFYear() const { return f_year; } // ������� ��
	int getFMonth() const { return f_month; } // ������� ��
	int getFDay() const { return f_day; } // ������� ��

	void setName(string name); // �̸� ����
	void setShelfDate(int f_year, int f_month, int f_day); // ������� ����
	void setMakeFood(string recipe1, string recipe2, string recipe3); // ���� �� �ִ� �丮 ����
	void setState(); // �������� ����
	void showMakeFood();

	void showLeftDate(); //������� ��ĥ ���Ҵ���
	void showState(); //���� ��������
	void CheckAll(); //������, �������, �������� ���

};
void ShowAllFood(vector<Food>& food); //�ش� Food����� ��ü ������ ���


string Food::getRecipe() const {
	string FullRecipe;
	for (int i = 0; i < 3; i++) {
		if (recipe[i] != "NO" && recipe[i] != "No") {
			FullRecipe += recipe[i];
			if ((i < 2) && ((recipe[i + 1] != "NO") && (recipe[i + 1] != "No")))
				FullRecipe += ", ";
		}
	}
	if (FullRecipe == "")
		return "���� �� �ִ� �丮�� �����ϴ�.";
	return FullRecipe + "�Դϴ�.";
}

void Food::setName(string name) // �̸� ����
{
	this->name = name;
}

void Food::setShelfDate(int f_year, int f_month, int f_day)
{
	int days = 0;
	if ((thisYear <= f_year) && (f_year <= thisYear + 100))
	{
		if (1 <= f_month && f_month <= 12)
		{
			if (f_month == 1 || f_month == 3 || f_month == 5 || f_month == 7 || f_month == 8 || f_month == 10 || f_month == 12) {
				days = 31;
			}
			else if (f_month == 2) {
				days = 28;
			}
			else
				days = 30;

			if ((1 <= f_day) && (f_day < days)) {
				this->f_year = f_year;
				this->f_month = f_month;
				this->f_day = f_day;
			}
			else {
				cout << getName() << "�� ���� �ٽ� �Է��Ͻÿ�(1~" << days << ")\n" << endl;
				return;
			}

		}
		else {
			cout << getName() << "�� ���� �ٽ� �Է��Ͻÿ�(1~12)\n" << endl;
			return;
		}
	}
	else {
		cout << getName() << "�� ���� �ٽ� �Է��Ͻÿ�(" << thisYear << "~)\n" << endl;
		return;
	}
}

void Food::setMakeFood(string recipe1 = "No", string recipe2 = "NO", string recipe3 = "NO") {
	recipe[0] = recipe1;
	recipe[1] = recipe2;
	recipe[2] = recipe3;
}

void Food::setState() {
	string state;
	cout << getName() << "�� �������¸� �Է��Ͻÿ� : ";
	cin >> state;
	while (1) {
		if (state == "���" || state == "����" || state == "�õ�")
		{
			this->state = state;   return;
		}
		else {  //������ ���¿� �ش� �ȵǸ� ���Է�.
			cout << "���Է� : ";
			cin >> state;
		}
	}
}

void Food::showLeftDate() {
	if (state == "��") //���� ������� ����� �̺����̸� ������� ���X
		return;
	time_t shelfdate, today;
	double diff; //������Ѱ� ����ð� ��
	int day; //�� �� ���� �ϼ� ����
	struct tm user_stime; //����ð� ���� ��
	user_stime.tm_year = f_year - 1900;
	user_stime.tm_mon = f_month - 1;
	user_stime.tm_mday = f_day;
	user_stime.tm_hour = 0, user_stime.tm_min = 0, user_stime.tm_sec = 0, user_stime.tm_isdst = 0;
	shelfdate = mktime(&user_stime); //�������
	time(&today); //����ð�
	diff = difftime(shelfdate, today);
	day = diff / (60 * 60 * 24); //���� ��

	cout << getName() << "�� ��������� " << day << "�� ���ҽ��ϴ�." << endl;
}

void Food::showState() {
	cout << "���� " << getState() << "���� ���Դϴ�." << endl;
}

void Food::showMakeFood() {
	cout << getName() << "���� ���� �� �ִ� ������ " << getRecipe() << endl;
}//���� �� �ִ� ����

//���� ���� �ش� ������� �̸�, ��������, ������� �ѹ��� ������.
void Food::CheckAll() {
	showMakeFood();
	showLeftDate();
	showState();
	cout << endl;
}

//�ش� Food����� ��ü ������ ���
void ShowAllFood(vector<Food>& food) {
	for (Food a : food) {
		cout << a.getName() << endl;
	}
}

int main(void)
{
	vector<Food> meat = {
		Food("�ҵ��", "������ũ", "����", "�Ұ��"), Food("�Ҹ��", "��", "������", "�Ұ��"), Food("�Ҿմٸ�", "��ȸ", "��Ʃ", "��"), Food("�Ұ���", "�Ұ���", "��", "��"), Food("�Ҿ���", "��", "�", "������"),
		Food("�һ���", "��ȸ", "��", "��"), Food("�ҿ��", "����", "������", "�Ұ��"), Food("����","����","������", "����"), Food("ä��", "������ũ", "����", "�������"), Food("�Ƚ�", "����", "����"),
		Food("�������", "����", "����", "��ġ�"), Food("�������", "������", "������", "��ä"), Food("�����Ƚ�", "������", "��ġ����", "������"), Food("��������", "������", "��䰥��"), Food("���� �մٸ���", "�Ұ��", "�", "��"),
		Food("����", "������", "����", "�Ұ��"), Food("���� �޴ٸ���", "����", "����", "������"), Food("���� ����", "������", "�", "����"), Food("���� ������", "����"), Food("���� ���긮��", "����"),
		Food("���", "���", "�����", "�뱸��"), Food("�߰�����", "��", "����", "����"), Food("�� �Ƚ�", "��", "Ƣ��"), Food("�ߴٸ�", "�ٺ�ť", "����", "��"), Food("�� ����", "����", "����", "Ƣ��"),
		Food("�� ���ָӴ�", "����", "����", "��ġ����"), Food("�߹�", "����"), Food("�����", "��", "���", "���챸��"), Food("����������", "������ũ", "������", "��䱸��"), Food("���� ���", "�ֹ���", "����"), Food("���� ����", "Ƣ��", "����", "���챸��"),
		Food("���� �Ƚ�", "�ֹ���", "����", "����"), Food("�� ���", "��Ʃ", "��", "��"), Food("�� �������", "Ƣ��", "����"), Food("�� �Ƚ�", "������ũ" ,"��ġ"), Food("�� ���", "������ũ", "��ġ"),
		Food("�� �����", "����", "�������", "�Ұ��"), Food("�� ���", "����", "�߱��丮"), Food("�� �ٸ���", "����", "Ƣ��", "����"), Food("�� �����", "������ũ","����","����"), Food("�� �����", "����", "��"),
		Food("�� ������", "����", "��ġ", "����"), Food("�� �մٸ���", "����", "��", "��"), Food("�� �޴ٸ���", "����", "����", "ī��"), Food("�� ����", "������ũ", "��ȸ"), Food("�� ��û�", "����", "����", "��ġ")
	};
	vector<Food> fish = { Food("����","�","��"), Food("����","�","��","��"), Food("�Ͼ�"), Food("����"), Food("��ġ","����","����"),Food("���ڹ�","����","����"),Food("����","����","����"), Food("��ġ","ȸ","������","�ָԹ�"), Food("����"),Food("����"),Food("��¡��","��","����","����"),Food("����","������","Ƣ��"),Food("����","����","������","����"), Food("����","������","Ƣ��"),Food("����","����","����"),Food("����","��ȸ","����","��ȸ"),Food("���","����","����"),Food("�췰","ȸ","�ſ���","����"),Food("����","ȸ","����","������ũ"),Food("�ػ�","��ȸ","��","��"),Food("ȫ��","ȸ","��ħ","����"),Food("��ġ","����","����"),Food("�Ʊ�","�Ʊ���"),Food("����","����","��"),Food("��ġ","����"),Food("����","����"),Food("��ø","��ø��"),Food("����","��","Į����"),Food("�������","��","��","��ȸ"),Food("������","Į����","���κ��","�̿���"),Food("������","����","��ħ","����"),Food("������","ȸ","����","��"),Food("ȫ��","��","��"),Food("����������","����","�����丮","����"),Food("����","����","�����丮","��"),Food("Ű����","�������","����","ȸ"),Food("����","��䲿��","��ħ","�����"),Food("����","��������","���ͱ���","������"),Food("�췷��","���屹","�����","�ʹ�ħ"),Food("��","������","�������","��") };
	vector<Food> vegetable = { Food("����"),Food("����"),Food("��"),Food("������"),Food("���ä"),Food("����"),Food("��縮"),Food("����"),Food("����"), Food("��ä"), Food("���"), Food("����"), Food("����"), Food("������"), Food("����"), Food("�Ѷ�λ�"), Food("����"), Food("����"), Food("��"), Food("�̳���"), Food("����"), Food("����"), Food("����"), Food("����"), Food("����ݸ�"), Food("��Ʈ"), Food("����"), Food("����"), Food("���ֳ���"), Food("����"), Food("�ñ�ġ"), Food("�ż���"), Food("����"), Food("����"), Food("��"), Food("����"), Food("�ƺ�ī��"), Food("�ƽ��Ķ�Ž�"), Food("�ƿ�"), Food("��ȣ��"), Food("�����"), Food("�����"), Food("����"), Food("����"), Food("����"), Food("���"), Food("�λ�"), Food("��ä"), Food("�׼�"), Food("û��ä"), Food("ġĿ��"), Food("�ݶ��"), Food("�ᳪ��"), Food("������ī"), Food("ȣ��"), Food("��Ÿ������"), Food("�����̹���"), Food("���̹���"), Food("����̹���"), Food("���̹���"), Food("ǥ�����") };
	vector<Food> sauce = { Food("���"),Food("������"),Food("���尡��"),Food("������"),Food("����"),Food("�����"),Food("��Ÿ�ٰ�"),Food("��ġ����"),Food("����"),Food("����"),Food("�긶��"),Food("������"),Food("����"),Food("������"),Food("�ұ�"),Food("�Ŀ��"),Food("����"),Food("����"),Food("��Ƽ��ũ"),Food("������"),Food("Ÿ��"),Food("�Ľ���"),Food("����"),Food("���ҽ�"),Food("�����������"),Food("�����Ұ����"),Food("�߰�����"),Food("�ߺ��������"),Food("�Ұ�����") };
	vector<Food> drink = { Food("����"), Food("�̿�����"), Food("�꽺"), Food("����"), Food("����ǰ") };
	vector<Food> other = {
		Food("�а��� �ڷº�"), Food("�а��� �߷º�"), Food("�а��� ���º�"), Food("�Ҹ�"), Food("���"), Food("Į������"), Food("�и�"), Food("�ø�"), Food("�̸�"), Food("�޹и�")
	};
	meat[0].CheckAll();
	meat[1].CheckAll();

	ShowAllFood(meat);
	return 0;
}