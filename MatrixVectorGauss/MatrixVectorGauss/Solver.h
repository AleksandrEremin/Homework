#pragma once
#include "Matrix.h"
#include "Vector.h"

using namespace std;
class GaussSolver
{
	matrix M, cM;
	Vector x, b, cb;
	int n;
public:

	GaussSolver(const matrix& M1, const Vector& b1, int n1);
	void systemPrint();
	Vector gauss();
	void check();
};


