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

void Food::setName(string name) // 이름 세터
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
				cout << getName() << "의 일을 다시 입력하시오(1~" << days << ")\n" << endl;
				return;
			}

		}
		else {
			cout << getName() << "의 월을 다시 입력하시오(1~12)\n" << endl;
			return;
		}
	}
	else {
		cout << getName() << "의 년을 다시 입력하시오(" << thisYear << "~)\n" << endl;
		return;
	}
}

void Food::setMakeFood() {
	cout << getName() << "으로 만들 수 있는 음식 목록을 재설정합니다.";
	cin >> recipe[0] >> recipe[1] >> recipe[2];
}

void Food::setState() {
	string state;
	cout << getName() << "의 보관상태를 입력하시오 : ";
	cin >> state;
	while (1) {
		if (state == "상온" || state == "냉장" || state == "냉동")
		{
			this->state = state;   return;
		}
		else {  //세가지 상태에 해당 안되면 재입력.
			cout << "재입력 : ";
			cin >> state;
		}
	}
}

void Food::setState1(string state) { // 현황판에 보이기 위해 작성
	if (state == "냉장" || state == "냉동" || state == "상온")
	{
		this->state = state;
		return;
	}
	else {
		cout << "보관상태 재입력: ";
		cin >> state;
	}
}

void Food::showLeftDate() {
	if (state == "미") //현재 사용자의 냉장고에 미보관이면 유통기한 출력X
		return;
	time_t shelfdate, today;
	double diff; //유통기한과 현재시각 비교
	int day; //비교 후 남은 일수 넣음
	struct tm user_stime; //현재시각 넣을 곳
	user_stime.tm_year = f_year - 1900;
	user_stime.tm_mon = f_month - 1;
	user_stime.tm_mday = f_day;
	user_stime.tm_hour = 0, user_stime.tm_min = 0, user_stime.tm_sec = 0, user_stime.tm_isdst = 0;
	shelfdate = mktime(&user_stime); //유통기한
	time(&today); //현재시각
	diff = difftime(shelfdate, today);
	day = diff / (60 * 60 * 24); //남은 날

	cout << getName() << "의 유통기한은 " << day << "일 남았습니다." << endl;
}

void Food::showState() {
	cout << "현재 " << getState() << "보관 중입니다." << endl;
}

void Food::showMakeFood() {
	cout << getName() << "으로 만들 수 있는 음식은 " << getRecipe() << endl;
}//만들 수 있는 음식

//보관 중인 해당 식재료의 이름, 보관상태, 유통기한 한번에 보여줌.
void Food::CheckAll() {
	showMakeFood();
	showLeftDate();
	showState();
	cout << endl;
}

//해당 Food목록의 전체 식재료명 출력
void ShowAllFood(vector<Food>& food) {
	for (Food a : food) {
		cout << a.getName() << endl;
	}
}

void addData(vector<Food>& food) { //vector<Food>& food 에 추가할 때
	while (1) {
		if (food[0].getName() == "소등심" || food[0].getName() == "생태") { //레시피까지 입력해야하는 육류, 어류
			string name = "";
			string recipe1 = "";
			string recipe2 = "";
			string recipe3 = "";
			cout << "이름(q입력시 종료): ";
			cin >> name;
			if (name == "q") {
				writeInFile(food);
				return;
			}
			cout << "레시피 입력 ";
			cin >> recipe1 >> recipe2 >> recipe3;
			addIn(food, name, recipe1, recipe2, recipe3);
		}
		else { //레시피 입력 안해도 되는 채소, 음료, 소스, etc
			string name = "";
			cout << "이름(q입력시 종료): ";
			cin >> name;
			if (name == "q") {
				writeInFile(food);
				return;
			}
			addIn(food, name);
		}
	}
}

void addIn(vector<Food>& food, string name, string r1, string r2, string r3) // 하나의 식재료 추가
{
	food.push_back(Food(name, r1, r2, r3)); //식재료 추가	
	writeInFile(food);
}

void addIn(vector<Food>& food, string name) // 하나의 식재료 추가
{
	food.push_back(Food(name)); //식재료 추가	
	writeInFile(food);
}

//파일에 미리 입력된 데이터 외에 추가할 때 사용됨.
void writeInFile(vector<Food>& food) { // txt파일들에 식재료들 write
	if (food[0].getName() == "육류") {
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
	else if (food[0].getName() == "어류") {
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
	else if (food[0].getName() == "채소") { //veget[0].getName()
		FILE* writeFile = fopen("veget.txt", "w");
		int i = 0, j = 1;
		while (i < food.size()) {  //첫 데이터 입력 -> 개행 -> 데이터입력 -> ... -> 개행 -> 데이터입력    ,,,,,, 개행을 한번 덜 해줘야돼서 j=1로 둠.
			fprintf(writeFile, food[i].getName().c_str());
			if (j < food.size()) {
				fprintf(writeFile, "\n");
			}
			i++;
			j++;
		}
		fclose(writeFile);
	}
	else if (food[0].getName() == "소스") {
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
	else if (food[0].getName() == "음료") {
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
	else if (food[0].getName() == "그외") {
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
	else if (food[0].getName() == "냉장") {
		FILE* writeFile = fopen("refrigeration.txt", "w");
		int i = 0;
		int j = 1;
		while (i < food.size()) {
			fprintf(writeFile, food[i].getName().c_str());
			if (food[i].getRecipe() != "")
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
	else if (food[0].getName() == "냉동") {
		FILE* writeFile = fopen("freeze.txt", "w");
		int i = 0;
		int j = 1;
		while (i < food.size()) {
			fprintf(writeFile, food[i].getName().c_str());
			if (food[i].getRecipe() != "")
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
	else if (food[0].getName() == "상온") {
		FILE* writeFile = fopen("room.txt", "w");
		int i = 0;
		int j = 1;
		while (i < food.size()) {
			fprintf(writeFile, food[i].getName().c_str());
			if (food[i].getRecipe() != "")
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
	return;
} // 입력해서 쓰는게 아니라 else 처리 안해줌. 

void readInFile(vector<Food>& food) { // 파일에 저장된 해당 식재료의 목록 콘솔창에 출력
	int i = 0;
	if (food[0].getName() == "소등심") {
		FILE* readFile = fopen("meat.txt", "r"); //r 은 읽기모드
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
	else if (food[0].getName() == "생태") {
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
	else if (food[0].getName() == "가지") {
		FILE* readFile = fopen("veget.txt", "r");
		while (i < food.size()) {
			int sizeName = food[i].getName().size();
			char name[20];
			fgets(name, sizeName + 2, readFile);
			printf("%s", name);

			i++;
		}
	}
	else if (food[0].getName() == "고수") {
		FILE* readFile = fopen("sauce.txt", "r");
		while (i < food.size()) {
			int sizeName = food[i].getName().size();
			char name[20];
			fgets(name, sizeName + 2, readFile);
			printf("%s", name);

			i++;
		}
	}
	else if (food[0].getName() == "우유") {
		FILE* readFile = fopen("drink.txt", "r");
		while (i < food.size()) {
			int sizeName = food[i].getName().size();
			char name[20];
			fgets(name, sizeName + 2, readFile);
			printf("%s", name);

			i++;
		}
	}
	else if (food[0].getName() == "박력분") {
		FILE* readFile = fopen("other.txt", "r");
		while (i < food.size()) {
			int sizeName = food[i].getName().size();
			char name[20];
			fgets(name, sizeName + 2, readFile); // \n 의 크기는 2
			printf("%s", name);

			i++;
		}
	}
	cout << endl;
	return;
}

void init(vector<Food>& food, string s) { //s에 맞는 식재료 목록으로 초기화함 ex) init(food, "육류") ---> meat.txt에 작성된 식재료들로 food 벡터가 초기화됨.
	food.clear();
	if (s == "육류") {
		FILE* readFile = NULL;
		readFile = fopen("meat.txt", "r");
		if (readFile != NULL) {
			char buf[1024];
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
	if (s == "어류") {
		FILE* readFile = NULL;
		readFile = fopen("fish.txt", "r");
		if (readFile != NULL) {
			char buf[1024];
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
	if (s == "채소") {
		FILE* readFile = NULL;
		readFile = fopen("veget.txt", "r");
		if (readFile != NULL) {
			char buf[1024];
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
	if (s == "소스") {
		FILE* readFile = NULL;
		readFile = fopen("sauce.txt", "r");
		if (readFile != NULL) {
			char buf[1024];
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
	if (s == "음료") {
		FILE* readFile = NULL;
		readFile = fopen("drink.txt", "r");
		if (readFile != NULL) {
			char buf[1024];
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
	if (s == "기타") {
		FILE* readFile = NULL;
		readFile = fopen("other.txt", "r");
		if (readFile != NULL) {
			char buf[1024];
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

	// 냉장, 냉동, 상온 현황에 보이기 위해 추가
	if (s == "냉장") { // refrigeration
		FILE* readFile = NULL;
		readFile = fopen("refrigeration.txt", "r");
		if (readFile != NULL) {

			char buf[1024];

			char name[32];
			fgets(buf, sizeof(buf), readFile);
			char* ptr = strtok(buf, "\n"); //- 냉장 받는 부분
			strcpy(name, ptr);

			Food new_food(name);
			new_food.setState1("냉장");
			food.push_back(new_food);

			while (!feof(readFile)) { // eof까지 반복
				fgets(buf, sizeof(buf), readFile);

				char name[32];
				char recipe1[32] = { 0, };
				char recipe2[32] = { 0, };
				char recipe3[32] = { 0, };

				char* ptr = strtok(buf, " \n");
				strcpy(name, ptr);

				ptr = strtok(NULL, " ");
				if (ptr != NULL)
				{ // 문자열의 끝까지

					strcpy(recipe1, ptr);

					ptr = strtok(NULL, " ");
					strcpy(recipe2, ptr);

					ptr = strtok(NULL, "\n");
					strcpy(recipe3, ptr);
				}


				if (recipe1[0] != 0)
				{ // 육류, 어류같이 recipe이 있으면
					Food new_food(name, recipe1, recipe2, recipe3);
					new_food.setState1("냉장");
					food.push_back(new_food);
				}
				else // recipe이 없으면
				{
					Food new_food(name);
					new_food.setState1("냉장");
					food.push_back(new_food);
				}

			}
		}
	}

	if (s == "냉동") { // freeze
		FILE* readFile = NULL;
		readFile = fopen("freeze.txt", "r");
		if (readFile != NULL) {

			char buf[1024];

			char name[32];
			fgets(buf, sizeof(buf), readFile);
			char* ptr = strtok(buf, "\n"); //- 냉동 받는 부분
			strcpy(name, ptr);

			Food new_food(name);
			new_food.setState1("냉동");
			food.push_back(new_food);

			while (!feof(readFile)) { // eof까지 반복
				fgets(buf, sizeof(buf), readFile);

				char name[32];
				char recipe1[32] = { 0, };
				char recipe2[32] = { 0, };
				char recipe3[32] = { 0, };

				char* ptr = strtok(buf, " \n");
				strcpy(name, ptr);

				ptr = strtok(NULL, " ");
				if (ptr != NULL)
				{ // 문자열의 끝까지

					strcpy(recipe1, ptr);

					ptr = strtok(NULL, " ");
					strcpy(recipe2, ptr);

					ptr = strtok(NULL, "\n");
					strcpy(recipe3, ptr);
				}


				if (recipe1[0] != 0)
				{ // 육류, 어류같이 recipe이 있으면
					Food new_food(name, recipe1, recipe2, recipe3);
					new_food.setState1("냉동");
					food.push_back(new_food);
				}
				else // recipe이 없으면
				{
					Food new_food(name);
					new_food.setState1("냉동");
					food.push_back(new_food);
				}

			}
		}
	}

	if (s == "상온") { // room
		FILE* readFile = NULL;
		readFile = fopen("room.txt", "r");
		if (readFile != NULL) {

			char buf[1024];

			char name[32];
			fgets(buf, sizeof(buf), readFile);
			char* ptr = strtok(buf, "\n"); //- 상온 받는 부분
			strcpy(name, ptr);

			Food new_food(name);
			new_food.setState1("상온");
			food.push_back(new_food);

			while (!feof(readFile)) { // eof까지 반복
				fgets(buf, sizeof(buf), readFile);

				char name[32];
				char recipe1[32] = { 0, };
				char recipe2[32] = { 0, };
				char recipe3[32] = { 0, };

				char* ptr = strtok(buf, " \n");
				strcpy(name, ptr);

				ptr = strtok(NULL, " ");
				if (ptr != NULL)
				{ // 문자열의 끝까지

					strcpy(recipe1, ptr);

					ptr = strtok(NULL, " ");
					strcpy(recipe2, ptr);

					ptr = strtok(NULL, "\n");
					strcpy(recipe3, ptr);
				}


				if (recipe1[0] != 0)
				{ // 육류, 어류같이 recipe이 있으면
					Food new_food(name, recipe1, recipe2, recipe3);
					new_food.setState1("상온");
					food.push_back(new_food);
				}
				else // recipe이 없으면
				{
					Food new_food(name);
					new_food.setState1("상온");
					food.push_back(new_food);
				}

			}
		}
	}
}
