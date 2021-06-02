#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	int id;

public:
	Person(int id, string name);	// 생성자
	Person(Person& person);			// 복사생성자
	~Person();						// 소멸자

	void setName(string name);
	void disp();		
};

Person::Person(int id, string name) {
	this->id = id;
	this->name = name;
}

Person::Person(Person& person) {  // 깊은 복사 - 별도의 메모리 사용
	this->id = person.id;
	this->name = person.name;
}

Person::~Person() {
	cout << "개체소멸" << endl;
}

void Person::setName(string name) {
	this->name = name;
}

void Person::disp() {
	cout << id << " : " << name << endl;
}

int main() {
	Person father(1, "kitae");
	Person son(father);

	father.disp();
	son.disp();

	son.setName("gildong");
	father.disp();
	son.disp();

	return 0;
}

