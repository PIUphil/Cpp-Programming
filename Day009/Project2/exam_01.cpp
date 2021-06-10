/*
  C++ 입출력 시스템
  - 스트림(stream) 입출력
	: 흐르는 시냇물
	: 데이터의 흐름이나 데이터를 제어하는 신호의 흐름 - 통로
	: 출입구 = 입력 스트림, 출력 스트림
	: 입출력 기본 단위 : 바이트(byte)
	  숫자, 영문자, 특수문자 - 1byte / 한글, 한자 - 2byte
	: 스트림 버퍼(buffer)를 가진다.		// buffer-임시기억장소
	: 임시기억장소 => 처리속도를 보완
	  버퍼, 클립보드(clipboard)-CtrlC/CtrlV/CtrlX, 캐시메모리(cache memory)-주기억장치와 cpu 사이에 존재 (펜티엄 : 캐시2개 / 셀러론 : 캐시1개)

  - ios => istream, ostream => iostream(fstream - file stream)
	(ios-최상위클래스/ 하위-istream, ostream)
  - ostream의 멤버 함수(ofstream - ouput file stream)
	: put(char ch) => 하나의 문자 출력
	  write(char* str, int n) => 문자열str에서 n개의 문자 출력
	  flush() => buffer에 있는 내용 출력
  - istream의 멤버 함수(ifstream - input file stream)
	: int get() => 문자를 읽어오는데 오류나 EOF(End Of File)일 때 '-1'을 리턴
	  istream& get(char& ch) => 문자를 읽어서 ch에 저장
	  istream& get(char* s, int n) => 입력스트림을 통해 n-1개의 문자를 읽어 배열s에 저장하고, 마지막에 '\0' 문자삽입
									  ('\n'을 만나면 '\0'을 삽입하고 리턴)
  - 포맷(format, 서식) 입출력 방법
	: c언어 printf = print + format, 출력서식에 맞게 출력하라
	: 출력서식(%) => %d, %c, %f, %s
	: 포맷 플래그, 포맷 함수, 조작자
  - 조작자 => 재정의(오버라이딩)
  - 삽입연산자(<<)와 추출연산자(>>) => 재정의(오버라이딩)
    : cin(입력), cout(출력), cerr(출력-오류), clog(출력-log,시스템 진행 파일)
*/