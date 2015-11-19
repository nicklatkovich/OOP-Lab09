#pragma once
#include <iostream>
using namespace std;

class Vector {
	int size = 0;
	int * coord = new int[0];
public:
	Vector();
	Vector(const Vector & Copy);
	Vector(int size);
	~Vector();
	void Set(int number, int index);
	void SetRand(int min, int max);
	int Get(int index);
	int GetSize();
	void Resize(int size);
	Vector & operator = (Vector & right);
	void print();
	friend ostream & operator << (ostream & output, Vector & v) {
		output << "V{";
		for (int i = 0; i < v.size; i++) {
			if (i > 0) {
				output << ",";
			}
			output << v.Get(i);
		}
		output << "}";
		return output;
	}
	friend bool operator < (Vector & left, Vector & right) {
		if (left.size < right.size) {
			return true;
		}
		else if (left.size > right.size) {
			return false;
		}
		else {
			for (int i = 0; i < left.size; i++) {
				if (left.Get(i) < right.Get(i)) {
					return true;
				}
				else if (left.Get(i) > right.Get(i)) {
					return false;
				}
			}
			return false;
		}
	}
	friend bool operator == (Vector & left, Vector & right) {
		if (left.size != right.size) {
			return false;
		}
		else {
			for (int i = 0; i < left.size; i++) {
				if (left.Get(i) != right.Get(i)) {
					return false;
				}
			}
			return true;
		}
	}
	friend bool operator > (Vector & left, Vector & right) {
		return ((!(left == right)) && (!(left < right)));
	}
	friend bool operator != (Vector & left, Vector & right) {
		return (!(left == right));
	}
};