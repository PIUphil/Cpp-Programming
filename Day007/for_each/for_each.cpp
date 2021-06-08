/*
  for_each() : 컨테이너의 각 원소를 검색하는 함수
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(int n) {
	cout << n << " ";
}

int main() {
	vector<int> v = { 1, 2, 3, 4, 5 };

	for_each(v.begin(), v.end(), print);
	// for_each(v.begin(), v.end(), [](int n) {cout << n << " "; });	// 람다표현식

	return 0;
}