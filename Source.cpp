#include "Array.h"
#include "Vector.h"
#include <iostream>
#include <time.h>
using namespace std;

/*Функция-шаблон, вычисляющая значение в массиве меньше заданного

Какое же тупое задание :facepalm...
Нет, чтобы найти минимальное из тех значений, что меньше заданного. Или максимальное...
Но найти ЗНАЧЕНИЕ в массиве меньше заданного... ЗНАЧЕНИЕ... ОДНО!!!*/

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

void main() {
	srand(time(0));
	Array<int>arr1(rand() % 4 + 3);
	arr1.SetRand(-99, 99);
	cout << "Arr1<int> = " << arr1 << endl;
	cout << "less_(Arr1, 0) = " << less_(arr1, 0) << endl;
	Array<double>arr2(rand() % 4 + 3);
	arr2.SetRandDouble(-99, 99);
	cout << "Arr2<int> = " << arr2 << endl;
	cout << "less_(Arr2, 0) = " << less_(arr2, 0.0) << endl;
	Array<Vector>arr3(rand() % 4 + 3);
	cout << "Arr3<Vector> = " << arr3 << endl;
	Vector vec;
	cout << "Vec = " << vec << endl;;
	cout << "less_(Arr3,  Vec) = " << less_(arr3, vec) << endl;
}