#include <stdio.h>
#include <complex.h>

/** \brief Read consecutive formatted complex numbers from text file
 *
 * \param[in] fname full path to the file
 * \param[in] arr_size pointer size : number of consecutive readings
 * \param[in] fmt string formatter for every scanf
 * \param[out] arr array to record values read
 */
void
carr_txt_read(char fname[], int arr_size, char const fmt[], double complex* arr);

/** \brief Read consecutive formatted float numbers from text file
 *
 * \param[in] fname full path to the file
 * \param[in] arr_size pointer size : number of consecutive readings
 * \param[in] fmt string formatter for every scanf
 * \param[out] arr array to record values read
 */
void
rarr_txt_read(char fname[], int arr_size, double* arr, char const fmt[]);

/** \brief Read consecutive formatted complex numbers from open file
 *
 * \param[in] f pointer to open reading file
 * \param[in] arr_size pointer size : number of consecutive readings
 * \param[in] fmt string formatter for every scanf
 * \param[out] arr array to record values read
 */
void
carr_stream_read(FILE* f, int arr_size, double complex* arr, char const fmt[]);

/** \brief Read consecutive formatted float numbers from open file
 *
 * \param[in] f pointer to open reading file
 * \param[in] arr_size pointer size : number of consecutive readings
 * \param[in] fmt string formatter for every scanf
 * \param[out] arr array to record values read
 */
void
rarr_stream_read(FILE* f, int arr_size, double* arr, char const fmt[]);

/** \brief Read consecutive formatted complex numbers to set a matrix
 *
 * \param[in] f full path to text file
 * \param[in] nrows number of rows in the matrix
 * \param[in] ncols number of columns in the matrix
 * \param[in] fmt string formatter for every scanf
 * \param[out] mat matrix to set with values read
 */
void
cmat_txt_read(
    char fname[], int nrows, int ncols, char const fmt[], double complex** mat);

/** \brief Read consecutive formatted float numbers to set a matrix
 *
 * \param[in] f full path to text file
 * \param[in] nrows number of rows in the matrix
 * \param[in] ncols number of columns in the matrix
 * \param[in] fmt string formatter for every scanf
 * \param[out] mat matrix to set with values read
 */
void
rmat_txt_read(
    char fname[], int nrows, int ncols, char const fmt[], double** mat);
