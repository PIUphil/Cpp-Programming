/*
  words.txt 파일을 줄단위로 읽어 저장한 후
  사용자가 입력한 단어를 포함하고 있는 문자열을 출력하는 프로그램
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


void fileRead(vector<string>& v, ifstream& fin) {		// 파일에서 줄 읽어오는 함수
	string line;

	while (getline(fin, line)) {
		v.push_back(line);
	}
}

void search(vector<string>& v, string word) {			// 문장에서 단어 찾는 함수
	for (int i = 0; i < v.size(); i++) {
		int index = v[i].find(word);			// 1 or -1
		if (index != -1)		// 찾았다면
			cout << v[i] << endl;
	}
}


int main() {
	vector<string> wordVector;

	ifstream fin("D:/C++_Prograimming/source/words.txt");
	if (!fin) {
		cout << "words.txt 파일을 열 수 없습니다.\n";
		return 0;
	}

	fileRead(wordVector, fin);
	fin.close();

	cout << "words.txt 파일을 읽었습니다.\n";

	while (true) {
		cout << "검색할 단어를 입력해주세요. \n";
		cout << "프로그램을 종료할 경우 exit를 입력하세요.";
		cout << "검색할 단어 = ";
		string word;
		getline(cin, word);

		if (word == "exit") break;

		search(wordVector, word);
	}
	cout << "프로그램을 종료합니다.\n";
	return 0;
}