
<div style="justify-items: center">
<img style="display: block" src="optional-logo.svg" alt="Optional Library">
</div>

# Introduction

A general-purpose *Maybe type* for representing missing values in C without `NULL` or *sentinel values*.

![][EXAMPLE]

> [!NOTE]
> [Schrödinger's cat][SCHRODINGERS_CAT] is inside a box. Until you look, you don't know if it's *alive* or *dead*. A
> [Maybe type][MAYBE_TYPE] works the same way. It either contains a cat, meaning you have a value, or it's empty,
> meaning you have nothing. Instead of risking errors when there's no cat, #OPTIONAL makes you handle both cases
> explicitly, eliminating the need for [null checks][NULL_CHECKING] or [sentinel values][SENTINEL_VALUE].


# Getting Started

## Adding Optionals to Your Project

This library consists of one header file only. All you need to do is copy `optional.h` into your project, and include
it.

```c
#include <optional.h>
```

Since it's a header-only library, there is no library code to link against.

> [!TIP]
> Optionals are useful for representing values that may or may not be present. To indicate *why* a value is absent, you
> may want to use [Results][RESULT_LIBRARY] instead.

## Optional Types and Variables

- #OPTIONAL_STRUCT @copybrief OPTIONAL_STRUCT
  @snippet example.c optional_struct
- #OPTIONAL @copybrief OPTIONAL
  @snippet example.c optional

## Creating Optional Objects

- #OPTIONAL_PRESENT @copybrief OPTIONAL_PRESENT
  @snippet example.c optional_present
- #OPTIONAL_EMPTY @copybrief OPTIONAL_EMPTY
  @snippet example.c optional_empty
- #OPTIONAL_OF_NULLABLE @copybrief OPTIONAL_OF_NULLABLE
  @snippet example.c optional_of_nullable
- #OPTIONAL_OF_POSSIBLY_FALSY @copybrief OPTIONAL_OF_POSSIBLY_FALSY
  @snippet example.c optional_of_possibly_falsy


# Basic Usage

## Checking for Presence

- #OPTIONAL_IS_PRESENT @copybrief OPTIONAL_IS_PRESENT
  @snippet example.c optional_is_present
- #OPTIONAL_IS_EMPTY @copybrief OPTIONAL_IS_EMPTY
  @snippet example.c optional_is_empty

## Unwrapping Values

- #OPTIONAL_USE_VALUE @copybrief OPTIONAL_USE_VALUE
  @snippet example.c optional_use_value
- #OPTIONAL_GET_VALUE @copybrief OPTIONAL_GET_VALUE
  @snippet example.c optional_get_value
- #OPTIONAL_OR_ELSE @copybrief OPTIONAL_OR_ELSE
  @snippet example.c optional_or_else

## Conditional Actions

- #OPTIONAL_IF_PRESENT @copybrief OPTIONAL_IF_PRESENT
  @snippet example.c optional_if_present
- #OPTIONAL_IF_PRESENT_OR_ELSE @copybrief OPTIONAL_IF_PRESENT_OR_ELSE
  @snippet example.c optional_if_present_or_else


# Advanced Usage

## Screening Optionals

- #OPTIONAL_FILTER @copybrief OPTIONAL_FILTER
  @snippet example.c optional_filter
- #OPTIONAL_FILTER_FALSY @copybrief OPTIONAL_FILTER_FALSY
  @snippet example.c optional_filter_falsy
- #OPTIONAL_FILTER_NULL @copybrief OPTIONAL_FILTER_NULL
  @snippet example.c optional_filter_null

## Transforming Values

- #OPTIONAL_MAP @copybrief OPTIONAL_MAP
  @snippet example.c optional_map
- #OPTIONAL_FLAT_MAP @copybrief OPTIONAL_FLAT_MAP
  @snippet example.c optional_flat_map
- #OPTIONAL_OR @copybrief OPTIONAL_OR
  @snippet example.c optional_or


# Additional Info

## Compatibility

Optionals rely on modern C features such as [designated initializers][DESIGNATED_INITIALIZERS],
[compound literals][COMPOUND_LITERALS], and [typeof][TYPEOF].

## Releases

This library adheres to [Semantic Versioning][SEMVER]. All notable changes for each version are documented in a
[change log][CHANGELOG].

Head over to GitHub for the [latest release][LATEST_RELEASE].

[![Latest Release][BADGE_LATEST_RELEASE]][LATEST_RELEASE]

## Source Code

The source code is [available on GitHub][SOURCE_CODE].

[![Fork me on GitHub][BADGE_GITHUB]][SOURCE_CODE]


[BADGE_GITHUB]:                 https://img.shields.io/badge/Fork_me_on_GitHub-black?logo=github
[BADGE_LATEST_RELEASE]:         https://img.shields.io/github/v/release/guillermocalvo/optional
[CHANGELOG]:                    https://github.com/guillermocalvo/optional/blob/main/CHANGELOG.md
[COMPOUND_LITERALS]:            https://gcc.gnu.org/onlinedocs/gcc-3.3/gcc/Compound-Literals.html
[DESIGNATED_INITIALIZERS]:      https://gcc.gnu.org/onlinedocs/gcc-3.3/gcc/Designated-Inits.html
[EXAMPLE]:                      example.png
[LATEST_RELEASE]:               https://github.com/guillermocalvo/optional/releases/latest
[MAYBE_TYPE]:                   https://en.wikipedia.org/wiki/Option_type
[NULL_CHECKING]:                https://en.wikipedia.org/wiki/Nullable_type#Compared_with_null_pointers
[RESULT_LIBRARY]:               https://result.guillermo.dev/
[SCHRODINGERS_CAT]:             https://en.wikipedia.org/wiki/Schr%C3%B6dinger%27s_cat
[SEMVER]:                       https://semver.org/
[SENTINEL_VALUE]:               https://en.wikipedia.org/wiki/Sentinel_value
[SOURCE_CODE]:                  https://github.com/guillermocalvo/optional
[TYPEOF]:                       https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2899.htm
