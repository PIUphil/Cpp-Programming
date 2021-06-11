#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
#pragma warning(disable:4996)


// 학생 성적정보를 저장하기 위한 클래스
class Student {
private:
	int no;					// 학번
	char name[256];			// 이름
	int kor, eng, math;		// 국어,영어,수학 점수
	int total;				// 총점
	double avg;				// 평균
	char level;				// 학점
	int grade;				// 등수

public:
	Student(int no, char* name, int kor, int eng, int math);
	//Student(char* name);
	Student();
	void calculate();
	friend ostream& operator<<(ostream& os, const Student& stu);			// 연산자 오버로딩
	friend void PrintElement(Student stu);						// 멤버필드 접근하기 위한 프렌드
	bool operator==(const char* key) const;
	void getStudent();

	int getNo();
};

Student::Student(int no, char* name, int kor, int eng, int math)
	: no(no), kor(kor), eng(eng), math(math) {
	strcpy(this->name, name); 
	calculate();
}

//Student::Student(char* name) {
//	strcpy(this->name, name);
//	//calculate();
//}

Student::Student() {
	calculate();
}

int Student::getNo() { return no; }

void Student::calculate() {
	total = kor + eng + math;
	avg = total / 3.0;
	
	switch (int(avg) / 10) {
	case 10: 
	case 9: level = 'A'; break;
	case 8: level = 'B'; break;
	case 7: level = 'C'; break;
	case 6: level = 'D'; break;
	default : level = 'F';
	}

	grade = 1;				// 등록된 모든 학생을 등수를 1로 초기화
}

ostream& operator<<(ostream& os, const Student& stu) {					// 연산자 오버로딩
	os << setw(4) << stu.no << setw(10) << stu.name
		<< setw(8) << stu.kor << setw(7) << stu.eng << setw(7) << stu.math
		<< setw(9) << stu.total << setw(9) << setprecision(2) << stu.avg			// setprecision(2) 소수점이하 2자리까지 표시
		<< setw(7) << stu.level << setw(7) << stu.grade;

	return os;
}

bool Student::operator==(const char* key) const {
	return strcmp(name, key) == 0;
}

void Student::getStudent() {
	cout << "학번 = ";
	cin >> no;
	cout << "이름 = ";
	cin >> name;
	cout << "국어점수 = ";
	cin >> kor;
	cout << "영어점수 = ";
	cin >> eng;
	cout << "수학점수 = ";
	cin >> math;

	// 버퍼에 남아있는 값을 비우는 작업
	fflush(stdin);
	calculate();
}

void PrintElement(Student stu) {
	cout << stu << endl;
}

/*
os << setw(4) << stu.no << setw(10) << stu.name
		<< setw(8) << stu.kor << setw(7) << stu.eng << setw(7) << stu.math
		<< setw(9) << stu.total << setw(9) << setprecision(2) << stu.avg
		<< setw(7) << stu.level << setw(7) << stu.grade;
*/

void title() {
	cout << "학번    이름     국어     영어     수학     총점    평균    학점    등수" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
}

//    [1] 입력   [2] 삭제   [3] 검색   [4] 출력   [5] 로드   [6] 저장   [7] 종료
// char* smenu[] = { "[1] 입력", "[2] 삭제", "[3] 검색", "[4] 출력", "[5] 로드", "[6] 저장", "[7] 종료" };

//char select_menu() {
//	char ch;
//	// int i;
//	cout << "\n****************************************************************************" << endl;
//	//for (i = 0; i < sizeof(smenu) / sizeof(smenu[0]); i++) {
//	//	cout << setw(10) << smenu[i];					// 메뉴 출력
//	//}
//	cout << "[1] 입력,   [2] 삭제,   [3] 검색,   [4] 출력,   [5] 로드,   [6] 저장,   [7] 종료";
//	cout << "\n****************************************************************************" << endl;
//
//	do {
//		cout << "메뉴 = ";
//		cin.get(ch);
//		fflush(stdin);
//	} while (ch < '1' || ch>'7');
//
//	return ch;
//}


class StudentManager {
public:
	vector<Student> v;

	void Input() {
		cout << "\n == 학생 등록 ==\n";
		Student temp;
		temp.getStudent();
		v.push_back(temp);
	}

	void Display() {
		cout << "\n\t == 전체 학생 정보 출력 == \n";
		title();
		for_each(v.begin(), v.end(), PrintElement);
	}

	void Delete() {
		//int id;
		char name;
		char searchName[256];


		cout << "\n == 학생 삭제 ==\n";
		//cout << "삭제할 학번 = ";
		cout << "삭제할 이름 = ";
		//cin >> id;
		cin >> searchName;
		fflush(stdin);

		vector<Student>::iterator iter;
		//iter = find(v.begin(), v.end(), id);
		iter = find(v.begin(), v.end(), searchName);

		if (iter != v.end()) {
			cout << "[삭제대상]" << endl;
			title();
			cout << *iter << endl;
			v.erase(iter);
			cout << "성공적으로 삭제가 완료되었습니다." << endl;
			Display();
		}
		else {
			//cout << id << " 학번이 존재하지 않습니다." << endl;
			cout << searchName << " 이름이 존재하지 않습니다." << endl;
		}
	}

	void Search() {
		// int id;
		char searchName[256];

		cout << "\n == 학생 검색 ==\n";
		//cout << "검색할 학번 = ";
		cout << "검색할 이름 = ";
		//cin >> id;
		cin >> searchName;
		fflush(stdin);

		vector<Student>::iterator iter;
		//iter = find(v.begin(), v.end(), id);
		iter = find(v.begin(), v.end(), searchName);

		if (iter != v.end()) {
			cout << "[검색대상]" << endl;
			title();
			cout << *iter << endl;
		}
		else {
			//cout << id << " 학번이 존재하지 않습니다." << endl;
			cout << searchName << " 이름이 존재하지 않습니다." << endl;
		}
	}

	void delete_all() {
		for (int i = v.size() - 1; i > 0; i--) {
			v.erase(v.begin()+i);
		}
	}

	void Exit() {
		cout << "\n 프로그램을 종료합니다.\n";
		delete_all();
	}

	void Load() {
		delete_all();

		ifstream fin;

		fin.open("student.txt");
		
		Student temp;

		while (fin.read((char*)&temp, sizeof(temp))) {		// 레코드(한줄) 단위로 읽어옴
			v.push_back(temp);
		}

		fin.close();
	}

	void Save() {
		ofstream fout;

		fout.open("student.txt");

		vector<Student>::iterator iter;

		for (iter = v.begin(); iter != v.end(); iter++) {
			Student temp = *iter;

			fout.write((char*)&temp, sizeof(temp));
		}

		fout.close();
	}	
};


int main() {
	StudentManager sm;

	sm.Load();

	//char ch;
	int ch;
		
	while (true) {
		//ch = select_menu();
		//    [1] 입력   [2] 삭제   [3] 검색   [4] 출력   [5] 로드   [6] 저장   [7] 종료
		cout << "\n\t 성적 관리 프로그램\n";
		cout << "\n****************************************************************************" << endl;
		cout << "[1] 입력,   [2] 삭제,   [3] 검색,   [4] 출력,   [5] 로드,   [6] 저장,   [7] 종료";
		cout << "\n****************************************************************************" << endl;
		cin >> ch;

		switch (ch) {
		case 1: sm.Input(); break;
		case 2: sm.Delete(); break;
		case 3: sm.Search(); break;
		case 4: sm.Display(); break;
		case 5: sm.Load(); break;
		case 6: sm.Save(); break;
		case 7: sm.Exit(); return 0;
		}
	}
	return 0;
}