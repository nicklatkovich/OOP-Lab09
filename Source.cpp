#include "Array.h"
#include "Vector.h"
#include <iostream>
#include <time.h>
using namespace std;

/*
Ещё одно бесполезное задание... "Исключения"!

Найдётся ли хотя бы один прогер в этом мире, который в своих проектах использует исключения?
Если да, то он мазахист...
Не удивлюсь, если он и explicit использует   :D
*/

template <class T>
T less_(Array<T>arr, T value) {
	T min = value;
	int size = arr.GetSize();
	for (int i = 0; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

void cls() {
	system("pause");
	system("cls");
}

/*
void main() is DEMO
*/
void main() {
	srand(time(0));
	Array<double>arr(rand() % 4 + 3);
	cout << " >> Array<double>Arr(" << (int)arr << ");\n";
	cout << " >> Arr.SetRand(99, -99);\n";
	arr.SetRandDouble(99, -99);
	cout << " >> cout << Arr;\n";
	cout << "Arr<double> = " << arr << "\n\n";
	cls();
	cout << " >> cout << Arr;\n";
	cout << "Arr<double> = " << arr << "\n\n";
	cout << " >> Arr.Get(-2);\n";
	cout << "Arr[-2] = " << arr.Get(-2) << "\n\n";
	cls();
	cout << " >> cout << Arr;\n";
	cout << "Arr<double> = " << arr << "\n\n";
	cout << " >> Arr.Get(8);\n";
	cout << "Arr[8] = " << arr.Get(8) << "\n\n";
	cls();
	cout << " >> cout << Arr;\n";
	cout << "Arr<double> = " << arr << "\n\n";
	cout << " >> Arr.Resize(-2);\n";
	arr.Resize(-2);
	cout << endl;
	cls();
	cout << " >> Array<int>Neg(-2);\n";
	Array<int>Neg(-2);
	cout << " >> cout << Neg;\n";
	cout << "Neg<int> = " << Neg << "\n\n";
	cls();
	cout << " >> Array<double>ArrLeft(5);\n";
	Array<double>ArrLeft(5);
	cout << " >> ArrLeft.SetRand(-99, 99);\n\n";
	ArrLeft.SetRandDouble(-99, 99);
	cout << " >> Array<double>ArrRight(7);\n";
	Array<double>ArrRight(7);
	cout << " >> ArrRight.SetRand(-99, 99);\n";
	ArrRight.SetRandDouble(-99, 99);
	cout << "\n\n";
	cls();
	cout << " >> cout << ArrLeft;\n";
	cout << "ArrLeft<double> = " << ArrLeft << "\n\n";
	cout << " >> cout << ArrRight;\n";
	cout << "ArrRight<double> = " << ArrRight << "\n\n";
	cout << " >> cout << (ArrLeft * ArrRight);\n";
	Array<double>temp = ArrLeft * ArrRight;
	cout << temp << "\n\n";
}