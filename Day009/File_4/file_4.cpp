/*
  get()을 이용해서 텍스트 파일
  C:\Windows\system.ini 파일을 읽어 화면에 출력하는 프로그램을 구현하시오.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* file = "C:/Windows/system.ini";
	
	// step1. 파일 객체 생성
	ifstream fin;

	// step2. 파일 열기
	//fin.open("C:/Windows/system.ini"/*, ios::in*/);	// ios::in - 파일 읽기 (생략)
	fin.open(file);

	if (!fin) {
		cout << "파일 열기 실패\n";
		return 0;
	}

	// step3. 작업
	int byte = 0;
	int ch;

	while ((ch = fin.get()) != EOF) {
		cout.put(ch);				
		byte++;
		//if (ch == '\n') break;
	}

	cout << "읽은 바이트 수 : " << byte << endl;

	// step4. 파일 닫기
	fin.close();

	return 0;
}