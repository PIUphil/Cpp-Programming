#include <iostream>
using namespace std;

#include "Adder.h"

Adder::Adder(int a, int b) {
	su1 = a;
	su2 = b;
}

int Adder::process() {
	return su1 + su2;
}