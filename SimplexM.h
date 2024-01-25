#ifndef _Simplex_CLASS_H_
#define _Simplex_CLASS_H_

class Simplex {
private:
	double Cfunc[6];
	double Xmass[3][6];
	double NewXmass[3][6];
	double Vmass[6];
	double NewVmass[6];
	int flagVmass[5];
	double tempVmass;
	int flagA;
	int str, stolb, newStolb, newStr;
	double BAmass[3];
	double tempBAmass;
	double lambda;
	double tempAA;
	double tempA[3];
	int tempA1 = 0;
	int tempStr[3] = {-1, -1, 5};
	int tempStolb[5] = {0, 1, 2, 3, 4};
	int tempS;
	int tempRes;
	int tempVres;
	int tempVdel[2];
	int tempVdel1, tempVdel2;
	int totalRes;
	double Lmass[6];
	int Xleft1, Xleft2, Xleft3, Xtop1, Xtop2;
	int Xtop[2];

public:
	void InputData();
	void CalcData();
	void PrintData();
};

#endif