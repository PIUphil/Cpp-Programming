/*
  다섯 명의 이름을 입력받아 벡터에 저장한 후, 
  사전에서 가장 뒷 순에 해당하는 사람의 이름을 출력하시오
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> sv;
	string name;

	cout << "다섯 명의 이름을 입력하세요." << endl;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "번째 이름 = ";
		// cin >> name;
		getline(cin, name, '\n');		// 성과 이름을 띄워써도 입력받음.
		sv.push_back(name);
	}

	// 처리 - 사전에서 가장 마지막에 나오는 이름
	name = sv.at(0);	// 벡터의 첫번째 값
	for (int i = 1; i < sv.size(); i++) {
		if (name < sv[i])
			name = sv[i];
	}
	cout << "사전에서 가장 뒤에 나오는 이름 : " << name << endl;


	return 0;
}