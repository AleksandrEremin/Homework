#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <iomanip> 

using namespace std;
class Vector
{
	double* V;
	int n;
public:
	Vector(int n=1);
	Vector(const Vector& bf);
	void vectorRand();
	void vectorPrint();
	void vectorWrite();
	double& operator[](int i);
	const double& operator[](int i) const;
	Vector& operator=(const Vector& v);
	int operator==(const Vector& v) const;
	int Getn() const;
	~Vector()
	{
	}
};
