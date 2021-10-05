#include "Vector.h"

Vector::Vector(int n1)
{
	if (n1 > 0)
	{
		n = n1;
		V = new double[n];
		for (int i = 0; i < n; i++)
		{
			V[i] = 0.0;
		}
	}
	else
		throw "Error";
}

Vector::Vector(const Vector& v) 
{
	n = v.n;
	V = new double[n];
	for (int i = 0; i < n; i++)
		V[i] = v.V[i]; ;
}

void Vector::vectorRand()
{
	for (int i = 0; i < n; i++)
		V[i] = 10 + (double)rand() / RAND_MAX * (0 - 10);
	//cout << "~вектор успешно сгенерирован\n" << endl;
}

void Vector::vectorPrint()
{
	cout << "        -----===== Печать  вектора  =====-----\n" << endl;
	cout << "y =" << "( ";
	for (int i = 0; i < n; i++)
	{
		cout << std::left << std::setw(2) << V[i] << "  ";
	}
	cout << ")" << endl;
}

void Vector::vectorWrite()
{
	double a;
	cout << "        -----===== Задаем вектор =====-----\n" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i << "]" << ":";
		cin >> a;
		cout << endl;
		V[i] = a;
	}
}

double& Vector::operator[](int i)
{
	if (i >= 0 && i < n)
		return V[i];
	else
		return V[0];
}

const double& Vector::operator[](int i) const
{
	if (i >= 0 && i < n)
		return V[i];
}

Vector& Vector::operator=(const Vector& v)
{
	if (this == &v)
		return *this;
	else if (n == v.n)
	{
		for (int i = 0; i < n; i++)
			V[i] = v.V[i];
		return *this;
	}
	else
	{
		delete[] V;

		n = v.n;
		V = new double[n];
		for (int i = 0; i < n; i++)
			V[i] = v.V[i];
		return *this;
	}
}

int Vector::Getn() const
{
	return n;
}

int Vector::operator==(const Vector& v) const
{
	for (int i = 0; i < n; i++)
	{
		if (V[i] != v.V[i])
			return 0;
	}
	return 1;
}
