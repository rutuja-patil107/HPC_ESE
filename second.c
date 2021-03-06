#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int size, rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int localsum[2] = {0, 0};
    int globalsum[2] = {0, 0};

    if (rank % 2 == 1)
    {
        localsum[0] += 5;
    }
    else if (rank > 0 && (rank % 2 == 0))
    {
        localsum[1] += 10;
    }

    MPI_Reduce(localsum, globalsum, 2, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("sum at odd indices = %d \n", globalsum[0]);
        printf("sum at even indices = %d \n", globalsum[1]);
    }

    MPI_Finalize();

    return (EXIT_SUCCESS);
}