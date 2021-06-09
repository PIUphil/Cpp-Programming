/*
  생성자 초기화
  클래스의 const, static 변수
  레퍼런스 타입을 리턴하는 함수
  this 포인터
  const 멤버 함수
*/

#include <iostream>
using namespace std;

class Marine {
	static int total_marine_num;

	int hp;						// 마린 체력
	int coord_x, coord_y;		// 마린 위치
	//int damage;					// 공격력
	bool is_dead;				// 생사확인

	// 기본 공격력
	const int default_damage;		//	const , final  - 선언하면 값을 바꿀 수 없음

public:
	Marine();					// 기본생성자
	Marine(int x, int y);		// x, y 좌표에 있는 마린 생성
	Marine(int x, int y, int default_damage);
	
	int attack();				// 데미지 리턴
	void be_attacked(int damage_earn);	// 피해 데미지
	void move(int x, int y);	// 새로운 위치
	void show_status();			// 상태 출력

	~Marine() {
		total_marine_num--;
	}
};

int Marine::total_marine_num = 0;

Marine::Marine()
	: hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
	total_marine_num++;
}

Marine::Marine(int x, int y)
	: hp(50), coord_x(x), coord_y(y), default_damage(5), is_dead(false) {
	total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
	: hp(50), coord_x(x), coord_y(y), /*damage(5),*/ is_dead(false), default_damage(default_damage) {
	total_marine_num++; 
}


int Marine::attack() {						// 데미지 리턴
	return default_damage;//damage;
}

void Marine::be_attacked(int damage_earn) {	// 피해 데미지
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;
}

void Marine::move(int x, int y) {			// 새로운 위치
	coord_x = x;
	coord_y = y;
}
void Marine::show_status() {
	cout << " *** Marine *** " << endl;
	cout << "Location : (" << coord_x << ", " << coord_y << ")" << endl;
	cout << "HP : " << hp << endl;
	cout << "현재 총 마린 수 : " << total_marine_num << endl;
}

void create_marine() {
	Marine marine3(10, 10, 4);
	marine3.show_status();
}

int main() {
	Marine marine1(2, 3, 10);
	marine1.show_status();

	Marine marine2(3, 5, 10);	
	marine2.show_status();

	cout << "마린1이 마린2를 공격!" << endl;
	marine2.be_attacked(marine1.attack());
	
	marine1.show_status();
	marine2.show_status();

	create_marine();

	return 0;
}