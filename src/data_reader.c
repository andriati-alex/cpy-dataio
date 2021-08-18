#include "file_handle.h"
#include "data_reader.h"
#include <stdlib.h>

static const unsigned int BUFF_SIZE = 256;

static void
report_array_read_problem(FILE* f, int index, int arr_size, char info[])
{
    fclose(f);
    printf(
        "\n\nERROR: Problem reading element %d of %d: %s\n\n",
        index,
        arr_size,
        info);
    exit(EXIT_FAILURE);
}

void
carr_txt_read(
    char fname[], char fmt[], int init_line, int arr_size, double complex* arr)
{
    int    i, n;
    double real, imag;
    FILE*  f;

    f = open_file(fname, "r");
    jump_comment_lines(f, CURSOR_POSITION);
    while (--init_line > 0) jump_next_line(f);
    for (i = 0; i < arr_size; i++)
    {
        n = fscanf(f, fmt, &real, &imag);
        if (n != 2)
        {
            char err_info[BUFF_SIZE];
            sprintf(err_info, "Reading complex numbers from %s", fname);
            report_array_read_problem(f, i, arr_size, err_info);
        }
        arr[i] = real + I * imag;
    }
    fclose(f);
}

void
rarr_txt_read(
    char fname[], char fmt[], int init_line, int arr_size, double* arr)
{
    int   i, n;
    FILE* f;

    f = open_file(fname, "r");
    jump_comment_lines(f, CURSOR_POSITION);
    while (--init_line > 0) jump_next_line(f);
    for (i = 0; i < arr_size; i++)
    {
        n = fscanf(f, fmt, &arr[i]);
        if (n != 1)
        {
            char err_info[BUFF_SIZE];
            sprintf(err_info, "Reading float numbers from %s", fname);
            report_array_read_problem(f, i, arr_size, err_info);
        }
    }
    fclose(f);
}

void
carr_stream_read(FILE* f, char fmt[], int arr_size, double complex* arr)
{
    int    i, n;
    double real, imag;

    assert_file_pointer(f, "In function carr_stream_read");
    for (i = 0; i < arr_size; i++)
    {
        n = fscanf(f, fmt, &real, &imag);
        if (n != 2)
        {
            char err_info[] = "Reading from file pointer in carr_stream_read";
            report_array_read_problem(f, i, arr_size, err_info);
        }
        arr[i] = real + I * imag;
    }
}

void
rarr_stream_read(FILE* f, char fmt[], int arr_size, double* arr)
{
    int i, n;

    assert_file_pointer(f, "In function rarr_stream_read");
    for (i = 0; i < arr_size; i++)
    {
        n = fscanf(f, fmt, &arr[i]);
        if (n != 1)
        {
            char err_info[] = "Reading from file pointer in rarr_stream_read";
            report_array_read_problem(f, i, arr_size, err_info);
        }
    }
}

void
cmat_txt_read(
    char   fname[],
    char   fmt[],
    int    init_line,
    int    nrows,
    int    ncols,
    double complex** mat)
{
    int    i, j, n;
    double real, imag;
    FILE*  f;

    f = open_file(fname, "r");
    jump_comment_lines(f, CURSOR_POSITION);
    while (--init_line > 0) jump_next_line(f);
    for (i = 0; i < nrows; i++)
    {
        for (j = 0; j < ncols; j++)
        {
            n = fscanf(f, fmt, &real, &imag);
            if (n != 2)
            {
                char err_info[BUFF_SIZE];
                sprintf(
                    err_info,
                    "Reading row %d and col %d of complex matrix",
                    i + 1,
                    j + 1);
                report_array_read_problem(
                    f, i * ncols + j, nrows * ncols, err_info);
            }
            mat[i][j] = real + I * imag;
        }
    }
    fclose(f);
}

void
rmat_txt_read(
    char fname[], char fmt[], int init_line, int nrows, int ncols, double** mat)
{
    int   i, j, n;
    FILE* f;

    f = open_file(fname, "r");
    jump_comment_lines(f, CURSOR_POSITION);
    while (--init_line > 0) jump_next_line(f);
    for (i = 0; i < nrows; i++)
    {
        for (j = 0; j < ncols; j++)
        {
            n = fscanf(f, fmt, &mat[i][j]);
            if (n != 1)
            {
                char err_info[BUFF_SIZE];
                sprintf(
                    err_info,
                    "Reading row %d col %d of real matrix",
                    i + 1,
                    j + 1);
                report_array_read_problem(
                    f, i * ncols + j, nrows * ncols, err_info);
            }
        }
    }
    fclose(f);
}
