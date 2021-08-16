#include "file_handle.h"
#include "data_recorder.h"
#include <stdlib.h>

void
carr_column_txt(char fname[], int arr_size, double complex* arr)
{
    FILE*  f;
    double real, imag;

    f = open_file_write(fname);
    for (int j = 0; j < arr_size; j++)
    {
        real = creal(arr[j]);
        imag = cimag(arr[j]);
        if (imag >= 0)
            fprintf(f, "(%.15E+%.15Ej)", real, imag);
        else
            fprintf(f, "(%.15E%.15Ej)", real, imag);
        fprintf(f, "\n");
    }
    fclose(f);
}

void
rarr_column_txt(char fname[], int arr_size, double* arr)
{
    FILE* f;

    f = open_file_write(fname);
    for (int j = 0; j < arr_size; j++)
    {
        fprintf(f, "%.15E\n", arr[j]);
    }
    fclose(f);
}

void
carr_inline(FILE* f, int arr_size, double complex* arr)
{
    double real, imag;

    if (f == NULL)
    {
        printf("\n\nERROR: NULL file provided in carr_inline routine\n\n");
        exit(EXIT_FAILURE);
    }

    for (int j = 0; j < arr_size; j++)
    {
        real = creal(arr[j]);
        imag = cimag(arr[j]);
        if (imag >= 0)
            fprintf(f, " (%.15E+%.15Ej)", real, imag);
        else
            fprintf(f, " (%.15E%.15Ej)", real, imag);
    }
    fprintf(f, "\n");
}

void
rarr_inline(FILE* f, int arr_size, double* arr)
{
    if (f == NULL)
    {
        printf("\n\nERROR: NULL file provided in rarr_inline routine\n\n");
        exit(EXIT_FAILURE);
    }

    for (int j = 0; j < arr_size; j++) fprintf(f, " %.15E", arr[j]);
    fprintf(f, "\n");
}

void
cmat_txt(char fname[], int nrows, int ncols, double complex** mat)
{
    double real, imag;
    FILE*  f;

    f = open_file_write(fname);

    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            real = creal(mat[i][j]);
            imag = cimag(mat[i][j]);
            if (imag >= 0)
                fprintf(f, " (%.15E+%.15Ej)", real, imag);
            else
                fprintf(f, " (%.15E%.15Ej)", real, imag);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

void
cmat_txt_transpose(char fname[], int nrows, int ncols, double complex** mat)
{
    double real, imag;
    FILE* f;

    f = open_file_write(fname);

    for (int j = 0; j < ncols; j++)
    {
        for (int i = 0; i < nrows; i++)
        {
            real = creal(mat[i][j]);
            imag = cimag(mat[i][j]);
            if (imag >= 0)
                fprintf(f, " (%.15E+%.15Ej)", real, imag);
            else
                fprintf(f, " (%.15E%.15Ej)", real, imag);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

void
rmat_txt(char fname[], int nrows, int ncols, double** mat)
{
    FILE*  f;

    f = open_file_write(fname);

    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            fprintf(f, " %.15E", mat[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

void
rmat_txt_transpose(char fname[], int nrows, int ncols, double** mat)
{
    FILE* f;

    f = open_file_write(fname);

    for (int j = 0; j < ncols; j++)
    {
        for (int i = 0; i < nrows; i++)
        {
            fprintf(f, " %.15E", mat[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

void
cmat_inline_rowmajor(FILE* f, int nrows, int ncols, double complex** mat)
{
    double real, imag;

    if (f == NULL)
    {
        printf("\n\nERROR: NULL file pointer in cmat_inline\n\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            real = creal(mat[i][j]);
            imag = cimag(mat[i][j]);
            if (imag >= 0)
                fprintf(f, " (%.15E+%.15Ej)", real, imag);
            else
                fprintf(f, " (%.15E%.15Ej)", real, imag);
        }
    }
    fprintf(f, "\n");
}

void
rmat_inline_rowmajor(FILE* f, int nrows, int ncols, double** mat)
{
    if (f == NULL)
    {
        printf("\n\nERROR: NULL file pointer in rmat_inline\n\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            fprintf(f, " %.15E", mat[i][j]);
        }
    }
    fprintf(f, "\n");
}
