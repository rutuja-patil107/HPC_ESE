#include <stdio.h>
#include <omp.h>
#define N 5
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t start, end;
    start = clock();
    int i, j;
#pragma omp parallel for num_threads(10) shared(i, j)
    for (i = N; i >= 1; i--)
    {
        for (j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    end = clock();
    double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
    printf("\nTime taken : %0.6f\n", time_taken);
}