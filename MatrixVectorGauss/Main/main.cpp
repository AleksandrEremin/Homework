#include "Solver.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 5;
	matrix matrix_1(n);
	Vector vector_1(n);


	//matrix_1.matrixWrite();
	matrix_1.matrixRand();
	//matrix_1.matrixPrint();


	//vector_1.vectorWrite();
	vector_1.vectorRand();
	//vector_1.vectorPrint();

	GaussSolver systems_1(matrix_1, vector_1, n);
	systems_1.systemPrint();
	systems_1.gauss();
	systems_1.check();

}