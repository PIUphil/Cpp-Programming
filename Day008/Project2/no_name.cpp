/*
  이름 없는 이름공간
*/
#include <iostream>

namespace {
	// 이 함수는 이 파일 안에서만 사용할 수 있다.
	// static int aaa()와 동일하다.
	int aaa() {}

	// static int x 와 동일하다.
	int x = 0;
}

int main() {
	aaa();
	x = 3;
	return 0;
}