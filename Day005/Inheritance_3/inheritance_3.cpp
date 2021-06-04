#include <iostream>
#include <string>
using namespace std;

class Person {
protected:				// 상속관계에서 접근 허용
	int age;
	string name;

public:
	Person(int age, string name)
		: age(age), name(name) {}
	
	void show() const {
		cout << "name : " << name << endl;
		cout << "age : " << age << endl;
	}
};

// 파생클래스 : 접근제한자 부모클래스
class Student : public Person {
	//int age;
	//string name;
	string major;

public:
	Student(int age, string name, string major)
		: Person(age, name), major(major) {}		// 부모꺼 초기화

	void show() const {
		//cout << "name : " << name << endl;		// 부모꺼. private에선 접근 못하지만, protected에선 가능
		//cout << "age : " << age << endl;
		Person::show();
		cout << "major : " << major << endl;
	}
};


int main() {
	Student stu(11, "aaa", "컴공");
	stu.show();

	Student stu2(22, "bbb", "전기");
	stu2.show();

	return 0;
}