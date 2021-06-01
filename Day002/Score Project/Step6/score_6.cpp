/*
  6단계 : 3명의 점수를 입력받아 처리하도록 2차원 배열을 구현
*/


#include <iostream>
#include <string>
using namespace std;

int main() {
	int score[3][4];
	// score[][0]:kor, score[][1]:eng, score[][2]:math, score[][3]:tot
	float avg[3];
	char grade[3];
	string s[3] = { "kor", "eng", "math" };

	for (int inwon = 0; inwon < 3; inwon++) {
		score[inwon][3] = 0;
		for (int i = 0; i < 3; i++) {
			do {
				cout << s[i] + " = ";
				cin >> score[inwon][i];
			} while (score[inwon][i] < 0 || score[inwon][i] > 100);
			score[inwon][3] += score[inwon][i];
		}

		avg[inwon] = score[inwon][3] / 3.0f;

		switch (int(avg[inwon]) / 10) {
		case 10: case 9: grade[inwon] = 'A'; break;
		case 8: grade[inwon] = 'B'; break;
		case 7: grade[inwon] = 'C'; break;
		case 6: grade[inwon] = 'D'; break;
		default: grade[inwon] = 'F';
		}
	}

	for (int inwon = 0; inwon < 3; inwon++) {
		cout << "총점 = " << score[inwon][3] << ", 평균 = " << avg[inwon] << endl;
		cout << "학점 = " << grade[inwon] << endl;
	}
	return 0;
}