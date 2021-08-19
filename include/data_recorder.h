/** \file data_recorder.h
 *
 * \author Alex Andriati
 * \date August/2021
 * \brief Module for data recording in text files
 *
 * In this module the routines provide tools for cleaner usage of file
 * writting, especially for data arrays. The module is design to offer
 * suitable interface to numpy savetxt/loadtxt functions
 *
 * The core functions are those related to **stream** keyword, which
 * require an open file to use and record array of data. The others,
 * are just wrappers to carry out the operations from file name, and
 * in most cases, it is possible to have an equivalent form with raw
 * **stream** functions
 *
 * For instance the \code carr_column_txt \endcode is equivalent to
 * first open the file and then call \code carr_stream_record \endcode
 * using the formatter with a linebreak character '\n' appended.
 */

#ifndef DATA_RECORDER_H
#define DATA_RECORDER_H

#include "file_handle.h"
#include <complex.h>
#include <stdio.h>

/** \brief Record array of complex values in open file
 *
 * All values are recorded according to the provided formatter which
 * must have at least two double pattern in string contents for real
 * and imag parts formatting
 *
 * \param f[in]          Pointer to open file
 * \param fmt[in]        String formatter with at least two double patterns
 * \param how_start[in]  Whether to place or not a linebreak before record
 * \param how_finish[in] Whether to place or not a linebreak at stream end
 * \param arr_size[in]   number of values to record
 * \param arr[in]        array with values to record
 *
 * \see enum StartStream
 * \see enum FinishStream
 * \see carr_column_txt
 */
void
carr_stream_record(
    FILE*             f,
    char              fmt[],
    enum StartStream  how_start,
    enum FinishStream how_finish,
    int               arr_size,
    double complex*   arr);

/** \brief Record array of real values in open file
 *
 * All values are recorded according to the provided formatter which
 * must have only one double pattern in string contents
 *
 * \param f[in]          Pointer to open file
 * \param fmt[in]        String formatter with only one double pattern
 * \param how_start[in]  Whether to place or not a linebreak before record
 * \param how_finish[in] Whether to place or not a linebreak at stream end
 * \param arr_size[in]   number of values to record
 * \param arr[in]        array with values to record
 *
 * \see enum StartStream
 * \see enum FinishStream
 * \see rarr_column_txt
 */
void
rarr_stream_record(
    FILE*             f,
    char              fmt[],
    enum StartStream  how_start,
    enum FinishStream how_finish,
    int               arr_size,
    double*           arr);

/** \brief Record array of complex values in a file as a column matrix
 *
 * Opens the file in write mode, thus, if it already exists will
 * be overwritten. The formatter string shall provide two double
 * patterns for real and imag parts. This routine can be engineered
 * using \code carr_stream_record \endcode with a formatter that
 * ends with a linebreak and a fresh created file to write
 *
 * \note Left a trailing line break. Remind that for further use in append
 *
 * \param fname[in]    name of full path to file
 * \param fmt[in]      formatter with two double pattern in string
 * \param arr_size[in] number of array elements to record
 * \param arr[in]      array with values to record
 *
 * \see carr_stream_record
 */
void
carr_column_txt(char fname[], char fmt[], int arr_size, double complex* arr);

/** \brief Record array of real values in a file as a column matrix
 *
 * Opens the file in write mode, thus, if it already exists will
 * be overwritten. The formatter string shall provide a single
 * double pattern. This routine can be engineered using \code
 * rarr_stream_record \endcode with a formatter that ends with a
 * linebreak and a fresh created file to write
 *
 * \note Left a trailing line break. Remind that for further use in append
 *
 * \param fname[in]    name of full path to file
 * \param fmt[in]      formatter with one double pattern in string
 * \param arr_size[in] number of array elements to record
 * \param arr[in]      array with values to record
 *
 * \see rarr_stream_record
 */
void
rarr_column_txt(char fname[], char fmt[], int arr_size, double* arr);

/** \brief Record complex matrix to text file
 *
 * Opens the file in write mode, thus, if it already exists will be
 * overwritten. Auto-use linebreaks to separate different rows. The
 * formatter must have two double pattern for real and imag parts
 *
 * \warning The formatter must also include a column separator to the
 *          left or right of number pattern. Usually it is a space
 *
 * \note Left a trailing line break. Remind it to after use in append mode
 *
 * \param fname[in] name of full path to file
 * \param fmt[in]   formatter with two double pattern in string
 * \param nrows[in] number of rows in the matrix
 * \param ncols[in] number of columns in the matrix
 * \param mat[in]   matrix with values to record
 */
void
cmat_txt(char fname[], char fmt[], int nrows, int ncols, double complex** mat);

/** \brief Record complex matrix appending to existing file
 *
 * Perform the same task of \code cmat_txt \endcode despite the file
 * is not overwritten, instead, the matrix is appended. Provides the
 * possibility to start in new line
 *
 * \warning The formatter must also include a column separator to the
 *          left or right of number pattern. Usually it is a space
 *
 * \note Left a trailing line break. Remind it to after use in append mode
 *
 * \see cmat_txt
 */
void
cmat_append(
    char             fname[],
    char             fmt[],
    enum StartStream how_start,
    int              nrows,
    int              ncols,
    double complex** mat);

/** \brief Record transpose of complex matrix to text file
 *
 * Similar to \code cmat_txt \endcode but first transpose the matrix
 *
 * \warning The formatter must also include a column separator to the
 *          left or right of number pattern. Usually it is a space
 *
 * \note Left a trailing line break. Remind it to after use in append mode
 *
 * \param fname[in] name of full path to file
 * \param fmt[in]   formatter with one double pattern in string
 * \param nrows[in] number of rows in the matrix
 * \param ncols[in] number of columns in the matrix
 * \param mat[in]   matrix with values to record
 *
 * \see cmat_txt
 */
void
cmat_txt_transpose(
    char fname[], char fmt[], int nrows, int ncols, double complex** mat);

/** \brief Record transpose of complex matrix appending to text file
 *
 * Equivalent to \code cmat_txt_transpose \endcode but if the file exists
 * it is not overwritten, instead, the matrix is appended. Also, provides
 * the possibility to start appending in new line
 *
 * \warning The formatter must also include a column separator to the
 *          left or right of number pattern. Usually it is a space
 *
 * \note Left a trailing line break. Remind it to after use in append mode
 *
 * \see cmat_txt_transpose
 */
void
cmat_append_transpose(
    char             fname[],
    char             fmt[],
    enum StartStream how_start,
    int              nrows,
    int              ncols,
    double complex** mat);

/** \brief Record real matrix to text file
 *
 * Opens the file in write mode, thus, if it already exists will be
 * overwritten. Auto-use linebreaks to separate different rows. The
 * formatter must have a single double pattern
 *
 * \warning The formatter must also include a column separator to the
 *          left or right of number pattern. Usually it is a space
 *
 * \note Left a trailing line break. Remind it to after use in append mode
 *
 * \param fname[in] name of full path to file
 * \param fmt[in]   formatter with two double pattern in string
 * \param nrows[in] number of rows in the matrix
 * \param ncols[in] number of columns in the matrix
 * \param mat[in]   matrix with values to record
 */
void
rmat_txt(char fname[], char fmt[], int nrows, int ncols, double** mat);

/** \brief Record real matrix appending to existing file
 *
 * Perform the same task of \code rmat_txt \endcode despite the file
 * is not overwritten, instead, the matrix is appended. Provides the
 * possibility to start in new line
 *
 * \warning The formatter must also include a column separator to the
 *          left or right of number pattern. Usually it is a space
 *
 * \note Left a trailing line break. Remind it to after use in append mode
 *
 * \see rmat_txt
 */
void
rmat_append(
    char             fname[],
    char             fmt[],
    enum StartStream how_start,
    int              nrows,
    int              ncols,
    double**         mat);

/** \brief Record transpose of real matrix to text file
 *
 * Similar to \code rmat_txt \endcode but first transpose the matrix
 *
 * \see rmat_txt
 *
 * \warning The formatter must also include a column separator to the
 *          left or right of number pattern. Usually it is a space
 *
 * \note Left a trailing line break. Remind it to after use in append mode
 *
 * \param fname[in] name of full path to file
 * \param fmt[in]   formatter with one double pattern in string
 * \param nrows[in] number of rows in the matrix
 * \param ncols[in] number of columns in the matrix
 * \param mat[in]   matrix with values to record
 */
void
rmat_txt_transpose(
    char fname[], char fmt[], int nrows, int ncols, double** mat);

/** \brief Record transpose of real matrix appending to text file
 *
 * Equivalent to \code rmat_txt_transpose \endcode but if the file exists
 * it is not overwritten, instead, the matrix is appended. Also, provides
 * the possibility to start appending in new line
 *
 * \warning The formatter must also include a column separator to the
 *          left or right of number pattern. Usually it is a space
 *
 * \note Left a trailing line break. Remind it to after use in append mode
 *
 * \see rmat_txt_transpose
 */
void
rmat_append_transpose(
    char             fname[],
    char             fmt[],
    enum StartStream how_start,
    int              nrows,
    int              ncols,
    double**         mat);

/** \brief Record stream of values from complex matrix in rowmajor format
 *
 * Equivalent to set the matrix in rowmajor format and call
 * \code carr_stream_record \endcode which provide the same
 * function signature except for the matrix input
 *
 * \see carr_stream_record
 */
void
cmat_rowmajor_stream(
    FILE*             f,
    char              fmt[],
    enum StartStream  how_start,
    enum FinishStream how_finish,
    int               nrows,
    int               ncols,
    double complex**  mat);

/** \brief Record stream of values from real matrix in rowmajor format
 *
 * Equivalent to set the matrix in rowmajor format and call
 * \code rarr_stream_record \endcode which provide the same
 * function signature except for the matrix input
 *
 * \see rarr_stream_record
 */
void
rmat_rowmajor_stream(
    FILE*             f,
    char              fmt[],
    enum StartStream  how_start,
    enum FinishStream how_finish,
    int               nrows,
    int               ncols,
    double**          mat);

/** \brief Record compelx matrix in rowmajor-array format as column matrix
 *
 * Wrapper routine to record a matrix as column vector which is the
 * rowmajor format of the matrix. Equivalent to create the rowmajor
 * format in an array and use \code carr_column_txt \endcode
 *
 * \see carr_column_txt
 */
void
cmat_rowmajor_column_txt(
    char fname[], char fmt[], int nrows, int ncols, double complex** mat);

/** \brief Record real matrix in rowmajor-array format as column matrix
 *
 * Wrapper routine to record a matrix as column vector which is the
 * rowmajor format of the matrix. Equivalent to create the rowmajor
 * format in an array and use \code rarr_column_txt \endcode
 *
 * \see rarr_column_txt
 */
void
rmat_rowmajor_column_txt(
    char fname[], char fmt[], int nrows, int ncols, double** mat);

/** \brief Append to existing file stream of complex values
 *
 * Wrapper routine to call \code carr_stream_record \endcode
 * with a file open in append mode using file name
 *
 * \see carr_stream_record
 */
void
carr_append_stream(
    char              fname[],
    char              fmt[],
    enum StartStream  how_start,
    enum FinishStream how_finish,
    int               arr_size,
    double complex*   arr);

/** \brief Append to existing file stream of real values
 *
 * Wrapper routine to call \code rarr_stream_record \endcode
 * with a file open in append mode using file name
 *
 * \see rarr_stream_record
 */
void
rarr_append_stream(
    char              fname[],
    char              fmt[],
    enum StartStream  how_start,
    enum FinishStream how_finish,
    int               arr_size,
    double*           arr);

/** \brief Append complex matrix using rowmajor format
 *
 * Wrapper routine to call \code cmat_rowmajor_stream \endcode
 * with a file open in append mode using file name
 *
 * \see cmat_rowmajor_stream
 */
void
cmat_rowmajor_append_stream(
    char              fname[],
    char              fmt[],
    enum StartStream  how_start,
    enum FinishStream how_finish,
    int               nrows,
    int               ncols,
    double complex**  mat);

/** \brief Append real matrix using rowmajor format
 *
 * Wrapper routine to call \code rmat_rowmajor_stream \endcode
 * with a file open in append mode using file name
 *
 * \see rmat_rowmajor_stream
 */
void
rmat_rowmajor_append_stream(
    char              fname[],
    char              fmt[],
    enum StartStream  how_start,
    enum FinishStream how_finish,
    int               nrows,
    int               ncols,
    double**          mat);

#endif
