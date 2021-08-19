/** \file test.c
 *
 * \author Alex Andriati
 * \date August/2021
 * \brief Simple executable to test the lib
 *
 * Read some files in \code test_files \endcode directory and record their
 * contents in new files using some of the functions provided in the lib
 */

#include "cpydataio.h"
#include <stdlib.h>

#define ARR_SIZE 8
char comment_char = '*';

int
main()
{
    char rarr_fname_in[] = "test_files/real_array_inp.dat",
         rarr_fname_out[] = "test_files/real_array_out.dat",
         carr_fname_in[] = "test_files/complex_array_inp.dat",
         carr_fname_out[] = "test_files/complex_array_out.dat",
         rmat_fname_in[] = "test_files/real_matrix_inp.dat",
         rmat_fname_out[] = "test_files/real_matrix_out.dat",
         cmat_fname_in[] = "test_files/complex_matrix_inp.dat",
         cmat_fname_out[] = "test_files/complex_matrix_out.dat";

    double           rarr[ARR_SIZE];
    double complex   carr[ARR_SIZE];
    double**         rmat;
    double complex** cmat;

    rmat = (double**) malloc(3 * sizeof(double*));
    for (int i = 0; i < 3; i++) rmat[i] = (double*) malloc(4 * sizeof(double));

    cmat = (double complex**) malloc(4 * sizeof(double complex*));
    for (int i = 0; i < 4; i++)
        cmat[i] = (double complex*) malloc(3 * sizeof(double complex));

    rarr_txt_read(rarr_fname_in, "%lf", 1, ARR_SIZE, rarr);
    rarr_column_txt(rarr_fname_out, REAL_SCIFMT_NOSPACE, ARR_SIZE, rarr);
    rarr_append_stream(
        rarr_fname_out,
        REAL_SCIFMT_SPACE_BEFORE,
        CURSOR_POSITION,
        NO_LINEBREAK,
        ARR_SIZE,
        rarr);

    carr_txt_read(carr_fname_in, " (%lf%lfj)", 1, ARR_SIZE, carr);
    carr_column_txt(carr_fname_out, CPLX_SCIFMT_NOSPACE, ARR_SIZE, carr);
    carr_append_stream(
        carr_fname_out,
        CPLX_SCIFMT_SPACE_BEFORE,
        CURSOR_POSITION,
        NO_LINEBREAK,
        ARR_SIZE,
        carr);

    rmat_txt_read(rmat_fname_in, "%lf", 1, 3, 4, (double**) rmat);
    rmat_txt(rmat_fname_out, REAL_SCIFMT_SPACE_BEFORE, 3, 4, rmat);
    rmat_append(
        rmat_fname_out, REAL_SCIFMT_SPACE_BEFORE, CURSOR_POSITION, 3, 4, rmat);
    rmat_rowmajor_append_stream(
        rmat_fname_out,
        REAL_SCIFMT_LINEBREAK,
        CURSOR_POSITION,
        NO_LINEBREAK,
        3,
        4,
        rmat);

    cmat_txt_read(cmat_fname_in, " (%lf%lfj) ", 1, 4, 3, cmat);
    cmat_txt(cmat_fname_out, CPLX_SCIFMT_SPACE_BEFORE, 4, 3, cmat);
    cmat_append(
        cmat_fname_out, CPLX_SCIFMT_SPACE_BEFORE, CURSOR_POSITION, 4, 3, cmat);
    cmat_rowmajor_append_stream(
        cmat_fname_out,
        CPLX_SCIFMT_LINEBREAK,
        CURSOR_POSITION,
        NO_LINEBREAK,
        4,
        3,
        cmat);

    for (int i = 0; i < 3; i++) free(rmat[i]);
    for (int i = 0; i < 4; i++) free(cmat[i]);
    free(rmat);
    free(cmat);

    printf("\nTest done\n\n");
    return 0;
}
