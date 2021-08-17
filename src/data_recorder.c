#include "data_recorder.h"
#include "file_handle.h"
#include <stdlib.h>

void
carr_stream_record(
    FILE*             f,
    char              fmt[],
    enum StartStream  in_newline,
    enum FinishStream add_linebreak,
    int               arr_size,
    double complex*   arr)
{
    assert_file_pointer(f, "carr_inline routine");
    if (in_newline) fprintf(f, "\n");
    for (int j = 0; j < arr_size; j++)
    {
        fprintf(f, fmt, creal(arr[j]), cimag(arr[j]));
    }
    if (add_linebreak) fprintf(f, "\n");
}

void
rarr_stream_record(
    FILE*             f,
    char              fmt[],
    enum StartStream  in_newline,
    enum FinishStream add_linebreak,
    int               arr_size,
    double*           arr)
{
    assert_file_pointer(f, "rarr_inline routine");
    if (in_newline) fprintf(f, "\n");
    for (int j = 0; j < arr_size; j++) fprintf(f, fmt, arr[j]);
    if (add_linebreak) fprintf(f, "\n");
}

void
carr_column_txt(char fname[], char fmt[], int arr_size, double complex* arr)
{
    FILE*  f;
    double real, imag;
    f = open_file(fname, "w");
    for (int j = 0; j < arr_size; j++)
    {
        real = creal(arr[j]);
        imag = cimag(arr[j]);
        fprintf(f, fmt, real, imag);
        fprintf(f, "\n");
    }
    fclose(f);
}

void
rarr_column_txt(char fname[], char fmt[], int arr_size, double* arr)
{
    FILE* f;
    f = open_file(fname, "w");
    for (int j = 0; j < arr_size; j++)
    {
        fprintf(f, fmt, arr[j]);
        fprintf(f, "\n");
    }
    fclose(f);
}

void
cmat_txt(char fname[], char fmt[], int nrows, int ncols, double complex** mat)
{
    FILE* f;
    f = open_file(fname, "w");
    for (int i = 0; i < nrows; i++)
    {
        carr_stream_record(f, fmt, CURSOR_POSITION, LINE_BREAK, ncols, mat[i]);
    }
    fclose(f);
}

void
cmat_append(
    char             fname[],
    char             fmt[],
    enum StartStream in_newline,
    int              nrows,
    int              ncols,
    double complex** mat)
{
    FILE* f;
    f = open_file(fname, "a");
    if (in_newline) fprintf(f, "\n");
    for (int i = 0; i < nrows; i++)
    {
        carr_stream_record(f, fmt, CURSOR_POSITION, LINE_BREAK, ncols, mat[i]);
    }
    fclose(f);
}

void
cmat_txt_transpose(
    char fname[], char fmt[], int nrows, int ncols, double complex** mat)
{
    FILE* f;
    f = open_file(fname, "w");
    for (int j = 0; j < ncols; j++)
    {
        for (int i = 0; i < nrows; i++)
        {
            fprintf(f, fmt, creal(mat[i][j]), cimag(mat[i][j]));
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

void
cmat_append_transpose(
    char             fname[],
    char             fmt[],
    enum StartStream in_newline,
    int              nrows,
    int              ncols,
    double complex** mat)
{
    FILE* f;
    f = open_file(fname, "a");
    if (in_newline) fprintf(f, "\n");
    for (int j = 0; j < ncols; j++)
    {
        for (int i = 0; i < nrows; i++)
        {
            fprintf(f, fmt, creal(mat[i][j]), cimag(mat[i][j]));
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

void
rmat_txt(char fname[], char fmt[], int nrows, int ncols, double** mat)
{
    FILE* f;
    f = open_file(fname, "w");
    for (int i = 0; i < nrows; i++)
    {
        rarr_stream_record(f, fmt, CURSOR_POSITION, LINE_BREAK, ncols, mat[i]);
    }
    fclose(f);
}

void
rmat_append(
    char             fname[],
    char             fmt[],
    enum StartStream in_newline,
    int              nrows,
    int              ncols,
    double**         mat)
{
    FILE* f;
    f = open_file(fname, "a");
    if (in_newline) fprintf(f, "\n");
    for (int i = 0; i < nrows; i++)
    {
        rarr_stream_record(f, fmt, CURSOR_POSITION, LINE_BREAK, ncols, mat[i]);
    }
    fclose(f);
}

void
rmat_txt_transpose(char fname[], char fmt[], int nrows, int ncols, double** mat)
{
    FILE* f;
    f = open_file(fname, "w");
    for (int j = 0; j < ncols; j++)
    {
        for (int i = 0; i < nrows; i++)
        {
            fprintf(f, fmt, mat[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

void
rmat_append_transpose(
    char             fname[],
    char             fmt[],
    enum StartStream in_newline,
    int              nrows,
    int              ncols,
    double**         mat)
{
    FILE* f;
    f = open_file(fname, "a");
    if (in_newline) fprintf(f, "\n");
    for (int j = 0; j < ncols; j++)
    {
        for (int i = 0; i < nrows; i++)
        {
            fprintf(f, fmt, mat[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

void
cmat_rowmajor_stream(
    FILE*             f,
    char              fmt[],
    enum StartStream  in_newline,
    enum FinishStream add_linebreak,
    int               nrows,
    int               ncols,
    double complex**  mat)
{
    assert_file_pointer(f, "cmat_rowmajor_stream routine");
    if (in_newline) fprintf(f, "\n");
    for (int i = 0; i < nrows; i++)
    {
        carr_stream_record(
            f, fmt, CURSOR_POSITION, NO_LINEBREAK, ncols, mat[i]);
    }
    if (add_linebreak) fprintf(f, "\n");
}

void
rmat_rowmajor_stream(
    FILE*             f,
    char              fmt[],
    enum StartStream  in_newline,
    enum FinishStream add_linebreak,
    int               nrows,
    int               ncols,
    double**          mat)
{
    assert_file_pointer(f, "rmat_rowmajor_stream routine");
    if (in_newline) fprintf(f, "\n");
    for (int i = 0; i < nrows; i++)
    {
        rarr_stream_record(
            f, fmt, CURSOR_POSITION, NO_LINEBREAK, ncols, mat[i]);
    }
    if (add_linebreak) fprintf(f, "\n");
}

void
cmat_rowmajor_column_txt(
    char fname[], char fmt[], int nrows, int ncols, double complex** mat)
{
    FILE* f;
    f = open_file(fname, "w");
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            fprintf(f, fmt, creal(mat[i][j]), cimag(mat[i][j]));
            fprintf(f, "\n");
        }
    }
    fclose(f);
}

void
rmat_rowmajor_column_txt(
    char fname[], char fmt[], int nrows, int ncols, double** mat)
{
    FILE* f;
    f = open_file(fname, "w");
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            fprintf(f, fmt, mat[i][j]);
            fprintf(f, "\n");
        }
    }
    fclose(f);
}

void
carr_append_stream(
    char              fname[],
    char              fmt[],
    enum StartStream  in_newline,
    enum FinishStream add_linebreak,
    int               arr_size,
    double complex*   arr)
{
    FILE* f;
    f = open_file(fname, "a");
    carr_stream_record(f, fmt, in_newline, add_linebreak, arr_size, arr);
    fclose(f);
}

void
rarr_append_stream(
    char              fname[],
    char              fmt[],
    enum StartStream  in_newline,
    enum FinishStream add_linebreak,
    int               arr_size,
    double*           arr)
{
    FILE* f;
    f = open_file(fname, "a");
    rarr_stream_record(f, fmt, in_newline, add_linebreak, arr_size, arr);
    fclose(f);
}

void
cmat_rowmajor_append_stream(
    char              fname[],
    char              fmt[],
    enum StartStream  in_newline,
    enum FinishStream add_linebreak,
    int               nrows,
    int               ncols,
    double complex**  mat)
{
    FILE* f;
    f = open_file(fname, "a");
    cmat_rowmajor_stream(f, fmt, in_newline, add_linebreak, nrows, ncols, mat);
    fclose(f);
}

void
rmat_rowmajor_append_stream(
    char              fname[],
    char              fmt[],
    enum StartStream  in_newline,
    enum FinishStream add_linebreak,
    int               nrows,
    int               ncols,
    double**          mat)
{
    FILE* f;
    f = open_file(fname, "a");
    rmat_rowmajor_stream(f, fmt, in_newline, add_linebreak, nrows, ncols, mat);
    fclose(f);
}
