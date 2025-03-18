#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.


# Autoconf requirements
AC_PREREQ([2.68])


# Initialize package
AC_INIT([optional], [0.1.0], [optional@guillermo.dev], [optional], [https://github.com/guillermocalvo/optional/])


# Information on the package
AC_COPYRIGHT([Copyright 2025 Guillermo Calvo])
AC_REVISION([$PACKAGE_VERSION])
AC_MSG_NOTICE([
      ___        _   _                   _
     / _ \ _ __ | |_(_) ___  _ __   __ _| |
    | | | | '_ \| __| |/ _ \| '_ \ / _` | |
    | |_| | |_) | |_| | (_) | | | | (_| | |
     \___/| .__/ \__|_|\___/|_| |_|\__,_|_|
          |_|
       A general-purpose Maybe type for C
])


# Check if the source folder is correct
AC_CONFIG_SRCDIR([src/optional.h])


# Checks for programs.
AC_PROG_CC
AC_PROG_CPP


# Checks for header files.
AC_CHECK_HEADERS([stdbool.h])


# Checks for compiler characteristics
AC_LANG([C])


# The config file is generated but not used by the source code
#AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
    optional.pc
    Makefile
])


# Automake initialisation
AM_INIT_AUTOMAKE([
    -Wall
    -Werror
    foreign
    subdir-objects
    no-define
])


AC_OUTPUT
