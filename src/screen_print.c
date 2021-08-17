#include "screen_print.h"
#include <stdio.h>
#include <stdlib.h>

static void
cprint(double complex z)
{
    printf("(%9.2E,%9.2E )", creal(z), cimag(z));
}

static void
rprint(double x)
{
    printf("%9.2E", x);
}

void
print_sequence(char c, int repeat)
{
    for (int i = 0; i < repeat; i++) printf("%c", c);
}

void
sepline(char sep, int repeat, int break_before, int break_after)
{
    int i;
    for (i = 0; i < break_before; i++) printf("\n");
    print_sequence(sep, repeat);
    for (i = 0; i < break_after; i++) printf("\n");
}

void
rarr_print(int arr_size, double* arr, int compact_threshold, int tail_size)
{
    int i;

    if (arr_size < compact_threshold)
    {
        for (i = 0; i < arr_size; i++)
        {
            printf("\n\t");
            rprint(arr[i]);
        }
        printf("\n");
        return;
    }
    // print first and last `tail_size` elements for long arrays
    if (tail_size > arr_size)
    {
        printf("\n\nERROR: tail size to print is larger than array size: ");
        printf("Exiting in function rarr_print\n\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < tail_size; i++)
    {
        printf("\n\t");
        rprint(arr[i]);
    }
    for (i = 0; i < 5; i++)
    {
        printf("\n\t\t");
        printf(".");
    }
    for (i = arr_size - tail_size; i < arr_size; i++)
    {
        printf("\n\t");
        rprint(arr[i]);
    }
    printf("\n");
}

void
carr_print(
    int arr_size, double complex* arr, int compact_threshold, int tail_size)
{
    int i;

    if (arr_size < compact_threshold)
    {
        for (i = 0; i < arr_size; i++)
        {
            printf("\n\t");
            cprint(arr[i]);
        }
        printf("\n");
        return;
    }
    // print first and last `tail_size` elements for long arrays
    if (tail_size > arr_size)
    {
        printf("\n\nERROR: tail size to print is larger than array size: ");
        printf("Exiting in function carr_print\n\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < tail_size; i++)
    {
        printf("\n\t");
        cprint(arr[i]);
    }
    for (i = 0; i < 5; i++)
    {
        printf("\n\t\t");
        printf(".");
    }
    for (i = arr_size - tail_size; i < arr_size; i++)
    {
        printf("\n\t");
        cprint(arr[i]);
    }
    printf("\n");
}

void
rmat_print(int nrows, int ncols, double** M)
{
    for (int i = 0; i < nrows; i++)
    {
        printf("\n");
        for (int j = 0; j < ncols; j++)
        {
            printf("  ");
            rprint(M[i][j]);
        }
    }
    printf("\n");
}

void
cmat_print(int nrows, int ncols, double complex** M)
{
    for (int i = 0; i < nrows; i++)
    {
        printf("\n");
        for (int j = 0; j < ncols; j++)
        {
            printf("  ");
            cprint(M[i][j]);
        }
    }
    printf("\n");
}

void
rrowmajor_print(int nrows, int ncols, double* arr)
{
    for (int i = 0; i < nrows; i++)
    {
        printf("\n");
        for (int j = 0; j < ncols; j++)
        {
            printf("  ");
            rprint(arr[i * ncols + j]);
        }
    }
    printf("\n");
}

void
crowmajor_print(int nrows, int ncols, double complex* arr)
{
    for (int i = 0; i < nrows; i++)
    {
        printf("\n");
        for (int j = 0; j < ncols; j++)
        {
            printf("  ");
            cprint(arr[i * ncols + j]);
        }
    }
    printf("\n");
}
