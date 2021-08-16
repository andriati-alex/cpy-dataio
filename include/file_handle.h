#ifndef FILE_HANDLE_H
#define FILE_HANDLE_H

#include <stdio.h>

/** \brief Open file to write data after check if not a NULL pointer */
FILE*
open_file_write(char fname[]);

/** \brief Open file to read data after check if not a NULL pointer */
FILE*
open_file_read(char fname[]);

/** \brief Return number of lines in a file */
unsigned int
number_of_lines(char fname[]);

/** \brief Move reading cursor of a file to next line */
void
jump_next_line(FILE* f);

/** \brief Move reading cursor until get line not starting with # */
void
jump_comment_lines(FILE* f);

#endif
