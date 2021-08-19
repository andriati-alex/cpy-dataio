/** \file screen_print.h
 *
 * \author Alex Andriati
 * \date August/2021
 * \brief Simple screen display module of numerical data
 */

#ifndef SCREEN_PRINT_H
#define SCREEN_PRINT_H

#include <complex.h>

/** \brief Print sequence of some character given */
void
print_sequence(char c, int repeat);

/** \brief Print on screen a sequence of the same character with line breaks
 *
 * \param[in] sep           the ASCII character to print
 * \param[in] repeat        number of times the character must be printed
 * \param[in] break_before  number of lines to break before separation line
 * \param[in] break_after   number of lines to break after separation line
 */
void
sepline(char sep, int repeat, int break_before, int break_after);

/** \brief Print array of double values as single-column matrix
 *
 * \param[in] arr_size          number of elements in array
 * \param[in] arr               array with real numbers
 * \param[in] compact_threshold tolerance size to print array head and tail
 * \param[in] tail_size         number of first and last elements to print
 *
 * \warning `tail_size` must be smaller than `arr_size`
 */
void
rarr_print(int arr_size, double* arr, int compact_threshold, int tail_size);

/** \brief Print array of complex values as single-column matrix
 *
 * \param[in] arr_size number of elements in array
 * \param[in] arr array with complex numbers
 * \param[in] compact_threshold tolerance size to print array head and tail
 * \param[in] tail_size number of first and last elements to print
 *
 * \warning `tail_size` must be smaller than `arr_size`
 */
void
carr_print(
    int arr_size, double complex* arr, int compact_threshold, int tail_size);

/** \brief Print on screen matrix of real numbers */
void
rmat_print(int nrows, int ncols, double** mat);

/** \brief Print on screen matrix of complex numbers */
void
cmat_print(int nrows, int ncols, double complex** mat);

/** \brief Print on screen real matrix given in row-major format
 *
 * \warning The array size must be at least \code nrows * ncols \endcode
 */
void
rrowmajor_print(int nrows, int ncols, double* arr);

/** \brief Print on screen complex matrix given in row-major format
 *
 * \warning The array size must be at least \code nrows * ncols \endcode
 */
void
crowmajor_print(int nrows, int ncols, double complex* arr);

#endif
