// lab00.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>

using namespace std;

void testas(int N);

int main()
{
	testas(1000);
	return 0;
}

void testas(int N) {
	double* B = new double[N];
	double* C = new double[N];
	double** A = new double* [N];
	for (int i = 0; i < N; i++)
		A[i] = new double[N];

	for (int i = 0; i < N; i++)
		B[i] = 3 * i + 100;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			A[i][j] = 600 + i + j;

	int K = 100;
	clock_t t1, t2;
	//alg1
	t1 = clock();
	for (int l = 0; l < K; l++)
	{
		for (int i = 0; i < N; i++)
			C[i] = 0;
		for (int i = 0; i < N; i++)
			for (int k = 0; k < N; k++)
				C[i] += A[i][k] * B[k];
	}
	t2 = clock();
	cout << "Laikas: " <<
		(double)(t2 - t1) / (double)CLOCKS_PER_SEC / (double)K
		<< endl;
	//alg2
	t1 = clock();
	for (int l = 0; l < K; l++)
	{
		for (int i = 0; i < N; i++)
			C[i] = 0;
		for (int k = 0; k < N; k++)
			for (int i = 0; i < N; i++)
				C[i] += A[i][k] * B[k];
	}
	t2 = clock();
	cout << "Laikas: " <<
		(double)(t2 - t1) / (double)CLOCKS_PER_SEC / (double)K
		<< endl;


	for (int i = 0; i < N; i++)
		delete[]A[i];
	delete[]A;
	delete[]C;
	delete[]B;
}
