#pragma once
#include "Errors.h"
#include <iostream>
using namespace std;

template <class T>
class Array {
	T * data = new T[0];
	int size = 0;
public:
	Array(int size) {
		try {
			if (size < 0) {
				throw ErrorNegativeSize();
			}
		}
		catch (ErrorNegativeSize a) {
			a.printErrorName();
			cout << "Created with Size = 0\n";
			return;
		}
		delete[] data;
		this->size = size;
		data = new T[size];
	}
	Array(const Array & Copy) {
		delete[] data;
		size = Copy.size;
		data = new T[size];
		for (int i = 0; i < size; i++) {
			data[i] = Copy.data[i];
		}
	}
	~Array() {
		delete[] data;
	}
	void Set(T dat, int index) {
		try {
			if (index < 0) {
				throw ErrorNegativeIndex();
			}
			else if (index >= size) {
				throw ErrorUnknownIndex();
			}
		}
		catch (ErrorNegativeIndex a) {
			a.printErrorName();
			cout << "NOT Set\n";
			return;
		}
		catch (ErrorUnknownIndex a) {
			a.printErrorName();
			cout << "NOT Set\n";
			return;
		}
		if (index > -1) if (index < size) {
			data[index] = dat;
		}
	}
	void SetRand(int min, int max) {
		try {
			if (max < min) {
				throw ErrorInRand();
			}
		}
		catch (ErrorInRand a) {
			a.printErrorName();
		}
		int r = abs(max - min) + 1;
		for (int i = 0; i < size; i++) {
			data[i] = rand() % r + min;
		}
	}
	void SetRandDouble(int min, int max) {
		try {
			if (max < min) {
				throw ErrorInRand();
			}
		}
		catch (ErrorInRand a) {
			a.printErrorName();
		}
		min *= 100;
		max *= 100;
		int r = abs(max - min) + 1;
		for (int i = 0; i < size; i++) {
			data[i] = (double)(rand() % r + min) / 100;
		}
	}
	T Get(int index) {
		try {
			if (index < 0) {
				throw ErrorNegativeIndex();
			}
			else if (index >= size) {
				throw ErrorUnknownIndex();
			}
		}
		catch (ErrorNegativeIndex a) {
			a.printErrorName();
			cout << "returned NULL\n";
			return NULL;
		}
		catch (ErrorUnknownIndex a) {
			a.printErrorName();
			cout << "returned NULL\n";
			return NULL;
		}
		return data[index];
	}
	int GetSize() {
		return size;
	}
	void Resize(int size) {
		try {
			if (size < 0) {
				throw ErrorNegativeSize();
			}
		}
		catch (ErrorNegativeSize a) {
			a.printErrorName();
			cout << "NOT Resized\n";
			return;
		}
		Array temp = *this;
		delete[] data;
		data = new T[size];
		for (int i = 0; i < size; i++) {
			data[i] = temp.Get(i);
		}
	}
	friend Array operator * (Array & left, Array & right) {
		try {
			if (left.GetSize() != right.GetSize()) {
				throw ErrorDifferentSizes();
			}
		}
		catch (ErrorDifferentSizes a) {
			a.printErrorName();
			cout << "Getting the MIN size\n";
		}
		int min;
		if (left.size < right.size) {
			min = left.size;
		}
		else {
			min = right.size;
		}
		Array temp(min);
		for (int i = 0; i < min; i++) {
			temp.data[i] = left[i] * right[i];
		}
		return temp;
	}
	Array & operator = (Array & right) {
		delete[] data;
		size = right.size;
		data = new T[size];
		for (int i = 0; i < size; i++) {
			data[i] = right[i];
		}
		return *this;
	}
	T operator [] (int index) {
		return Get(index);
	}
	operator int() {
		return size;
	}
	friend bool operator == (Array & left, Array & right) {
		if (left.size != right.size) {
			return false;
		}
		else {
			for (int i = 0; i < left.size; i++) {
				if (left[i] != right[i]) {
					return false;
				}
			}
			return true;
		}
	}
	friend bool operator <= (Array & left, Array & right) {
		if (left.size < right.size) {
			return true;
		}
		else if (left.size > right.size) {
			return false;
		}
		else {
			for (int i = 0; i < left.size; i++) {
				if (left[i] < right[i]) {
					return true;
				}
				else if (left[i] > right[i]) {
					return false;
				}
			}
			return true;
		}
	}
	void print() {
		cout << *this;
	}
	friend ostream & operator << (ostream & output, Array & arr) {
		output << "(";
		for (int i = 0; i < arr.size; i++) {
			if (i > 0) {
				output << ",";
			}
			output << " " << arr.data[i];
		}
		output << " )";
		return output;
	}
};