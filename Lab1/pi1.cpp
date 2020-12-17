#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#define SEED 35791246
int main()
{
	int n = 0, i, count = 0;
	double z, pi, x, y;
	printf("Enter the number of iterations used to estimate pi: ");
	scanf("%d", &n);
	srand(SEED);
	double t1 = omp_get_wtime();
	#pragma omp parallel for num_threads(1)
	for (i = 0; i < n; i++) {
		x = (double)rand() / RAND_MAX;
		y = (double)rand() / RAND_MAX;
		z = x * x + y * y;
		if (z <= 1) count++;
	}
	pi = (double)count / n * 4;
	double t2 = omp_get_wtime();
	printf("Number of trials= %d , estimate of pi is %g \n", n, pi);
	printf("Time taken: %f", t2 - t1);
}