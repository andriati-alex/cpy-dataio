/** \file data_reader.h
 *
 * \author Alex Andriati
 * \date August/2021
 * \brief Numerical data reading from text files
 *
 * In general, the routines share a common API requiring file name,
 * formatter, line to start reading and array/matrix information
 *
 */

#include <complex.h>
#include <stdio.h>

/** \brief Read consecutive formatted complex numbers from text file
 *
 * \param[in] fname     full path to the file
 * \param[in] fmt       string formatter for every fscanf
 * \param[in] init_line in which line to start (ignoring comment lines)
 * \param[in] arr_size  number of consecutive readings
 * \param[out] arr      array to record values read
 */
void
carr_txt_read(
    char fname[], char fmt[], int init_line, int arr_size, double complex* arr);

/** \brief Read consecutive formatted float numbers from text file
 *
 * \param[in] fname     full path to the file
 * \param[in] fmt       string formatter for every fscanf
 * \param[in] init_line in which line to start (ignoring comment lines)
 * \param[in] arr_size  number of consecutive readings
 * \param[out] arr      array to record values read
 */
void
rarr_txt_read(
    char fname[], char fmt[], int init_line, int arr_size, double* arr);

/** \brief Read consecutive formatted complex numbers from open file
 *
 * \param[in] f        pointer to open reading file
 * \param[in] fmt      string formatter for every fscanf
 * \param[in] arr_size number of consecutive readings
 * \param[out] arr     array to record values read
 */
void
carr_stream_read(FILE* f, char fmt[], int arr_size, double complex* arr);

/** \brief Read consecutive formatted float numbers from open file
 *
 * \param[in] f        pointer to open reading file
 * \param[in] fmt      string formatter for every scanf
 * \param[in] arr_size number of consecutive readings
 * \param[out] arr     array to record values read
 */
void
rarr_stream_read(FILE* f, char fmt[], int arr_size, double* arr);

/** \brief Read consecutive formatted complex numbers to set a matrix
 *
 * \param[in] fname     full path to text file
 * \param[in] fmt       string formatter for every scanf
 * \param[in] init_line line number to start reading
 * \param[in] nrows     number of rows in the matrix
 * \param[in] ncols     number of columns in the matrix
 * \param[out] mat      matrix to set with values read
 */
void
cmat_txt_read(
    char   fname[],
    char   fmt[],
    int    init_line,
    int    nrows,
    int    ncols,
    double complex** mat);

/** \brief Read consecutive formatted float numbers to set a matrix
 *
 * \param[in] fname     full path to text file
 * \param[in] fmt       string formatter for every scanf
 * \param[in] init_line line number to start reading
 * \param[in] nrows     number of rows in the matrix
 * \param[in] ncols     number of columns in the matrix
 * \param[out] mat      matrix to set with values read
 */
void
rmat_txt_read(
    char     fname[],
    char     fmt[],
    int      init_line,
    int      nrows,
    int      ncols,
    double** mat);
