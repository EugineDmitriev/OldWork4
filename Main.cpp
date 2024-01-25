#include <iostream>
#include "SimplexM.h"

using namespace std;

int main() {
	setlocale(0, "RUS");
	Simplex s;
	s.InputData();
	s.CalcData();
	s.PrintData();
	system("pause");
	return 0;
};