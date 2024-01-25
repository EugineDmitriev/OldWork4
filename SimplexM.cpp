#include <iostream>
#include "SimplexM.h"

using namespace std;


void Simplex::CalcData() {
	while (tempRes < 2) {

		tempVmass = 0;

		for (int i = 1; i < 5; i++) {
			if (Vmass[i] > 0) {
				stolb = i;
				tempVmass = Vmass[i];
				}
			if (Vmass[i]>0 && Vmass[i] == tempVmass) break;
		}

		tempVres = 0;
		for (int i = 1; i < 5; i++) {
			if (Vmass[i] <= 0) {
				tempVres++;
			}
		}


		tempBAmass = 0;
		for (int i = 0; i < 3; i++) {
			if (Xmass[i][stolb] == 0) {
				BAmass[i] = 0;
			}
			else {
				BAmass[i] = Xmass[i][0] / Xmass[i][stolb];
			}
			if (BAmass[i] > 0 && (tempBAmass == 0 || BAmass[i] < tempBAmass)) {
				tempBAmass = BAmass[i];
				str = i;
			}
		}

		if (newStr == str && newStolb == stolb) {
			cout << "Бесконечный цикл, нет решения" << endl;
			system("pause");
		}

		newStr = str;
		newStolb = stolb;

		cout << "Разрешающий элемент [" << str + 1 << "][" << stolb << "]" << endl << endl << endl;

		lambda = 1 / Xmass[str][stolb];

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {
				if (i != str && j != stolb) {
					NewXmass[i][j] = Xmass[i][j] + Xmass[i][stolb] * lambda * -1 * Xmass[str][j];
				}
			}
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {
				if (i == str && j == stolb) {
					NewXmass[i][j] = lambda;
				}
			}
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {
				if (i == str && j != stolb) {
					NewXmass[i][j] = Xmass[i][j] * lambda;
				}
			}
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {
				if (i != str && j == stolb) {
					NewXmass[i][j] = Xmass[i][j] * lambda * -1;
				}
			}
		}


		for (int i = 0; i < 5; i++) {
			if (i == stolb) {
				NewVmass[i] = Vmass[i] * lambda * -1;
			}
			if (i != stolb) {
				NewVmass[i] = Vmass[i] + lambda * -1 * Vmass[stolb] * Xmass[str][i];
			}
		}

		cout << endl;

		for (int i = 0; i < 5; i++) {
			cout << NewXmass[0][i] << "   ";
		}
		cout << endl;
		for (int i = 0; i < 5; i++) {
			cout << NewXmass[1][i] << "   ";
		}
		cout << endl;
		for (int i = 0; i < 5; i++) {
			cout << NewXmass[2][i] << "   ";
		}
		cout << endl;
		for (int i = 0; i < 5; i++) {
			cout << NewVmass[i] << "   ";
		}
		cout << endl;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {
				Xmass[i][j] = NewXmass[i][j];
			}
		}

		for (int i = 0; i < 5; i++) {
			Vmass[i] = NewVmass[i];
		}

		for (int i = 0; i < 3; i++) {
			if (str == i) {
				tempS = tempStr[i];
				tempStr[i] = stolb;
			}
		}

		for (int i = 0; i < 5; i++) {
			if (i == 0) {}
			else if (stolb == i) {
				tempStolb[i] = tempS;
			}
		}


		tempRes = 0;
		for (int i = 0; i < 5; i++) {
			if (tempStolb[i] < 0) {
				tempRes++;
			}
		}
		if (tempVres == 4 && tempRes < 2) {
			cout << "задача не имеет оптимального решения" << endl;
			system("pause");
		}
	}
};