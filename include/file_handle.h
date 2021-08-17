/** \file file_handle.h
 *
 * \author Alex Andriati
 * \date Aug/2021
 * \brief Simple improved toolbox to easier use files
 *
 * Some macros are provided to provide a better integration with numpy
 * formmating string to read and write complex numbers using brackets
 * and \code j \endcode as the imaginary unit. By default, the macros
 * provide 15 decimal places, according to C double precision
 */

#ifndef FILE_HANDLE_H
#define FILE_HANDLE_H

#include <stdio.h>

/** \brief How to start operation in open file: CURSOR_POSITION/NEXT_LINE */
enum StartStream
{
    CURSOR_POSITION,
    NEXT_LINE
};

/** \brief How to finish operation in open file: NO_LINEBREAK/LINEBREAK */
enum FinishStream
{
    NO_LINEBREAK,
    LINE_BREAK
};

#define CPLX_FMT_SPACE_BOTH   " (%.15E%+.15Ej) " /// " (%.15E%+.15Ej) "
#define CPLX_FMT_SPACE_BEFORE " (%.15E%+.15Ej)"  /// " (%.15E%+.15Ej)"
#define CPLX_FMT_SPACE_AFTER  "(%.15E%+.15Ej) "  /// "(%.15E%+.15Ej) "
#define CPLX_FMT_NOSPACE      "(%.15E%+.15Ej)"   /// "(%.15E%+.15Ej)"
#define CPLX_FMT_LINEBREAK    "(%.15E%+.15Ej)\n" /// "(%.15E%+.15Ej)\n"
#define REAL_FMT_SPACE_BOTH   " %.15E "          /// " %.15E "
#define REAL_FMT_SPACE_BEFORE " %.15E"           /// " %.15E"
#define REAL_FMT_SPACE_AFTER  "%.15E "           /// "%.15E "
#define REAL_FMT_NOSPACE      "%.15E"            /// "%.15E"
#define REAL_FMT_LINEBREAK    "%.15E\n"          /// "%.15E\n"
#define DEFAULT_COMMENT_CHAR  '#'                /// comment trigger

/** \brief Exit with failure if file pointer is NULL reporting a message */
void
assert_file_pointer(FILE* f, char client_msg[]);

/** \brief Just improved fopen with NULL pointer check */
FILE*
open_file(char fname[], char mode[]);

/** \brief Return number of lines in a file */
unsigned int
number_of_lines(char fname[]);

/** \brief Move reading cursor of a file to the beginning of next line */
void
jump_next_line(FILE* f);

/** \brief Move reading cursor until get line not starting with #
 *
 * Preferably, the initial cursor position should be in the beginning of
 * a new line. Spaces and empty lines are also skipped but any different
 * character despite '#' count as a non-comment trigger
 *
 * \param f[in]           Pointer to a open file
 * \param in_nextline[in] Whether to start scanning in the next line or
 *                        current cursor position
 *
 * \see DEFAULT_COMMENT_CHAR
 */
void
jump_comment_lines(FILE* f, enum StartStream in_nextline);

#endif
