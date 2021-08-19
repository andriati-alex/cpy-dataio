/** \file file_handle.h
 *
 * \author Alex Andriati
 * \date Aug/2021
 * \brief Simple improved toolbox for an easier files usage
 *
 * Some macros are provided for better integration with numpy, formmating
 * string to write complex numbers using brackets and \code j \endcode as
 * imaginary unit. By default, the macros provide 16 digits, according to
 * C double precision. Moreover, these macros use explonential notation
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
    LINEBREAK
};

/** \brief Simple boolean information */
enum Bool
{
    FALSE,
    TRUE
};

#define CPLX_SCIFMT_SPACE_BOTH   " (%.15E%+.15Ej) " /// " (%.15E%+.15Ej) "
#define CPLX_SCIFMT_SPACE_BEFORE " (%.15E%+.15Ej)"  /// " (%.15E%+.15Ej)"
#define CPLX_SCIFMT_SPACE_AFTER  "(%.15E%+.15Ej) "  /// "(%.15E%+.15Ej) "
#define CPLX_SCIFMT_NOSPACE      "(%.15E%+.15Ej)"   /// "(%.15E%+.15Ej)"
#define CPLX_SCIFMT_LINEBREAK    "(%.15E%+.15Ej)\n" /// "(%.15E%+.15Ej)\n"
#define REAL_SCIFMT_SPACE_BOTH   " %.15E "          /// " %.15E "
#define REAL_SCIFMT_SPACE_BEFORE " %.15E"           /// " %.15E"
#define REAL_SCIFMT_SPACE_AFTER  "%.15E "           /// "%.15E "
#define REAL_SCIFMT_NOSPACE      "%.15E"            /// "%.15E"
#define REAL_SCIFMT_LINEBREAK    "%.15E\n"          /// "%.15E\n"
#define DEFAULT_COMMENT_CHAR     '#'                /// default comment trigger

/** \brief Character interpreted as beginning of comment line
 *
 * Comment headers in data files are usually preeceded by a '#', as well
 * as throughout configuration files. This global variable defines which
 * character will trigger a comment line. By default it is '#', but the
 * client application can set to a different value. To change '#' to any
 * other character assign this global variable in the main app program
 */
extern char comment_char;

/** \brief Exit with failure if file pointer is NULL reporting a message */
void
assert_file_pointer(FILE* f, char client_msg[]);

/** \brief Just improved fopen with NULL pointer check */
FILE*
open_file(char fname[], char mode[]);

/** \brief Return number of lines in a file */
unsigned int
number_of_lines(char fname[], enum Bool skip_comments);

/** \brief Move reading cursor of a file to the beginning of next line */
void
jump_next_line(FILE* f);

/** \brief Move reading cursor until get line not starting with #
 *
 * Preferably, the initial cursor position should be in the beginning of
 * a new line. Spaces and empty lines are also skipped but any different
 * different character from \code comment_char \endcode count as a non-
 * comment trigger. By default \code comment_char = '#' \endcode
 *
 * \param f[in]         Pointer to a open file
 * \param how_start[in] Either CURSOR_POSITION or NEXT_LINE
 *
 * \see comment_char
 */
void
jump_comment_lines(FILE* f, enum StartStream how_start);

#endif
