/*
  C++ 파일 입출력(File I/O)
  - 파일(file) : 보조기억장소의 처리 단위
  - 텍스트 파일 : 문자만으로 구성된 파일. txt, html, xml, c/c++, java
  - 바이너리 파일 : 문자, 그림, 표, 사운드, 동영상 등등
					hwp, doc, ppt, jpg, bmp, mp3, ...
  - 파일 입출력 라이브러리
	fstream : iostream
	ifstream : istream - 입력
	ofstream : ostream - 출력

  - 파일입출력 방법
	step1. 파일객체 생성
	step2. 파일 열기
	step3. 작업
	step4. 파일 닫기
*/

#include <iostream>
#include <fstream>		// ifstream or ofstream
using namespace std;

int main() {
	// step1. 파일 객체 생성
	ofstream fout;		// file out

	// step2. 파일 열기
	// open(파일명, mode)
	// mode : r(read), w(write), a(append), rb, wb, ab [binary]
	// ofstream은 출력용이므로 w를 생략가능하다?
	fout.open("song.txt");
	if (!fout) {			// 열기 실패일 경우
		cout << "song.txt 파일을 열지 못했습니다.\n";
		return 0;
	}

	// step3. 작업
	int age = 21;
	char singer[] = "kim";
	char song[] = "Yesterday";

	fout << age << '\n';
	fout << singer << endl;
	fout << song << endl;

	// step4. 파일 닫기
	fout.close();

	return 0;
}


