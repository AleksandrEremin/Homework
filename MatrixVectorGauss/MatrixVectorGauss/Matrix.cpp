#include "Matrix.h"

matrix::matrix(int n1)
{
	if (n1 > 0)
	{
		n = n1;
		M = new double* [n];
		for (int i = 0; i < n; i++)
			M[i] = new double[n];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				M[i][j] = 0.0;
	}
	else
	{
		throw "Error";
	}
}


void matrix::matrixRand()
{
	int j;
	for (int i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			M[i][j] = 10 + (double)rand() / RAND_MAX * (0 - 10);
	}
	cout << "~матрица успешно сгенерирована\n" << endl;
}

void matrix::matrixPrint()
{
	cout << "        -----===== Печать  матрицы  =====-----\n" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "      |     ";
		for (int j = 0; j < n; j++)
		{
			cout << std::left << std::setw(10) << M[i][j];
		}
		cout << "|\n";
	}
	cout << "\n";
}

void matrix::matrixWrite()
{
	cout << "       ------===== Задаем  матрицу =====------\n" << endl;
	int j;
	double a;
	for (int i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << "[" << i << "]" << "[" << j << "]" << ":";
			cin >> a;
			cout << endl;
			M[i][j] = a;
		}
	}
	cout << endl;
}

double*& matrix::operator [](int i)
{
	if (i > 0 && i < n);
	return M[i];
}


const double* matrix::operator[](int i) const
{
	if (i >= 0 && i < n)
		return M[i];
}

matrix& matrix::operator=(const matrix& other)
{
	if (&other == this)
		return *this;
	else
	{
		for (int i = 0; i < n; i++)
			delete[] M[i];
		delete[] M;
		n = other.n;
		M = new double* [n];
		for (int i = 0; i < n; i++)
			M[i] = new double[n];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				M[i][j] = other.M[i][j];
		}
		return *this;
	}
}

matrix matrix::operator+(const matrix& other) const
{
	matrix res(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			res.M[i][j] = M[i][j] + other.M[i][j];
	}
	return res;
}

matrix matrix::operator*(const matrix& other) const
{
	matrix res(n);
	for (int i = 0; i < res.n; i++)
	{
		for (int j = 0; j < res.n; j++)
		{
			for (int k = 0; k < n; k++)
				res.M[i][j] += M[i][k] * other.M[k][j];
		}
	}
	return res;
}


int matrix::operator==(const matrix& m) const
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (M[i][j] != m.M[i][j])
				return 0;
		}
	}
	return 1;
}