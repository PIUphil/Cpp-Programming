#include <iostream>
//#include <map>
//#include <string>
//#include <algorithm>
#include <random>
using namespace std;

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 9);
	for (int i = 0; i < 5; i++)
		cout << "³­¼ö : " << dis(gen) << endl;

	return 0;
}