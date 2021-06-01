/*
  가위바위보 게임 만들기
  두 사람이 하는 가위, 바위, 보 게임을 만들어 보세요.

  주어진 입출력 형식에 맞게 구현하세요.

  <입력 및 출력형식>
  게임에 참가할 사람이름 : 방자 향단
  게임을 시작합니다.
  방자 = 가위
  향단 = 바위
  향단이가 이겼습니다.
  다시(Y/N) = y
  
  게임에 참가할 사람이름 : 순이 철수
  순이 = 바위
  철수 = 바위
  비겼습니다.
  다시(Y/N) = N
  프로그램을 종료합니다.
*/

#include <iostream>
#include <string>
using namespace std;


int main() {
	string a, b;
	string c, d;
	char check;

	while (true) {
		cout << "게임에 참여할 두 사람 이름 :";
		cin >> a >> b;

		cout << a << " = ";
		cin >> c;
		cout << b << " = ";
		cin >> d;

		if ((c == "가위" && d == "보") || (c == "바위" && d == "가위") || (c == "보" && d == "바위"))
			cout << a << "가 이겼습니다." << endl;
		else if ((c == "보" && d == "가위") || (c == "가위" && d == "바위") || (c == "바위" && d == "보"))
			cout << b << "가 이겼습니다." << endl;
		else
			cout << "비겼습니다" << endl;


		cout << "다시(Y / N) = ";
		cin >> check;

		if (check == 'n'|| check == 'N') break;
	}

	return 0;
}


//int main() {
//	string name1, name2, winner;
//	string rsp1, rsp2;
//	int rsp1_i, rsp2_i;
//	char yn;
//
//	do {
//		cout << "게임에 참가할 사람이름 : ";
//		cin >> name1 >> name2;
//
//		cout << name1 << " = ";
//		cin >> rsp1;
//
//		cout << name2 << " = ";
//		cin >> rsp2;
//
//		// 가위 바위 보 = 1,2,3
//		if (rsp1 == "가위") rsp1_i = 1;
//		else if (rsp1 == "바위") rsp1_i = 2;
//		else if (rsp1 == "보") rsp1_i = 3;
//		else cout << "error";
//
//		if (rsp2 == "가위") rsp2_i = 1;
//		else if (rsp2 == "바위") rsp2_i = 2;
//		else if (rsp2 == "보") rsp2_i = 3;
//		else cout << "error";
//
//		// (rsp1_i - rsp2_i)%3
//		switch ((3 + rsp1_i - rsp2_i) % 3 == 0) {
//		case 1: winner = name1; break;
//		case 2: winner = name2; break;
//		default: winner = "0";
//		}
//
//		if (winner!="0")
//			cout << winner << "이가 이겼습니다." << endl;
//		else cout << "비겼습니다." << endl;
//
//		cout << "다시(Y / N) = ";
//		cin >> yn;
//	} while (yn == 'y');
//
//
//	cout << "프로그램을 종료합니다." << endl;
//	return 0;
//}