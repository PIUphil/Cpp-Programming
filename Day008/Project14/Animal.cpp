#include <iostream>
#include <cstring>
//#include <string>
using namespace std;
#pragma warning(disable:4996)

struct Animal {
	char name[30];		// 이름
	//string name;
	int age;			// 나이
	int health;			// 체력
	int food;			// 포만도
	int clean;			// 청결도
};

void create_animal(Animal* animal) {
	cout << "동물 이름 = ";
	cin >> animal->name;
	
	cout << "동물 나이 = ";
	cin >> animal->age;

	animal->food = 100;
	animal->clean = 100;
	animal->health = 100;
}

void play(Animal* animal) {
	animal->health += 10;
	animal->food -= 20;
	animal->clean -= 30;
}

void one_day_pass(Animal* animal) {
	// 하루가 지나면
	animal->health -= 10;
	animal->food -= 30;
	animal->clean -= 20;
}

void show(Animal* animal) {
	cout << animal->name << "의 상태 : " << endl;
	cout << "체력 : " << animal->health << endl;
	cout << "청결 : " << animal->clean << endl;
	cout << "배부름 : " << animal->food << endl << endl;
}

int main() {
	// 구조체 포인터 배열
	Animal* list[10];
	int animal_num = 0;

	//for (;;) {
	while (true) {
		cout << "1. 동물 추가하기" << endl;
		cout << "2. 놀기" << endl;
		cout << "3. 상태보기" << endl;
		cout << "4. 종료" << endl;

		int menu;
		cout << "선택 = ";
		cin >> menu;
		
		switch (menu) {
			int play_with;

		case 1: {
			list[animal_num] = new Animal;
			create_animal(list[animal_num++]);
			break; }

		case 2: {
			cout << "누구랑 놀게? = ";
			cin >> play_with;
			if (play_with < animal_num)
				play(list[play_with]);
			break; }

		case 3: {
			cout << "누구꺼 보게? = ";
			cin >> play_with;
			if (play_with < animal_num)
				show(list[play_with]);
			break; }

		case 4: {
			cout << "작업을 종료합니다.\n";
			return 0; }
		}

		// 하루가 지났다.
		for (int i = 0; i < animal_num; i++)
			one_day_pass(list[i]);
	}

	// 동적할당받은 메모리를 반환
	for (int i = 0; i < animal_num; i++)
		delete list[i];

	return 0;
}