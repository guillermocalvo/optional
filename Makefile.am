#
# Optional Library
#
# Copyright (c) 2025 Guillermo Calvo
# Licensed under the Apache License, Version 2.0
#

AUTOMAKE_OPTIONS = foreign subdir-objects

AM_CFLAGS = -Wall -Werror --pedantic -Isrc

include_HEADERS = src/optional.h

# Documentation

docsdir = $(datadir)/docs/optional
docs_DATA = docs/*


# Check

check_PROGRAMS =                                        \
    bin/check/optional_present                          \
    bin/check/optional_empty                            \
    bin/check/optional_of_nullable                      \
    bin/check/optional_of_possibly_falsy                \
    bin/check/optional_is_present                       \
    bin/check/optional_is_empty                         \
    bin/check/optional_use_value                        \
    bin/check/optional_get_value                        \
    bin/check/optional_or_else                          \
    bin/check/optional_if_present_using_functions       \
    bin/check/optional_if_present_using_macros          \
    bin/check/optional_if_present_or_else_using_functions \
    bin/check/optional_if_present_or_else_using_macros  \
    bin/check/optional_filter_using_functions           \
    bin/check/optional_filter_using_macros              \
    bin/check/optional_filter_null                      \
    bin/check/optional_filter_falsy                     \
    bin/check/optional_map_using_functions              \
    bin/check/optional_map_using_macros                 \
    bin/check/optional_flat_map_using_functions         \
    bin/check/optional_flat_map_using_macros            \
    bin/check/optional_or                               \
    bin/check/examples

TESTS =                                                 \
    bin/check/optional_present                          \
    bin/check/optional_empty                            \
    bin/check/optional_of_nullable                      \
    bin/check/optional_of_possibly_falsy                \
    bin/check/optional_is_present                       \
    bin/check/optional_is_empty                         \
    bin/check/optional_use_value                        \
    bin/check/optional_get_value                        \
    bin/check/optional_or_else                          \
    bin/check/optional_if_present_using_functions       \
    bin/check/optional_if_present_using_macros          \
    bin/check/optional_if_present_or_else_using_functions \
    bin/check/optional_if_present_or_else_using_macros  \
    bin/check/optional_filter_using_functions           \
    bin/check/optional_filter_using_macros              \
    bin/check/optional_filter_null                      \
    bin/check/optional_filter_falsy                     \
    bin/check/optional_map_using_functions              \
    bin/check/optional_map_using_macros                 \
    bin/check/optional_flat_map_using_functions         \
    bin/check/optional_flat_map_using_macros            \
    bin/check/optional_or                               \
    bin/check/examples

tests: check


# Tests

bin_check_optional_present_SOURCES                          = tests/optional_present.c
bin_check_optional_empty_SOURCES                            = tests/optional_empty.c
bin_check_optional_of_nullable_SOURCES                      = tests/optional_of_nullable.c
bin_check_optional_of_possibly_falsy_SOURCES                = tests/optional_of_possibly_falsy.c
bin_check_optional_is_present_SOURCES                       = tests/optional_is_present.c
bin_check_optional_is_empty_SOURCES                         = tests/optional_is_empty.c
bin_check_optional_use_value_SOURCES                        = tests/optional_use_value.c
bin_check_optional_get_value_SOURCES                        = tests/optional_get_value.c
bin_check_optional_or_else_SOURCES                          = tests/optional_or_else.c
bin_check_optional_if_present_using_functions_SOURCES       = tests/optional_if_present_using_functions.c
bin_check_optional_if_present_using_macros_SOURCES          = tests/optional_if_present_using_macros.c
bin_check_optional_if_present_or_else_using_functions_SOURCES = tests/optional_if_present_or_else_using_functions.c
bin_check_optional_if_present_or_else_using_macros_SOURCES  = tests/optional_if_present_or_else_using_macros.c
bin_check_optional_filter_using_functions_SOURCES           = tests/optional_filter_using_functions.c
bin_check_optional_filter_using_macros_SOURCES              = tests/optional_filter_using_macros.c
bin_check_optional_filter_null_SOURCES                      = tests/optional_filter_null.c
bin_check_optional_filter_falsy_SOURCES                     = tests/optional_filter_falsy.c
bin_check_optional_map_using_functions_SOURCES              = tests/optional_map_using_functions.c
bin_check_optional_map_using_macros_SOURCES                 = tests/optional_map_using_macros.c
bin_check_optional_flat_map_using_functions_SOURCES         = tests/optional_flat_map_using_functions.c
bin_check_optional_flat_map_using_macros_SOURCES            = tests/optional_flat_map_using_macros.c
bin_check_optional_or_SOURCES                               = tests/optional_or.c
bin_check_examples_SOURCES                                  = examples/example.c examples/pet-store.c examples/application.c


# Generate documentation

docs: docs/html/index.html

docs/html/index.html: docs/Doxyfile docs/doxygen-awesome.css docs/doxygen-awesome-sidebar-only.css
	doxygen docs/Doxyfile

docs/doxygen-awesome.css:
	wget --verbose --output-document docs/doxygen-awesome.css https://github.com/jothepro/doxygen-awesome-css/raw/refs/heads/main/doxygen-awesome.css

docs/doxygen-awesome-sidebar-only.css:
	wget --verbose --output-document docs/doxygen-awesome-sidebar-only.css https://github.com/jothepro/doxygen-awesome-css/raw/refs/heads/main/doxygen-awesome-sidebar-only.css
