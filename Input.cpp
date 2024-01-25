#include <iostream>
#include "SimplexM.h"

using namespace std;

void Simplex::InputData() {
	cout << "¬ведите функцию" << endl;

	for (int i = 1; i < 6; i++) {
		if (i == 3 || i == 4) {
			Cfunc[i] = 0;
		}
		else {
			cout << "x[" << i << "] " << endl;
			cin >> Cfunc[i];
		}
	}



	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			if (i == 0) {
				cout << "¬ведите коэффициенты 1-го уравнени€" << endl;
				if (j == 0) {
					cout << "¬ведите свободный член" << endl;
					cin >> Xmass[i][j];
				}
				else if (j == 3) {
					Xmass[i][j] = 0;
				}
				else if (j == 4) {
					Xmass[i][j] = 0;
				}
				else if (j == 5) {
					Xmass[i][j] = 0;
				}
				else {
					cout << "x[" << j << "] " << endl;
					cin >> Xmass[i][j];
				}
			}

			if (i == 1) {
				cout << "¬ведите коэффициенты 2-го уравнени€" << endl;
				if (j == 0) {
					cout << "¬ведите свободный член" << endl;
					cin >> Xmass[i][j];
				}
				else if (j == 1) {
					Xmass[i][j] = 0;
				}
				else if (j == 4) {
					Xmass[i][j] = 0;
				}
				else if (j == 5) {
					Xmass[i][j] = 0;
				}
				else {
					cout << "x[" << j << "] " << endl;
					cin >> Xmass[i][j];
				}
			}

			if (i == 2) {
				cout << "¬ведите коэффициенты 3-го уравнени€" << endl;
				if (j == 0) {
					cout << "¬ведите свободный член" << endl;
					cin >> Xmass[i][j];
				}
				else if (j == 1) {
					Xmass[i][j] = 0;
				}
				else if (j == 2) {
					Xmass[i][j] = 0;
				}
				else {
					cout << "x[" << j << "] " << endl;
					cin >> Xmass[i][j];
				}
			}

		}
	}

		for (int j = 0; j < 6; j++) {
			if (Xmass[2][5] > 1 && Xmass[2][0] > 0) {
				Xmass[2][j] = Xmass[2][j] / Xmass[2][5];
			}
			else if (Xmass[2][5] < 1 && Xmass[2][0] > 0) {
				Xmass[2][j] = Xmass[2][j] / Xmass[2][5] * -1;
			}
			else if (Xmass[2][5] == 0) {
				Xmass[2][5] = 1;
			}
		}

	if (Xmass[0][0] < 0) {
		for (int i = 0; i < 6; i++) {
			if (Xmass[0][i] == 0) {
				Xmass[0][i] = 0;
			}
			else {
				Xmass[0][i] = Xmass[0][i] * -1;
			}
		}
	}

	if (Xmass[1][0] < 0) {
		for (int i = 0; i < 6; i++) {
			if (Xmass[1][i] == 0) {
				Xmass[1][i] = 0;
			}
			else {
				Xmass[1][i] = Xmass[1][i] * -1;
			}
		}
	}

	if (Xmass[2][0] < 0) {
		for (int i = 0; i < 6; i++) {
			if (Xmass[2][i] == 0) {
				Xmass[2][i] = 0;
			}
			else {
				Xmass[2][i] = Xmass[2][i] * -1;
			}
		}
	}

	for (int j = 0; j < 6; j++) {
		Vmass[j] = Xmass[0][j] + Xmass[1][j];
	}

	cout << endl;

	for (int i = 0; i < 5; i++) {
		cout << Xmass[0][i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 5; i++) {
		cout << Xmass[1][i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 5; i++) {
		cout << Xmass[2][i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 5; i++) {
		cout << Vmass[i] << " ";
	}
	cout << endl;
};