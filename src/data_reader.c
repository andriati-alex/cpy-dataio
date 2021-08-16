#include "file_handle.h"
#include <complex.h>
#include <stdlib.h>

void
carr_txt_read(char fname[], int arr_size, double* arr)
{
    int    i, n;
    double real, imag;
    FILE*  f;

    f = open_file_read(fname);
    for (i = 0; i < arr_size; i++)
    {
        n = fscanf(f, " (%lf%lfj)", &real, &imag);
        if (n != 2)
        {
            printf("\n\nERROR: Wrong number of parameters read in ");
            printf("carr_txt_read function\n\n");
            exit(EXIT_FAILURE);
        }
        arr[i] = real + I * imag;
    }
    fclose(f);
}
