#include <iostream>
using namespace std;

class SoSimple {
	int num;

public:
	SoSimple(int n) : num(n) {}

	SoSimple& AddNum(int n) {
		num += n;
		return *this;			// 나의 주소를 리턴
	}

	void showData() const {		// const로 만들어진 객체만 접근가능..?( 아니어도 되네,,?)
		cout << "num = " << num << endl;
	}
};

int main() {
	const SoSimple obj(7);
	// obj.AddNum(20);			// 값 변경 불가
	obj.showData();

	return 0;
}