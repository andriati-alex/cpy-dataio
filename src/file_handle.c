#include "file_handle.h"
#include <stdlib.h>

char comment_char = DEFAULT_COMMENT_CHAR;

void
assert_file_pointer(FILE* f, char client_msg[])
{
    if (f == NULL)
    {
        printf("\n\nERROR: Got a NULL file pointer: %s\n\n", client_msg);
        exit(EXIT_FAILURE);
    }
}

FILE*
open_file(char fname[], char mode[])
{
    FILE* f;
    f = fopen(fname, mode);
    if (f == NULL)
    {
        printf("\n\nERROR: impossible to open file %s for %s\n\n", fname, mode);
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
    f = open_file(fname, "r");
    jump_comment_lines(f, CURSOR_POSITION);
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
jump_comment_lines(FILE* f, enum StartStream in_newline)
{
    char c;

    if (in_newline) jump_next_line(f);
    while ((c = getc(f)) != EOF)
    {
        if (c == '\n' || c == ' ') continue;
        if (c == comment_char)
        {
            jump_next_line(f);
        } else
        {
            fseek(f, -1, SEEK_CUR);
            return;
        }
    }
}
