#include "file_handle.h"
#include <stdlib.h>

FILE*
open_file_write(char fname[])
{
    FILE* f;
    f = fopen(fname, "w");
    if (f == NULL)
    {
        printf("\n\nERROR: impossible to open file %s\n\n", fname);
        exit(EXIT_FAILURE);
    }
    return f;
}

FILE*
open_file_read(char fname[])
{
    FILE* f;
    f = fopen(fname, "r");
    if (f == NULL)
    {
        printf("\n\nERROR: impossible to open file %s\n\n", fname);
        exit(EXIT_FAILURE);
    }
    return f;
}

unsigned int
number_of_lines(char fname[])
{
    char         c;
    FILE*        f;
    unsigned int linebreaks, has_end_linebreak;

    linebreaks = 0;
    has_end_linebreak = 0;
    f = open_file_read(fname);
    while ((c = getc(f)) != EOF)
    {
        has_end_linebreak = 0;
        if (c == '\n')
        {
            linebreaks++;
            has_end_linebreak = 1;
        }
    }
    fclose(f);
    if (has_end_linebreak) return linebreaks;
    return linebreaks + 1;
}

void
jump_next_line(FILE* f)
{
    char c;
    while ((c = getc(f)) != EOF)
    {
        if (c == '\n') return;
    }
}

void
jump_comment_lines(FILE* f)
{
    char c;

    while ((c = getc(f)) != EOF)
    {
        if (c == '\n') continue;
        if (c == '#')
        {
            jump_next_line(f);
        } else
        {
            fseek(f, -1, SEEK_CUR);
            return;
        }
    }
}
