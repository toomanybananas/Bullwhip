#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([bullwhip], [1.0], [stuff@stuff.com])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([ImageManager.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_LANG([C++])

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lBox2D':
AC_CHECK_LIB([Box2D], [main])
AC_CHECK_LIB([sfml-system], [main])
AC_CHECK_LIB([sfml-window], [main])
AC_CHECK_LIB([sfml-graphics], [main])


# Checks for header files.
AC_CHECK_HEADERS([wchar.h])
AC_CHECK_HEADERS([Box2D/Box2D.h])
AC_CHECK_HEADERS([SFML/Graphics.hpp]) #we should just be able to check the graphics lib

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT32_T
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_STRTOD
AC_CHECK_FUNCS([memmove memset pow sqrt strtol])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
