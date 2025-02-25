/* This file is auto-generated by opts.sh.  */

#include "config.h"
#include "system.h"
#include "options.h"
#include "opts.h"
#include "intl.h"

#ifdef GCC_DRIVER
int target_flags;
#endif /* GCC_DRIVER */

/* Set by -Wfatal-errors.
   Exit on the first error occurred  */
int flag_fatal_errors;

/* Set by -Wtraditional.
   Warn about features not present in traditional C  */
int warn_traditional;

/* Set by -pedantic.
   Issue warnings needed for strict compliance to the standard  */
int pedantic;

/* Set by -w.
   Suppress warnings  */
int inhibit_warnings;


/* Local state variables.  */

const char * const lang_names[] =
{
  "SDCPP",
  0
};

const unsigned int cl_options_count = N_OPTS;

const struct cl_option cl_options[] =
{
  { "--help",
    "Display this information",
    N_OPTS, 5, -1,
    CL_COMMON,
    0, CLVC_BOOLEAN, 0 },
  { "--version",
    "Display the compiler's version",
    N_OPTS, 8, -1,
    CL_COMMON,
    0, CLVC_BOOLEAN, 0 },
  { "-A",
    "-A<question>=<answer>	Assert the <answer> to <question>.  Putting '-' before <question> disables the <answer> to <question>",
    N_OPTS, 1, -1,
    CL_SDCPP | CL_JOINED | CL_SEPARATE,
    0, CLVC_STRING, 0 },
  { "-C",
    "Do not discard comments",
    N_OPTS, 1, -1,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-CC",
    "Do not discard comments in macro expansions",
    N_OPTS, 2, -1,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-D",
    "-D<macro>[=<val>]	Define a <macro> with <val> as its value.  If just <macro> is given, <val> is taken to be 1",
    N_OPTS, 1, -1,
    CL_SDCPP | CL_JOINED | CL_SEPARATE,
    0, CLVC_STRING, 0 },
  { "-H",
    "Print the name of header files as they are used",
    N_OPTS, 1, -1,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-I",
    "-I <dir>	Add <dir> to the end of the main include path.  -I- gives more include path control; see info documentation",
    N_OPTS, 1, -1,
    CL_SDCPP | CL_JOINED | CL_SEPARATE,
    0, CLVC_STRING, 0 },
  { "-M",
    "Generate make dependencies",
    N_OPTS, 1, -1,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-MD",
    "Generate make dependencies and compile",
    N_OPTS, 2, -1,
    CL_SDCPP | CL_SEPARATE,
    0, CLVC_BOOLEAN, 0 },
  { "-MF",
    "-MF <file>	Write dependency output to the given file",
    N_OPTS, 2, -1,
    CL_SDCPP | CL_JOINED | CL_SEPARATE,
    0, CLVC_STRING, 0 },
  { "-MG",
    "Treat missing header files as generated files",
    N_OPTS, 2, -1,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-MM",
    "Like -M but ignore system header files",
    N_OPTS, 2, -1,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-MMD",
    "Like -MD but ignore system header files",
    N_OPTS, 3, -1,
    CL_SDCPP | CL_SEPARATE,
    0, CLVC_BOOLEAN, 0 },
  { "-MP",
    "Generate phony targets for all headers",
    N_OPTS, 2, -1,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-MQ",
    "-MQ <target>	Add a MAKE-quoted target",
    N_OPTS, 2, -1,
    CL_SDCPP | CL_JOINED | CL_SEPARATE,
    0, CLVC_STRING, 0 },
  { "-MT",
    "-MT <target>	Add an unquoted target",
    N_OPTS, 2, -1,
    CL_SDCPP | CL_JOINED | CL_SEPARATE,
    0, CLVC_STRING, 0 },
  { "-P",
    "Do not generate #line directives",
    N_OPTS, 1, -1,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-U",
    "-U<macro>	Undefine <macro>",
    N_OPTS, 1, -1,
    CL_SDCPP | CL_JOINED | CL_SEPARATE,
    0, CLVC_STRING, 0 },
  { "-Wall",
    "Enable most warning messages",
    N_OPTS, 4, 19,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-Wcomment",
    "Warn about possibly nested block comments, and C++ comments spanning more than one physical line",
    N_OPTS, 8, 20,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-Wcomments",
    "Synonym for -Wcomment",
    N_OPTS, 9, 21,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-Wdeprecated",
    "Warn about deprecated compiler features",
    N_OPTS, 11, 22,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-Wendif-labels",
    "Warn about stray tokens after #elif and #endif",
    N_OPTS, 13, 23,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-Werror",
    "Treat all warnings as errors",
    N_OPTS, 6, 24,
    CL_COMMON,
    0, CLVC_BOOLEAN, 0 },
  { "-Wfatal-errors",
    "Exit on the first error occurred",
    N_OPTS, 13, 25,
    CL_SDCPP,
    &flag_fatal_errors, CLVC_BOOLEAN, 0 },
  { "-Wimport",
    "Deprecated.  This switch has no effect.",
    N_OPTS, 7, 26,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-Wsystem-headers",
    "Do not suppress warnings from system headers",
    N_OPTS, 15, 27,
    CL_COMMON,
    0, CLVC_BOOLEAN, 0 },
  { "-Wtraditional",
    "Warn about features not present in traditional C",
    N_OPTS, 12, 28,
    CL_SDCPP,
    &warn_traditional, CLVC_BOOLEAN, 0 },
  { "-Wtrigraphs",
    "Warn if trigraphs are encountered that might affect the meaning of the program",
    N_OPTS, 10, 29,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-Wundef",
    "Warn if an undefined macro is used in an #if directive",
    N_OPTS, 6, 30,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-Wunused-macros",
    "Warn about macros defined in the main file that are not used",
    N_OPTS, 14, 31,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-Wvariadic-macros",
    "Do not warn about using variadic macros when -pedantic",
    N_OPTS, 16, 32,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-ansi",
    "A synonym for -std=c89.",
    N_OPTS, 4, -1,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-d",
    "-d<letters>	Enable dumps from specific passes of the compiler",
    N_OPTS, 1, -1,
    CL_SDCPP | CL_COMMON | CL_JOINED,
    0, CLVC_STRING, 0 },
  { "-fdollars-in-identifiers",
    "Permit '$' as an identifier character",
    N_OPTS, 23, 35,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-fexec-charset=",
    "-fexec-charset=<cset>	Convert all strings and character constants to character set <cset>",
    N_OPTS, 14, -1,
    CL_SDCPP | CL_JOINED | CL_REJECT_NEGATIVE,
    0, CLVC_STRING, 0 },
  { "-finput-charset=",
    "-finput-charset=<cset>      Specify the default character set for source files.",
    N_OPTS, 15, -1,
    CL_SDCPP | CL_JOINED | CL_REJECT_NEGATIVE,
    0, CLVC_STRING, 0 },
  { "-fpreprocessed",
    "Treat the input file as already preprocessed",
    N_OPTS, 13, 38,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-fshow-column",
    0,
    N_OPTS, 12, 39,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-fsigned-char",
    "Make \"char\" signed by default",
    N_OPTS, 12, 40,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-ftabstop=",
    "-ftabstop=<number>	Distance between tab stops for column reporting",
    N_OPTS, 9, -1,
    CL_SDCPP | CL_JOINED | CL_REJECT_NEGATIVE | CL_UINTEGER,
    0, CLVC_BOOLEAN, 0 },
  { "-funsigned-char",
    "Make \"char\" unsigned by default",
    N_OPTS, 14, 42,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-fwide-exec-charset=",
    "-fwide-exec-charset=<cset>	Convert all wide strings and character constants to character set <cset>",
    N_OPTS, 19, -1,
    CL_SDCPP | CL_JOINED | CL_REJECT_NEGATIVE,
    0, CLVC_STRING, 0 },
  { "-fworking-directory",
    "Generate a #line directive pointing at the current working directory",
    N_OPTS, 18, 44,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-idirafter",
    "-idirafter <dir>	Add <dir> to the end of the system include path",
    N_OPTS, 9, -1,
    CL_SDCPP | CL_JOINED | CL_SEPARATE,
    0, CLVC_STRING, 0 },
  { "-imacros",
    "-imacros <file>	Accept definition of macros in <file>",
    N_OPTS, 7, -1,
    CL_SDCPP | CL_JOINED | CL_SEPARATE,
    0, CLVC_STRING, 0 },
  { "-imultilib",
    "-imultilib <dir> Set <dir> to be the multilib include subdirectory",
    N_OPTS, 9, -1,
    CL_JOINED | CL_SEPARATE,
    0, CLVC_STRING, 0 },
  { "-include",
    "-include <file>	Include the contents of <file> before other files",
    N_OPTS, 7, -1,
    CL_SDCPP | CL_JOINED | CL_SEPARATE,
    0, CLVC_STRING, 0 },
  { "-iprefix",
    "-iprefix <path>	Specify <path> as a prefix for next two options",
    N_OPTS, 7, -1,
    CL_SDCPP | CL_JOINED | CL_SEPARATE,
    0, CLVC_STRING, 0 },
  { "-iquote",
    "-iquote <dir>	Add <dir> to the end of the quote include path",
    N_OPTS, 6, -1,
    CL_SDCPP | CL_JOINED | CL_SEPARATE,
    0, CLVC_STRING, 0 },
  { "-isysroot",
    "-isysroot <dir>	Set <dir> to be the system root directory",
    N_OPTS, 8, -1,
    CL_SDCPP | CL_JOINED | CL_SEPARATE,
    0, CLVC_STRING, 0 },
  { "-isystem",
    "-isystem <dir>	Add <dir> to the start of the system include path",
    N_OPTS, 7, -1,
    CL_SDCPP | CL_JOINED | CL_SEPARATE,
    0, CLVC_STRING, 0 },
  { "-iwithprefix",
    "-iwithprefix <dir>	Add <dir> to the end of the system include path",
    N_OPTS, 11, -1,
    CL_SDCPP | CL_JOINED | CL_SEPARATE,
    0, CLVC_STRING, 0 },
  { "-iwithprefixbefore",
    "-iwithprefixbefore <dir>	Add <dir> to the end of the main include path",
    OPT_iwithprefix, 17, -1,
    CL_SDCPP | CL_JOINED | CL_SEPARATE,
    0, CLVC_STRING, 0 },
  { "-lang-asm",
    0,
    N_OPTS, 8, -1,
    CL_UNDOCUMENTED,
    0, CLVC_BOOLEAN, 0 },
  { "-lang-objc",
    0,
    N_OPTS, 9, -1,
    CL_SDCPP | CL_UNDOCUMENTED,
    0, CLVC_BOOLEAN, 0 },
  { "-no-trigraphs",
    "-no-trigraphs	Disble ISO C trigraphs support",
    N_OPTS, 12, -1,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-nostdinc",
    "Do not search standard system include directories (those specified with -isystem will still be used)",
    N_OPTS, 8, -1,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-o",
    "-o <file>	Place output into <file>",
    N_OPTS, 1, -1,
    CL_SDCPP | CL_JOINED | CL_SEPARATE,
    0, CLVC_STRING, 0 },
  { "-obj-ext=",
    "-obj-ext=<extension>	Define object file extension, used for generation of make dependencies",
    OPT_o, 8, -1,
    CL_SDCPP | CL_JOINED,
    0, CLVC_STRING, 0 },
  { "-pedantic",
    "Issue warnings needed for strict compliance to the standard",
    N_OPTS, 8, -1,
    CL_SDCPP,
    &pedantic, CLVC_BOOLEAN, 0 },
  { "-pedantic-errors",
    "Like -pedantic but issue them as errors",
    N_OPTS, 15, -1,
    CL_SDCPP | CL_COMMON,
    0, CLVC_BOOLEAN, 0 },
  { "-pedantic-parse-number",
    "Pedantic parse number",
    N_OPTS, 21, -1,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-remap",
    "Remap file names when including files",
    N_OPTS, 5, -1,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-std=c11",
    "Conform to the ISO 2011 C standard",
    N_OPTS, 7, -1,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-std=c89",
    "Conform to the ISO 1990 C standard",
    N_OPTS, 7, -1,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-std=c99",
    "Conform to the ISO 1999 C standard",
    N_OPTS, 7, -1,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-std=iso9899:1990",
    "Conform to the ISO 1990 C standard",
    N_OPTS, 16, -1,
    0,
    0, CLVC_BOOLEAN, 0 },
  { "-std=iso9899:199409",
    "Conform to the ISO 1990 C standard as amended in 1994 (and ratified in 1995)",
    N_OPTS, 18, -1,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-std=iso9899:1999",
    "Conform to the ISO 1999 C standard",
    N_OPTS, 16, -1,
    0,
    0, CLVC_BOOLEAN, 0 },
  { "-traditional-cpp",
    "Enable traditional preprocessing",
    N_OPTS, 15, -1,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-v",
    "Enable verbose output",
    N_OPTS, 1, -1,
    CL_SDCPP,
    0, CLVC_BOOLEAN, 0 },
  { "-w",
    "Suppress warnings",
    N_OPTS, 1, -1,
    CL_COMMON,
    &inhibit_warnings, CLVC_BOOLEAN, 0 }
};
