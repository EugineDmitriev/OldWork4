#include <iostream>
#include "SimplexM.h"

using namespace std;

void Simplex::PrintData() {
	newStr = -1;
	newStolb = -1;

	cout << endl << endl << "Вычёркиваем V строку и v1/v2 столбцы" << endl;
	while (totalRes < 3) {
		for (int i = 0; i < 5; i++) {
			if (tempStolb[i] < 0) {
				tempVdel[i] = i;
			}
		}

		tempVdel1 = tempVdel[0];
		tempVdel2 = tempVdel[1];

		Xleft1 = tempStr[0];
		Xleft2 = tempStr[1];
		Xleft3 = tempStr[2];

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 2; j++) {
				if (tempStolb[i] > 0) {
					Xtop[j] = tempStolb[i];
				}
			}
		}

		Xtop1 = Xtop[0];
		Xtop2 = Xtop[1];

		for (int i = 0; i < 5; i++) {
			if (tempStolb[i] > 0 && Xtop1 == Xtop2) {
				Xtop2 = tempStolb[i];
			}
		}

		Lmass[0] = Xmass[0][0] * Cfunc[Xleft1] + Xmass[1][0] * Cfunc[Xleft2] + Xmass[2][0] * Cfunc[Xleft3];
		for (int i = 1; i < 6; i++) {
			Lmass[i] = Xmass[0][i] * Cfunc[Xleft1] + Xmass[1][i] * Cfunc[Xleft2] + Xmass[2][i] * Cfunc[Xleft3];
		}

		for (int i = 1; i < 6; i++) {
			if (i > tempStolb[i]) {
				if (i == Cfunc[Xtop1]) {
					Lmass[i] = Lmass[i] - Cfunc[Xtop1];
				}
				else if (i == Cfunc[Xtop2]) {
					Lmass[i] = Lmass[i] - Cfunc[Xtop2];
				}
			}
		}

		cout << endl;
		for (int i = 0; i < 5; i++) {
			if (tempStolb[i] >= 0) {
				cout << Xmass[0][i] << "   ";
			}
		}
		cout << endl;
		for (int i = 0; i < 5; i++) {
			if (tempStolb[i] >= 0) {
				cout << Xmass[1][i] << "   ";
			}
		}
		cout << endl;
		for (int i = 0; i < 5; i++) {
			if (tempStolb[i] >= 0) {
				cout << Xmass[2][i] << "   ";
			}
		}
		cout << endl;

		cout << Lmass[0] << "   " << Lmass[Xtop1] << "   " << Lmass[Xtop2];
		cout << endl << endl;


		if (totalRes < 3) {
			tempVmass = 0;

			for (int i = 1; i < 5; i++) {
				if (Lmass[i] > 0 && tempStolb[i] != i) {
					stolb = i;
					tempVmass = Lmass[i];
				}
				if (Lmass[i] > 0 && Lmass[i] == tempVmass) break;
			}

			tempVres = 0;
			for (int i = 1; i < 5; i++) {
				if (Lmass[i] <= 0) {
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
					NewVmass[i] = Lmass[i] * lambda * -1;
				}
				if (i != stolb) {
					NewVmass[i] = Lmass[i] + lambda * -1 * Lmass[stolb] * Xmass[str][i];
				}
			}

			cout << endl;

			for (int i = 0; i < 5; i++) {
				if (0 <= tempStolb[i]) {
					cout << NewXmass[0][i] << "   ";
				}
			}
			cout << endl;
			for (int i = 0; i < 5; i++) {
				if (0 <= tempStolb[i]) {
					cout << NewXmass[1][i] << "   ";
				}
			}
			cout << endl;
			for (int i = 0; i < 5; i++) {
				if (0 <= tempStolb[i]) {
					cout << NewXmass[2][i] << "   ";
				}
			}
			cout << endl;
			for (int i = 0; i < 5; i++) {
				if (0 <= tempStolb[i]) {
					cout << NewVmass[i] << "   ";
				}
			}
			cout << endl;

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 5; j++) {
					Xmass[i][j] = NewXmass[i][j];
				}
			}

			for (int i = 0; i < 5; i++) {
				Lmass[i] = NewVmass[i];
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
		}


		totalRes = 0;
		for (int i = 0; i < 3; i++) {
			if (Lmass[i] <= 0) {
				totalRes++;
			}
		}
	}
	
		if (totalRes == 3) {
			cout << "x[" << Xleft1 << "] = " << Xmass[0][0] << "   ";
			cout << "x[" << Xleft2 << "] = " << Xmass[1][0] << "   ";
			cout << "x[" << Xleft3 << "] = " << Xmass[2][0] << "   ";
			cout << "Lmin = " << Lmass[0] << endl;
			cout << "x[" << Xtop1 << "] = 0   ";
			cout << "x[" << Xtop2 << "] = 0   " << endl;
		}
};