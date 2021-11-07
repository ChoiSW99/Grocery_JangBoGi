#include "food.h"

string Food::getRecipe() const {
	string FullRecipe;
	for (int i = 0; i < 3; i++) {
		if (recipe[i] != "NO" && recipe[i] != "No") {
			FullRecipe += recipe[i];
			if ((i < 2) && ((recipe[i + 1] != "NO") && (recipe[i + 1] != "No")))
				FullRecipe += " ";
		}
	}
	if (FullRecipe == "")
		return "";
	return FullRecipe;
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

void Food::setMakeFood() {
	cout << getName() << "���� ���� �� �ִ� ���� ����� �缳���մϴ�.";
	cin >> recipe[0] >> recipe[1] >> recipe[2];
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

void addData(vector<Food>& food) { //vector<Food>& food �� �߰��� ��
	while (1) {
		if (food[0].getName() == "�ҵ��" || food[0].getName() == "����") { //�����Ǳ��� �Է��ؾ��ϴ� ����, ���
			string name = "";
			string recipe1 = "";
			string recipe2 = "";
			string recipe3 = "";
			cout << "�̸�(q�Է½� ����): ";
			cin >> name;
			if (name == "q") {
				writeInFile(food);
				return;
			}
			cout << "������ �Է� ";
			cin >> recipe1 >> recipe2 >> recipe3;
			addIn(food, name, recipe1, recipe2, recipe3);
		}
		else { //������ �Է� ���ص� �Ǵ� ä��, ����, �ҽ�, etc
			string name = "";
			cout << "�̸�(q�Է½� ����): ";
			cin >> name;
			if (name == "q") {
				writeInFile(food);
				return;
			}
			addIn(food, name);
		}
	}
}
void addIn(vector<Food>& food, string name, string r1, string r2, string r3) // �ϳ��� ����� �߰�
{
	food.push_back(Food(name, r1, r2, r3)); //����� �߰�	
	writeInFile(food);
}
void addIn(vector<Food>& food, string name) // �ϳ��� ����� �߰�
{
	food.push_back(Food(name)); //����� �߰�	
	writeInFile(food);
}

//���Ͽ� �̸� �Էµ� ������ �ܿ� �߰��� �� ����.
void writeInFile(vector<Food>& food) { // txt���ϵ鿡 ������ write
	if (food[0].getName() == "�ҵ��") {
		FILE* writeFile = fopen("meat.txt", "w");
		int i = 0, j = 1;
		while (i < food.size()) {
			fprintf(writeFile, food[i].getName().c_str());
			fprintf(writeFile, " ");
			fprintf(writeFile, food[i].getRecipe().c_str());
			if (j < food.size()) {
				fprintf(writeFile, "\n");
			}
			i++;
			j++;
		}
		fclose(writeFile);
	}
	else if (food[0].getName() == "����") {
		FILE* writeFile = fopen("fish.txt", "w");
		int i = 0, j = 1;
		while (i < food.size()) {
			fprintf(writeFile, food[i].getName().c_str());
			fprintf(writeFile, " ");
			fprintf(writeFile, food[i].getRecipe().c_str());
			if (j < food.size()) {
				fprintf(writeFile, "\n");
			}
			i++;
			j++;
		}
		fclose(writeFile);
	}
	else if (food[0].getName() == "����") { //veget[0].getName()
		FILE* writeFile = fopen("veget.txt", "w");
		int i = 0, j = 1;
		while (i < food.size()) {  //ù ������ �Է� -> ���� -> �������Է� -> ... -> ���� -> �������Է�    ,,,,,, ������ �ѹ� �� ����ߵż� j=1�� ��.
			fprintf(writeFile, food[i].getName().c_str());
			if (j < food.size()) {
				fprintf(writeFile, "\n");
			}
			i++;
			j++;
		}
		fclose(writeFile);
	}
	else if (food[0].getName() == "���") {
		FILE* writeFile = fopen("sauce.txt", "w");
		int i = 0, j = 1;
		while (i < food.size()) {
			fprintf(writeFile, food[i].getName().c_str());
			if (j < food.size()) {
				fprintf(writeFile, "\n");
			}
			i++;
			j++;
		}
		fclose(writeFile);
	}
	else if (food[0].getName() == "����") {
		FILE* writeFile = fopen("drink.txt", "w");
		int i = 0, j = 1;
		while (i < food.size()) {
			fprintf(writeFile, food[i].getName().c_str());
			if (j < food.size()) {
				fprintf(writeFile, "\n");
			}
			i++;
			j++;
		}
		fclose(writeFile);
	}
	else if (food[0].getName() == "�ڷº�") {
		FILE* writeFile = fopen("other.txt", "w");
		int i = 0;
		int j = 1;
		while (i < food.size()) {
			fprintf(writeFile, food[i].getName().c_str());
			if (j < food.size()) {
				fprintf(writeFile, "\n");
			}
			i++;
			j++;
		}
		fclose(writeFile);
	}
	return;
} // �Է��ؼ� ���°� �ƴ϶� else ó�� ������. 

void readInFile(vector<Food>& food) { // ���Ͽ� ����� �ش� ������� ��� �ܼ�â�� ���
	int i = 0;
	if (food[0].getName() == "�ҵ��") {
		FILE* readFile = fopen("meat.txt", "r"); //r �� �б���
		while (i < food.size()) {
			int sizeName = food[i].getName().size();
			int sizeRecipe = food[i].getRecipe().size();
			char name[50], recipe[50];
			fgets(name, sizeName + 2, readFile);
			printf("%s", name);
			fgets(recipe, sizeRecipe + 2, readFile);
			printf("%s", recipe);
			i++;
		}
	}
	else if (food[0].getName() == "����") {
		FILE* readFile = fopen("fish.txt", "r");
		while (i < food.size()) {
			int sizeName = food[i].getName().size();
			int sizeRecipe = food[i].getRecipe().size();
			char name[20], recipe[50];
			fgets(name, sizeName + 2, readFile);
			printf("%s", name);
			fgets(recipe, sizeRecipe + 2, readFile);
			printf("%s", recipe);
			i++;
		}
	}
	else if (food[0].getName() == "����") {
		FILE* readFile = fopen("veget.txt", "r");
		while (i < food.size()) {
			int sizeName = food[i].getName().size();
			char name[20];
			fgets(name, sizeName + 2, readFile);
			printf("%s", name);

			i++;
		}
	}
	else if (food[0].getName() == "���") {
		FILE* readFile = fopen("sauce.txt", "r");
		while (i < food.size()) {
			int sizeName = food[i].getName().size();
			char name[20];
			fgets(name, sizeName + 2, readFile);
			printf("%s", name);

			i++;
		}
	}
	else if (food[0].getName() == "����") {
		FILE* readFile = fopen("drink.txt", "r");
		while (i < food.size()) {
			int sizeName = food[i].getName().size();
			char name[20];
			fgets(name, sizeName + 2, readFile);
			printf("%s", name);

			i++;
		}
	}
	else if (food[0].getName() == "�ڷº�") {
		FILE* readFile = fopen("other.txt", "r");
		while (i < food.size()) {
			int sizeName = food[i].getName().size();
			char name[20];
			fgets(name, sizeName + 2, readFile); // \n �� ũ��� 2
			printf("%s", name);

			i++;
		}
	}
	cout << endl;
	return;
}

void init(vector<Food>& food, string s) { //s�� �´� ����� ������� �ʱ�ȭ�� ex) init(food, "����") ---> meat.txt�� �ۼ��� ������� food ���Ͱ� �ʱ�ȭ��.

	if (s == "����") {
		FILE* readFile = NULL;
		readFile = fopen("meat.txt", "r");
		if (readFile != NULL) {
			char buf[2048];
			while (!feof(readFile)) {
				fgets(buf, sizeof(buf), readFile);

				char name[32];
				char recipe1[32];
				char recipe2[32];
				char recipe3[32];

				char* ptr = strtok(buf, " ");
				strcpy(name, ptr);

				ptr = strtok(NULL, " ");
				strcpy(recipe1, ptr);

				ptr = strtok(NULL, " ");
				strcpy(recipe2, ptr);

				ptr = strtok(NULL, "\n");
				strcpy(recipe3, ptr);

				Food new_food(name, recipe1, recipe2, recipe3);
				food.push_back(new_food);
			}
		}
	}
	if (s == "���") {
		FILE* readFile = NULL;
		readFile = fopen("fish.txt", "r");
		if (readFile != NULL) {
			char buf[2048];
			while (!feof(readFile)) {
				fgets(buf, sizeof(buf), readFile);

				char name[32];
				char recipe1[32];
				char recipe2[32];
				char recipe3[32];

				char* ptr = strtok(buf, " ");
				strcpy(name, ptr);
				ptr = strtok(NULL, " ");
				strcpy(recipe1, ptr);
				ptr = strtok(NULL, " ");
				strcpy(recipe2, ptr);
				ptr = strtok(NULL, "\n");
				strcpy(recipe3, ptr);
				Food new_food(name, recipe1, recipe2, recipe3);
				food.push_back(new_food);
			}
		}
	}
	if (s == "ä��") {
		FILE* readFile = NULL;
		readFile = fopen("veget.txt", "r");
		if (readFile != NULL) {
			char buf[2048];
			while (!feof(readFile)) {
				fgets(buf, sizeof(buf), readFile);

				char name[32];

				char* ptr = strtok(buf, "\n");
				strcpy(name, ptr);
				Food new_food(name);
				food.push_back(new_food);
			}
		}
	}
	if (s == "�ҽ�") {
		FILE* readFile = NULL;
		readFile = fopen("sauce.txt", "r");
		if (readFile != NULL) {
			char buf[2048];
			while (!feof(readFile)) {
				fgets(buf, sizeof(buf), readFile);

				char name[32];

				char* ptr = strtok(buf, "\n");
				strcpy(name, ptr);
				Food new_food(name);
				food.push_back(new_food);
			}
		}
	}
	if (s == "����") {
		FILE* readFile = NULL;
		readFile = fopen("drink.txt", "r");
		if (readFile != NULL) {
			char buf[2048];
			while (!feof(readFile)) {
				fgets(buf, sizeof(buf), readFile);

				char name[32];

				char* ptr = strtok(buf, "\n");
				strcpy(name, ptr);
				Food new_food(name);
				food.push_back(new_food);
			}
		}
	}
	if (s == "��Ÿ") {
		FILE* readFile = NULL;
		readFile = fopen("other.txt", "r");
		if (readFile != NULL) {
			char buf[2048];
			while (!feof(readFile)) {
				fgets(buf, sizeof(buf), readFile);

				char name[32];

				char* ptr = strtok(buf, "\n");
				strcpy(name, ptr);
				Food new_food(name);
				food.push_back(new_food);
			}
		}
	}

}

//int main(void)
//{
//	vector<Food> meat = {
//		Food("�ҵ��", "������ũ", "����", "�Ұ��"), Food("�Ҹ��", "��", "������", "�Ұ��"), Food("�Ҿմٸ�", "��ȸ", "��Ʃ", "��"), Food("�Ұ���", "�Ұ���", "��", "��"), Food("�Ҿ���", "��", "�", "������"),
//		Food("�һ���", "��ȸ", "��", "��"), Food("�ҿ��", "����", "������", "�Ұ��"), Food("����","����","������", "����"), Food("ä��", "������ũ", "����", "�������"), Food("�Ƚ�", "����", "����"),
//		Food("�������", "����", "����", "��ġ�"), Food("�������", "������", "������", "��ä"), Food("�����Ƚ�", "������", "��ġ����", "������"), Food("��������", "������", "��䰥��"), Food("���� �մٸ���", "�Ұ��", "�", "��"),
//		Food("����", "������", "����", "�Ұ��"), Food("���� �޴ٸ���", "����", "����", "������"), Food("���� ����", "������", "�", "����"), Food("���� ������", "����"), Food("���� ���긮��", "����"),
//		Food("���", "���", "�����", "�뱸��"), Food("�߰�����", "��", "����", "����"), Food("�� �Ƚ�", "��", "Ƣ��"), Food("�ߴٸ�", "�ٺ�ť", "����", "��"), Food("�� ����", "����", "����", "Ƣ��"),
//		Food("�� ���ָӴ�", "����", "����", "��ġ����"), Food("�߹�", "����"), Food("�����", "��", "���", "���챸��"), Food("����������", "������ũ", "������", "��䱸��"), Food("���� ���", "�ֹ���", "����"), Food("���� ����", "Ƣ��", "����", "���챸��"),
//		Food("���� �Ƚ�", "�ֹ���", "����", "����"), Food("�� ���", "��Ʃ", "��", "��"), Food("�� �������", "Ƣ��", "����"), Food("�� �Ƚ�", "������ũ" ,"��ġ"), Food("�� ���", "������ũ", "��ġ"),
//		Food("�� �����", "����", "�������", "�Ұ��"), Food("�� ���", "����", "�߱��丮"), Food("�� �ٸ���", "����", "Ƣ��", "����"), Food("�� �����", "������ũ","����","����"), Food("�� �����", "����", "��"),
//		Food("�� ������", "����", "��ġ", "����"), Food("�� �մٸ���", "����", "��", "��"), Food("�� �޴ٸ���", "����", "����", "ī��"), Food("�� ����", "������ũ", "��ȸ"), Food("�� ��û�", "����", "����", "��ġ")
//	};
//	vector<Food> fish = { Food("����","�","��"), Food("����","�","��","��"), Food("�Ͼ�"), Food("����"), Food("��ġ","����","����"),Food("���ڹ�","����","����"),Food("����","����","����"), Food("��ġ","ȸ","������","�ָԹ�"), Food("����"),Food("����"),Food("��¡��","��","����","����"),Food("����","������","Ƣ��"),Food("����","����","������","����"), Food("����","������","Ƣ��"),Food("����","����","����"),Food("����","��ȸ","����","��ȸ"),Food("���","����","����"),Food("�췰","ȸ","�ſ���","����"),Food("����","ȸ","����","������ũ"),Food("�ػ�","��ȸ","��","��"),Food("ȫ��","ȸ","��ħ","����"),Food("��ġ","����","����"),Food("�Ʊ�","�Ʊ���"),Food("����","����","��"),Food("��ġ","����"),Food("����","����"),Food("��ø","��ø��"),Food("����","��","Į����"),Food("�������","��","��","��ȸ"),Food("������","Į����","���κ��","�̿���"),Food("������","����","��ħ","����"),Food("������","ȸ","����","��"),Food("ȫ��","��","��"),Food("����������","����","�����丮","����"),Food("����","����","�����丮","��"),Food("Ű����","�������","����","ȸ"),Food("����","��䲿��","��ħ","�����"),Food("����","��������","���ͱ���","������"),Food("�췷��","���屹","�����","�ʹ�ħ"),Food("��","������","�������","��") };
//	vector<Food> vegetable = { Food("����"),Food("����"),Food("��"),Food("������"),Food("���ä"),Food("����"),Food("��縮"),Food("����"),Food("����"), Food("��ä"), Food("���"), Food("����"), Food("����"), Food("������"), Food("����"), Food("�Ѷ�λ�"), Food("����"), Food("����"), Food("��"), Food("�̳���"), Food("����"), Food("����"), Food("����"), Food("����"), Food("����ݸ�"), Food("��Ʈ"), Food("����"), Food("����"), Food("���ֳ���"), Food("����"), Food("�ñ�ġ"), Food("�ż���"), Food("����"), Food("����"), Food("��"), Food("����"), Food("�ƺ�ī��"), Food("�ƽ��Ķ�Ž�"), Food("�ƿ�"), Food("��ȣ��"), Food("�����"), Food("�����"), Food("����"), Food("����"), Food("����"), Food("���"), Food("�λ�"), Food("��ä"), Food("�׼�"), Food("û��ä"), Food("ġĿ��"), Food("�ݶ��"), Food("�ᳪ��"), Food("������ī"), Food("ȣ��"), Food("��Ÿ������"), Food("�����̹���"), Food("���̹���"), Food("����̹���"), Food("���̹���"), Food("ǥ�����") };
//	vector<Food> sauce = { Food("���"),Food("������"),Food("���尡��"),Food("������"),Food("����"),Food("�����"),Food("��Ÿ�ٰ�"),Food("��ġ����"),Food("����"),Food("����"),Food("�긶��"),Food("������"),Food("����"),Food("������"),Food("�ұ�"),Food("�Ŀ��"),Food("����"),Food("����"),Food("��Ƽ��ũ"),Food("������"),Food("Ÿ��"),Food("�Ľ���"),Food("����"),Food("���ҽ�"),Food("�����������"),Food("�����Ұ����"),Food("�߰�����"),Food("�ߺ��������"),Food("�Ұ�����") };
//	vector<Food> drink = { Food("����"), Food("�̿�����"), Food("�꽺"), Food("����"), Food("����ǰ") };
//	vector<Food> other = {
//		Food("�а��� �ڷº�"), Food("�а��� �߷º�"), Food("�а��� ���º�"), Food("�Ҹ�"), Food("���"), Food("Į������"), Food("�и�"), Food("�ø�"), Food("�̸�"), Food("�޹и�")
//	};
//	meat[0].CheckAll();
//	meat[1].CheckAll();
//
//	ShowAllFood(meat);
//	return 0;
//}