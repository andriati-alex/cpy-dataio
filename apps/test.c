#include "cpydataio.h"

#define ARR_SIZE 8
char comment_char = '*';

int
main()
{
    char   fname[80];
    double arr[ARR_SIZE];

    printf("\nProvide input text file (full path) with array values: ");
    scanf("%s", fname);
    printf("File %s has:\n", fname);
    printf("\t%2d lines ignoring comments\n", number_of_lines(fname, FALSE));
    printf("\t%2d lines counting comments\n", number_of_lines(fname, TRUE));
    rarr_txt_read(fname, "%lf", 1, ARR_SIZE, arr);
    printf("\nProvide output text file (full path) to record values: ");
    scanf("%s", fname);
    rarr_append_stream(
        fname,
        REAL_SCIFMT_SPACE_BEFORE,
        CURSOR_POSITION,
        NO_LINEBREAK,
        ARR_SIZE,
        arr);

    printf("\n\nTest done\n\n");
    return 0;
}
