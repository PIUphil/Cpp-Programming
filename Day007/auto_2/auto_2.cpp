#include <iostream>
#include <vector>
using namespace std;

int square(int x) {
	return x * x;
}

int main() {
	auto c = 'a';
	auto pi = 3.14;
	auto num = 10;
	auto* p = &num;
	cout << c << ":" << pi << ":" << num << ":" << *p << endl;

	auto res = square(3);
	cout << res << endl;

	vector<int> v = { 1, 2, 3, 4, 5 };
	/*vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		cout << *it << " ";*/

	for (auto it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	
	cout << endl;
	
	return 0;
}