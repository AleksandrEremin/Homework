#include "../GTests/gtest.h"

#include <Matrix.h>
#include <Vector.h>
#include <gtest.h>
#include <Solver.h>


TEST(matrix, 1)
{
	matrix M(5);
	ASSERT_NO_THROW(matrix M(5));
}

TEST(matrix, 2)
{
	ASSERT_ANY_THROW(matrix M(-2));
}

TEST(matrix, 3)
{
	int size = 3;
	double sum = 0.0;
	matrix M1(size);
	for (int i = 1; i < size; i++)
		for (int j = 1; j < size; j++)
			sum += M1[i][j];
	ASSERT_EQ(0, sum);
}

TEST(matrix, 4)
{
	int n = 2;
	matrix matrix_1(n);
	matrix_1[0][0] = 1;
	matrix_1[0][1] = 2;
	matrix_1[1][0] = 3;
	matrix_1[1][1] = 4;
	matrix matrix_2(n);
	matrix_2[0][0] = 4;
	matrix_2[0][1] = 3;
	matrix_2[1][0] = 2;
	matrix_2[1][1] = 1;
	matrix matrix_3(n);
	matrix_3[0][0] = 8;
	matrix_3[0][1] = 5;
	matrix_3[1][0] = 20;
	matrix_3[1][1] = 13;

	matrix_1= matrix_1*matrix_2;

	EXPECT_EQ(matrix_3, matrix_1);
}



TEST(vector, 1)
{
	ASSERT_ANY_THROW(Vector M(-2));
}

TEST(vector, 2)
{
	int size = 3;
	double sum = 0.0;
	Vector V1(size);
	for (int i = 1; i < size; i++)
		sum += V1[i];
	ASSERT_EQ(0, sum);
}

TEST(vector, 3)
{
	int size = 3;
	double sum = 0.0;
	Vector V1(size);
	V1.vectorRand();
	for (int i = 1; i < size; i++)
		sum += V1[i];
	ASSERT_NE(0, sum);
}


TEST(vector, 4)
{
	int size = 2;
	Vector V1(size), V2(size);
	V1.vectorRand();
	V2.vectorRand();

	V2 = V1;

	EXPECT_EQ(V2, V1);
}




TEST(solver, 1)
{
	int n = 2;
	matrix matrix_1(n);
	Vector vector_1(n);
	Vector Res(n);
	Vector ResRes(n);
	matrix_1[0][0] = 1;
	matrix_1[0][1] = -1;
	matrix_1[1][0] = 2;
	matrix_1[1][1] = 1;
	vector_1[0] = -5;
	vector_1[1] = -7;
	GaussSolver systems_1(matrix_1, vector_1, n);
	Res = systems_1.gauss();
	ResRes[0] = -4;
	ResRes[1] = 1;
	EXPECT_EQ(Res, ResRes);
}