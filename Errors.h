#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Error {
	char * ErrorName = new char[0];
	int ErrorNameLength = 0;
	bool Critical = false;
public:
	Error() {}
	Error(Error & Object) {
		ErrorNameLength = Object.ErrorNameLength;
		delete[] ErrorName;
		ErrorName = new char[ErrorNameLength];
		for (int i = 0; i < ErrorNameLength; i++) {
			ErrorName[i] = Object.ErrorName[i];
		}
	}
	void printErrorName() {
		cout << setw(ErrorNameLength) << setfill('=') << "";
		cout << endl;
		for (int i = 0; i < ErrorNameLength; i++) {
			cout << ErrorName[i];
		}
		cout << endl;
		cout << setw(ErrorNameLength) << setfill('=') << "";
		cout << endl;
	}
	void setErrorName(const char * ErrorName) {
		ErrorNameLength = strlen(ErrorName);
		delete[]this->ErrorName;
		this->ErrorName = new char[ErrorNameLength];
		for (int i = 0; i < ErrorNameLength; i++) {
			this->ErrorName[i] = ErrorName[i];
		}
	}
	~Error() {
		delete[] ErrorName;
		if (Critical) {
			exit(0);
		}
	}
};

class ErrorInRand : public Error {
public:
	ErrorInRand() {
		setErrorName("ERROR in Rand: MAX < MIN");
	}
};

class ErrorNegativeIndex : public Error {
public:
	ErrorNegativeIndex() {
		setErrorName("ERROR in Get: Index < 0");
	}
};

class ErrorUnknownIndex : public Error {
public:
	ErrorUnknownIndex() {
		setErrorName("ERROR in Get: Index > Size");
	}
};

class ErrorNegativeSize : public Error {
public:
	ErrorNegativeSize() {
		setErrorName("ERROR in SetSize: Size < 0");
	}
};

class ErrorDifferentSizes : public Error {
public:
	ErrorDifferentSizes() {
		setErrorName("ERROR: Sizes of Arrayes are Different");
	}
};