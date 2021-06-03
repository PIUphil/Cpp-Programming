#include <iostream>
#include <cstring>
using namespace std;
#pragma warning (disable:4996)


class Person {
private:
	char* name;		// 동적할당
	int age;

public:
	Person() {
		name = NULL;
		age = 0;
	}

	Person(char* curName, int curAge) {
		age = curAge;
		name = new char[strlen(curName)+1];
		strcpy(name, curName);
	}

	void setPerson(char* curName, int curAge) {
		age = curAge;
		name = new char[strlen(curName) + 1];
		strcpy(name, curName);
	}

	void setName(char* curName) {
		name = curName;
	}

	char* getName() {
		return name;
	}

	void setAge(int age) {
		this->age = age;
	}

	int getAge() {
		return age;
	}

	void showPerson() {
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl << endl;
	}

	~Person() {
		delete[] name;					// 동적할당 반환
		cout << "소멸자 호출" << endl;
	}
};

int main() {
	Person arr[3];			// 객체 배열
	char curName[100];		// 영문자 99자, 한글 49자
	char* str;
	int age;
	int len;

	for (int i = 0; i < 3; i++) {
		cout << "이름 = ";
		cin >> curName;
		cout << "나이 = ";
		cin >> age;

		len = strlen(curName) + 1;
		str = new char[len];
		strcpy(str, curName);

		arr[i].setPerson(str, age);
	}

	for (int i = 0; i < 3; i++) {
		arr[i].showPerson();
	}
	return 0;
}


/*
int main() {
	Person arr[3];		// 객체 배열
	// Person* ptr[100];		// 객체 포인터배열

	//Person *p, *q, *r;			// 포인터변수
	Person* ptr[3];
	//p = arr;			// &arr[0]
	/*p = &arr[0];
	q = &arr[1];
	r = &arr[2];*/

/*
	for (int i = 0; i < 3; i++) {
		// arr[i].showPerson();
		/*p->showPerson();
		p++;*/
/*		ptr[i]->showPerson();
	}

	return 0;
}
*/