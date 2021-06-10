/*
  istream& ignore(int n=1, int delim=EOF)
  입력스트림에서 n개의 문자 제거

	cin.ignore(10);			- 스트림에서 10개 제거
	cin.ignore(10, ';');	- 10개문자 제거하고 ; 을 만나면 종료

  int gcount()
  최근 입력스트림에서 읽은 바이트 수(문자의 개수)
  - Enter키도 개수에 포함됨
*/