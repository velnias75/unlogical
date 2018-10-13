#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([unlogical], [0], [heiko@rangun.de])
AM_INIT_AUTOMAKE([foreign no-dist-gzip dist-xz])
AC_CONFIG_HEADERS([config.h])
LT_INIT
AC_CONFIG_MACRO_DIRS([m4])

PKG_CHECK_MODULES([CPPUNIT], [cppunit >= 1.14.0])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADER_STDBOOL

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE

# Checks for library functions.

AC_OUTPUT([Makefile src/Makefile tests/Makefile])
