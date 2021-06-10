#include <iostream>
#include <cstring>
using namespace std;

/*
  줄 단위로 입력하여 출력하는 프로그램
  단, exit를 입력하면 반복을 끝낸다.
  getline()
*/

int main() {
	char line[80];

	cout << "getline() 함수를 이용해서 줄단위로 입력\n";
	cout << "exit를 입력하면 프로그램이 종료됩니다." << endl;
	
	int no = 1;		// 라인번호
	while (true) {
		cout << no << " => ";
		cin.getline(line, 80);
		int cnt = cin.gcount();		// 가장 최근에 입력한 겟라인의 글자수를 리턴

		if (strcmp(line, "exit") == 0) break;
		cout << "Echo : " << line << endl;
		cout << "글자 수 : " << cnt << endl;
		no++;

	}
	return 0;
}