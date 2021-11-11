#include "add.h"
#include "food.h"
#include "home.h"

bool add()
{
	system("cls");
	int key;
	string a;
	string r1, r2, r3;
	int i;
	cout << "추가할 재료와 번호를 입력하세요 ( 1:고기 2:생선 3:채소 4:음료 5:소스 6:그 외) ";
	cin >> a >> i;
	if (a == "x" || a == "X") { //수정해야됨.
		return false;
	}
	if (i == 1)
	{
		if (!(isexist_meat(a)))
		{
			FILE* writeFile = fopen("meat.txt", "a");
			cout << "첫번째 레시피를 입력하세요 (없다면 x를 입력하세요): ";
			cin >> r1;
			cout << "두번째 레시피를 입력하세요 (없다면 x를 입력하세요): ";
			cin >> r2;
			cout << "세번째 레시피를 입력하세요 (없다면 x를 입력하세요): ";
			cin >> r3;
			fprintf(writeFile, "\n");
			fprintf(writeFile, a.c_str());
			fprintf(writeFile, " ");
			fprintf(writeFile, r1.c_str());
			fprintf(writeFile, " ");
			fprintf(writeFile, r2.c_str());
			fprintf(writeFile, " ");
			fprintf(writeFile, r3.c_str());	
			fclose(writeFile);
			cout << "성공적으로 입력됐습니다.";
			Sleep(1000);
			return true;
		}
		else
		{
			cout << "이미 존재하는 식재료 입니다.\n";
			Sleep(1000);
			return true;
		}

	}
	else if (i == 2)
	{
		if (!(isexist_fish(a)))
		{
			FILE* writeFile = fopen("fish.txt", "a");
			cout << "첫번째 레시피를 입력하세요 (없다면 x를 입력하세요): ";
			cin >> r1;
			cout << "두번째 레시피를 입력하세요 (없다면 x를 입력하세요): ";
			cin >> r2;
			cout << "세번째 레시피를 입력하세요 (없다면 x를 입력하세요): ";
			cin >> r3;
			fprintf(writeFile, "\n");
			fprintf(writeFile, a.c_str());
			fprintf(writeFile, " ");
			fprintf(writeFile, r1.c_str());
			fprintf(writeFile, " ");
			fprintf(writeFile, r2.c_str());
			fprintf(writeFile, " ");
			fprintf(writeFile, r3.c_str());
			fclose(writeFile);
			cout << "성공적으로 입력됐습니다.";
			Sleep(1000);
			return true;
		}
		else
		{
			cout << "이미 존재하는 식재료 입니다.\n";
			Sleep(1000);
			return true;
		}
	}
	else if (i == 3)
	{
		if (!(isexist_veget(a)))
		{
			FILE* writeFile = fopen("veget.txt", "a");
			fprintf(writeFile, "\n");
			fprintf(writeFile, a.c_str());
			fclose(writeFile);
			cout << "성공적으로 입력됐습니다.";
			Sleep(1000);
			return true;
		}
		else
		{
			cout << "이미 존재하는 식재료 입니다.\n";
			Sleep(1000);
			return true;
		}
	}
	else if (i == 4)
	{
		if (!(isexist_drink(a)))
		{
			FILE* writeFile = fopen("drink.txt", "a");
			fprintf(writeFile, "\n");
			fprintf(writeFile, a.c_str());
			fclose(writeFile);
			cout << "성공적으로 입력됐습니다.";
			Sleep(1000);
			return true;
		}
		else
		{
			cout << "이미 존재하는 식재료 입니다.\n";
			Sleep(1000);
			return true;
		}
	}
	else if (i == 5)
	{
		if (!(isexist_sauce(a)))
		{
			FILE* writeFile = fopen("sauce.txt", "a");
			fprintf(writeFile, "\n");
			fprintf(writeFile, a.c_str());
			fclose(writeFile);
			cout << "성공적으로 입력됐습니다.";
			Sleep(1000);
			return true;
		}
		else
		{
			cout << "이미 존재하는 식재료 입니다.\n";
			Sleep(1000);
			return true;
		}
	}
	else if (i == 5)
	{
		if (!(isexist_other(a)))
		{
			FILE* writeFile = fopen("other.txt", "a");
			fprintf(writeFile, "\n");
			fprintf(writeFile, a.c_str());
			fclose(writeFile);
			cout << "성공적으로 입력됐습니다.";
			Sleep(1000);
			return true;
		}
		else
		{
			cout << "이미 존재하는 식재료 입니다.\n";
			Sleep(1000);
			return true;
		}
	}
	else
	{
		cout << "잘못된 종류입니다\n";
		return true;
	}
}

bool isexist_meat(string s)
{
	FILE* readFile = fopen("meat.txt", "r"); //r 은 읽기모드
	if (readFile != NULL)
	{
		char buf[2048];
		while (!feof(readFile))
		{
			fgets(buf, sizeof(buf), readFile);
			char name[32];


			char* ptr = strtok(buf, " ");
			strcpy(name, ptr);
			if (name == s)
			{
				return true;
			}
		}
	}
	return false;
}

bool isexist_fish(string s)
{
	FILE* readFile = fopen("fish.txt", "r"); //r 은 읽기모드
	if (readFile != NULL)
	{
		char buf[2048];
		while (!feof(readFile))
		{
			fgets(buf, sizeof(buf), readFile);
			char name[32];


			char* ptr = strtok(buf, " ");
			strcpy(name, ptr);
			if (name == s)
			{
				return true;
			}
		}
	}
	return false;
}

bool isexist_veget(string s)
{
	FILE* readFile = fopen("veget.txt", "r"); //r 은 읽기모드
	if (readFile != NULL)
	{
		char buf[2048];
		while (!feof(readFile))
		{
			fgets(buf, sizeof(buf), readFile);
			char name[32];


			char* ptr = strtok(buf, " ");
			strcpy(name, ptr);
			if (name == s)
			{
				return true;
			}
		}
	}
	return false;
}

bool isexist_drink(string s)
{
	FILE* readFile = fopen("drink.txt", "r"); //r 은 읽기모드
	if (readFile != NULL)
	{
		char buf[2048];
		while (!feof(readFile))
		{
			fgets(buf, sizeof(buf), readFile);
			char name[32];


			char* ptr = strtok(buf, " ");
			strcpy(name, ptr);
			if (name == s)
			{
				return true;
			}
		}
	}
	return false;
}

bool isexist_sauce(string s)
{
	FILE* readFile = fopen("sauce.txt", "r"); //r 은 읽기모드
	if (readFile != NULL)
	{
		char buf[2048];
		while (!feof(readFile))
		{
			fgets(buf, sizeof(buf), readFile);
			char name[32];


			char* ptr = strtok(buf, " ");
			strcpy(name, ptr);
			if (name == s)
			{
				return true;
			}
		}
	}
	return false;
}

bool isexist_other(string s)
{
	FILE* readFile = fopen("other.txt", "r"); //r 은 읽기모드
	if (readFile != NULL)
	{
		char buf[2048];
		while (!feof(readFile))
		{
			fgets(buf, sizeof(buf), readFile);
			char name[32];


			char* ptr = strtok(buf, " ");
			strcpy(name, ptr);
			if (name == s)
			{
				return true;
			}
		}
	}
	return false;
}

bool isexist_freeze(string s)
{
	FILE* readFile = fopen("freeze.txt", "r"); //r 은 읽기모드
	if (readFile != NULL)
	{
		char buf[2048];
		while (!feof(readFile))
		{
			fgets(buf, sizeof(buf), readFile);
			char name[32];


			char* ptr = strtok(buf, " ");
			strcpy(name, ptr);
			if (name == s)
			{
				return true;
			}
		}
	}
	return false;
}

bool isexist_room(string s)
{
	FILE* readFile = fopen("room.txt", "r"); //r 은 읽기모드
	if (readFile != NULL)
	{
		char buf[2048];
		while (!feof(readFile))
		{
			fgets(buf, sizeof(buf), readFile);
			char name[32];


			char* ptr = strtok(buf, " ");
			strcpy(name, ptr);
			if (name == s)
			{
				return true;
			}
		}
	}
	return false;
}

bool isexist_refri(string s)
{
	FILE* readFile = fopen("refrigeration.txt", "r"); //r 은 읽기모드
	if (readFile != NULL)
	{
		char buf[2048];
		while (!feof(readFile))
		{
			fgets(buf, sizeof(buf), readFile);
			char name[32];


			char* ptr = strtok(buf, " ");
			strcpy(name, ptr);
			if (name == s)
			{
				return true;
			}
		}
	}
	return false;
}