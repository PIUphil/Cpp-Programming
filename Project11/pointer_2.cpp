#include <iostream>
using namespace std;

int main() {
	char name[6] = "KOREA";			// 초기값을 줄땐 배열크기를 생략해도됨
	//char* p = name;
	char job[8] = "STUDENT";
	//char* q = job;
	char address[8] = "DAEJEON";
	//char* w = address;

	char people[3][8] = {"KOREA", "STUDENT", "DAEJEON"};	// 2차원배열
	//char* aaa[3] = { p, q, w };
	char* aaa[3] = {name, job, address};					// 1차원배열

	/*cout << name << endl;
	cout << job << endl;
	cout << address << endl;*/

	for (int i = 0; i < 3; i++) cout << people[i][0];

	return 0;
}