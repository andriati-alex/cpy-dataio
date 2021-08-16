#ifndef DATA_RECORDER_H
#define DATA_RECORDER_H

#include <complex.h>
#include <stdio.h>

/** \brief Record array of values in a file as a column matrix */
void
carr_column_txt(char fname[], int arr_size, double complex* arr);

/** \brief Record array of values in a file as a column matrix */
void
rarr_column_txt(char fname[], int arr_size, double* arr);

/** \brief Record array of values in current line of open file
 *
 * After values are recorded introduce a linebreak. If a
 * NULL pointer is given exit client program with error.
 */
void
carr_inline(FILE* f, int arr_size, double complex* arr);

/** \brief Record array of values in current line of open file
 *
 * After values are recorded introduce a linebreak. If a
 * NULL pointer is given exit client program with error.
 */
void
rarr_inline(FILE* f, int arr_size, double* arr);

/** \brief Record matrix to text file */
void
cmat_txt(char fname[], int nrows, int ncols, double complex** mat);

/** \brief Transpose and then record a matrix to text file */
void
cmat_txt_transpose(char fname[], int nrows, int ncols, double complex** mat);

/** \brief Record matrix to text file */
void
rmat_txt(char fname[], int nrows, int ncols, double** mat);

/** \brief Transpose and then record a matrix to text file */
void
rmat_txt_transpose(char fname[], int nrows, int ncols, double** mat);

/** \brief Record all matrix values in current line of open file
 *
 * The values are recorded in row-major format, such that the values
 * along lines are contiguous. This is equivalent to have the matrix
 * in row-major format and record the resulting array in a line
 *
 * \see carr_inline
 */
void
cmat_inline_rowmajor(FILE* f, int nrows, int ncols, double complex** mat);

/** \brief Record all matrix values in current line of open file
 *
 * The values are recorded in row-major format, such that the values
 * along lines are contiguous. This is equivalent to have the matrix
 * in row-major format and record the resulting array in a line
 *
 * \see rarr_inline
 */
void
rmat_inline_rowmajor(FILE* f, int nrows, int ncols, double** mat);

#endif
