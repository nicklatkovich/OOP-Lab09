#include "Vector.h"

Vector::Vector()
{
	delete[] coord;
	size = rand() % 6 + 2;
	coord = new int[size];
	for (int i = 0; i < size; i++) {
		coord[i] = rand() % 19 - 9;
	}
}

Vector::Vector(const Vector & Copy)
{
	delete[] coord;
	size = Copy.size;
	coord = new int[size];
	for (int i = 0; i < size; i++) {
		coord[i] = Copy.coord[i];
	}
}

Vector::Vector(int size)
{
	delete[] coord;
	this->size = size;
	coord = new int[size];
	for (int i = 0; i < size; i++) {
		coord[i] = 0;
	}
}

Vector::~Vector()
{
	delete[] coord;
}

void Vector::Set(int number, int index)
{
	if (index > -1 && index < size) {
		coord[index] = number;
	}
}

void Vector::SetRand(int min, int max)
{
	int r = abs(max - min) + 1;
	for (int i = 0; i < size; i++) {
		coord[i] = rand() % r + min;
	}
}

int Vector::Get(int index)
{
	if (index > -1 && index < size) {
		return coord[index];
	}
	else {
		return 0;
	}
}

int Vector::GetSize()
{
	return size;
}

void Vector::Resize(int size)
{
	Vector temp(this->size);
	for (int i = 0; i < this->size; i++) {
		temp.Set(coord[i], i);
	}
	delete[] coord;
	this->size = size;
	coord = new int[size];
	for (int i = 0; i < size; i++) {
		coord[i] = temp.Get(i);
	}
}

Vector & Vector::operator=(Vector & right)
{
	delete[] coord;
	size = right.size;
	coord = new int[size];
	for (int i = 0; i < size; i++) {
		coord[i] = right.Get(i);
	}
	return *this;
}

void Vector::print()
{
	cout << *this;
}
