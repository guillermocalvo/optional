/*
 * Copyright 2025 Guillermo Calvo
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OPTIONAL_VERSION

/**
 * Returns the major version number of this library.
 */
#define OPTIONAL_VERSION 0

#include <stddef.h> /* NULL */

#ifndef __bool_true_false_are_defined
#include <stdbool.h>
#endif

/**
 * Returns the type specifier for Optionals with the supplied type name.
 *
 * For example, an Optional that can hold an @p int value, has a type specifier:
 * <tt>struct optional_int</tt>.
 *
 * @note
 * The struct tag will be generated via #OPTIONAL_TAG.
 *
 * @remark
 * This macro is useful to define a variable of that specific type of Optionals.
 *
 * @b Example:
 * @snippet example.c optional
 *
 * @param type_name The value type name.
 * @return The Optional type specifier.
 *
 * @see OPTIONAL_STRUCT
 */
#define OPTIONAL(type_name)                                                 \
  struct OPTIONAL_TAG(type_name)

/**
 * Declares an Optional struct with a default tag and the supplied type.
 *
 * @note
 * The struct tag will be generated via #OPTIONAL_TAG.
 *
 * @remark
 * This macro is useful to declare Optional structs with a default tag.
 *
 * @b Example:
 * @snippet example.c optional_struct
 *
 * @param type The value type.
 * @return The type definition.
 *
 * @see OPTIONAL
 */
#define OPTIONAL_STRUCT(type)                                               \
  OPTIONAL_STRUCT_TAG(                                                      \
    type,                                                                   \
    OPTIONAL_TAG(type)                                                      \
  )

 /**
  * Initializes a new Optional containing the supplied value.
  *
  * @b Example:
  * @snippet example.c optional_present
  *
  * @param value The value.
  * @return The initializer for an Optional holding @b value.
  *
  * @see OPTIONAL_EMPTY
  * @see OPTIONAL_OF_NULLABLE
  * @see OPTIONAL_OF_POSSIBLY_FALSY
  */
#define OPTIONAL_PRESENT(value)                                             \
  {                                                                         \
    ._empty = false,                                                        \
    ._value = (value)                                                       \
  }

 /**
  * Initializes a new empty Optional.
  *
  * @b Example:
  * @snippet example.c optional_empty
  *
  * @return The initializer for an empty Optional.
  *
  * @see OPTIONAL_PRESENT
  * @see OPTIONAL_OF_NULLABLE
  * @see OPTIONAL_OF_POSSIBLY_FALSY
  */
#define OPTIONAL_EMPTY                                                      \
  {                                                                         \
    ._empty = true,                                                         \
  }


 /**
  * Initializes a new Optional based on a possibly null pointer.
  *
  * This macro will initialize a new empty Optional if the supplied
  * @b possibly_null_pointer is @p NULL; otherwise, it will initialize a new
  * Optional containing the supplied pointer.
  *
  * @pre @b possibly_null_pointer MUST be an @e lvalue.
  *
  * @b Example:
  * @snippet example.c optional_of_nullable
  *
  * @param possibly_null_pointer The possibly null pointer.
  * @return The initializer for either an empty Optional or an Optional holding
  *   @b possibly_null_pointer if it is not @p NULL.
  *
  * @see OPTIONAL_PRESENT
  * @see OPTIONAL_EMPTY
  * @see OPTIONAL_OF_POSSIBLY_FALSY
  */
#define OPTIONAL_OF_NULLABLE(possibly_null_pointer)                         \
  {                                                                         \
    ._empty = ((possibly_null_pointer) == NULL),                            \
    ._value = ((void) &(possibly_null_pointer), (possibly_null_pointer))    \
  }

 /**
  * Initializes a new Optional based on a possibly falsy value.
  *
  * This macro will initialize a new empty Optional if the supplied
  * @b possibly_falsy_value evaluates to @p false when converted to @p bool;
  * otherwise, it will initialize a new Optional containing the supplied value.
  *
  * @pre @b possibly_falsy_value MUST be an @e lvalue.
  *
  * @b Example:
  * @snippet example.c optional_of_possibly_falsy
  *
  * @param possibly_falsy_value The possibly falsy value.
  * @return The initializer for either an empty Optional or an Optional holding
  *   @b possibly_falsy_value if it does not evaluate to @p false.
  *
  * @see OPTIONAL_PRESENT
  * @see OPTIONAL_EMPTY
  * @see OPTIONAL_OF_NULLABLE
  */
#define OPTIONAL_OF_POSSIBLY_FALSY(possibly_falsy_value)                    \
  {                                                                         \
    ._empty = !(possibly_falsy_value),                                      \
    ._value = ((void) &(possibly_falsy_value), (possibly_falsy_value))      \
  }

/**
 * Checks if an Optional contains a value.
 *
 * @b Example:
 * @snippet example.c optional_is_present
 *
 * @param optional The Optional to check for presence.
 * @return @p true if @b optional is present; otherwise @p false.
 *
 * @see OPTIONAL_IS_EMPTY
 */
#define OPTIONAL_IS_PRESENT(optional)                                       \
  (!(optional)._empty)

/**
 * Checks if an Optional is empty.
 *
 * @b Example:
 * @snippet example.c optional_is_empty
 *
 * @param optional The Optional to check for absence.
 * @return @p true if @b optional is empty; otherwise @p false.
 *
 * @see OPTIONAL_IS_PRESENT
 */
#define OPTIONAL_IS_EMPTY(optional)                                         \
  ((optional)._empty)

/**
 * Returns an Optional's value.
 *
 * @pre @b optional MUST be present.
 *
 * @warning
 * If @b optional is empty, the value is not initialized explicitly but it
 * SHOULD be zeroed by the compiler.
 *
 * @b Example:
 * @snippet example.c optional_use_value
 *
 * @param optional The Optional to retrieve the value from.
 * @return @b optional's value.
 */
#define OPTIONAL_USE_VALUE(optional)                                        \
  ((optional)._value)

/**
 * Returns an Optional's value as a possibly-null pointer.
 *
 * @pre @b optional MUST be an @e lvalue.
 *
 * @b Example:
 * @snippet example.c optional_get_value
 *
 * @param optional The Optional to retrieve the value from.
 * @return A pointer to @b optional's value if present; otherwise @p NULL.
 */
#define OPTIONAL_GET_VALUE(optional)                                        \
  (                                                                         \
    (void) &(optional),                                                     \
    OPTIONAL_IS_EMPTY(optional)                                             \
    ? NULL                                                                  \
    : &OPTIONAL_USE_VALUE(optional)                                         \
  )

/**
 * Returns an Optional's value, or the supplied one.
 *
 * @pre @b optional MUST be an @e lvalue.
 *
 * @b Example:
 * @snippet example.c optional_or_else
 *
 * @param optional The Optional to retrieve the value from.
 * @param other The alternative value.
 * @return @b optional's value if present; otherwise @b other.
 *
 * @see OPTIONAL_OR_ELSE_MAP
 */
#define OPTIONAL_OR_ELSE(optional, other)                                   \
  (                                                                         \
    (void) &(optional),                                                     \
    OPTIONAL_IS_EMPTY(optional)                                             \
    ? (other)                                                               \
    : OPTIONAL_USE_VALUE(optional)                                          \
  )

/**
 * Performs the supplied action with an Optional's value.
 *
 * If @b optional is present, performs the given @b action with the value;
 * otherwise does nothing.
 *
 * @b Example:
 * @snippet example.c optional_if_present
 *
 * @param optional The Optional whose value will be used.
 * @param action The function or macro to be applied to @b optional's value.
 *
 * @see OPTIONAL_IF_PRESENT_OR_ELSE
 */
#define OPTIONAL_IF_PRESENT(optional, action)                               \
  do {                                                                      \
    typeof(optional) _optional = (optional);                                \
    if (OPTIONAL_IS_PRESENT(_optional)) {                                   \
      (void) (action(OPTIONAL_USE_VALUE(_optional)));                       \
    }                                                                       \
  } while(false)

/**
 * Performs either of the supplied actions with an Optional's value.
 *
 * If @b optional is present, performs the given present-based action with the
 * value; otherwise performs the given empty-based action.
 *
 * @b Example:
 * @snippet example.c optional_if_present_or_else
 *
 * @param optional The Optional whose value may be used.
 * @param present_action The function or macro to be applied to @b optional's
 *   value if present.
 * @param empty_action The expression to evaluate if @b optional is empty.
 *
 * @see OPTIONAL_IF_PRESENT
 */
#define OPTIONAL_IF_PRESENT_OR_ELSE(optional, present_action, empty_action) \
  do {                                                                      \
    typeof(optional) _optional = (optional);                                \
    if (OPTIONAL_IS_EMPTY(_optional)) {                                     \
      (void) (empty_action);                                                \
    } else {                                                                \
      (void) (present_action(OPTIONAL_USE_VALUE(_optional)));               \
    }                                                                       \
  } while(false)

/**
 * Conditionally transforms an Optional into an empty one.
 *
 * @pre @b optional MUST be an @e lvalue.
 *
 * @b Example:
 * @snippet example.c optional_filter
 *
 * @param optional The Optional to filter.
 * @param is_acceptable The predicate function or macro to apply to the value.
 * @return If @b optional is present and its value is deemed not acceptable, a
 *   new empty Optional; otherwise, the supplied @b optional.
 *
 * @see OPTIONAL_FILTER_FALSY
 * @see OPTIONAL_FILTER_NULL
 */
#define OPTIONAL_FILTER(optional, is_acceptable)                            \
  (                                                                         \
    (void) &(optional),                                                     \
    OPTIONAL_IS_EMPTY(optional)                                             \
            || (is_acceptable(OPTIONAL_USE_VALUE(optional)))                \
    ? (optional)                                                            \
    : (typeof(optional)) OPTIONAL_EMPTY                                     \
  )

/**
 * Transforms an Optional containing a falsy value into an empty one.
 *
 * @pre @b optional MUST be an @e lvalue.
 *
 * @b Example:
 * @snippet example.c optional_filter_falsy
 *
 * @param optional The Optional to filter.
 * @return If @b optional is present and its value is not falsy, a new empty
 *   Optional; otherwise, the supplied @b optional.
 *
 * @see OPTIONAL_FILTER
 * @see OPTIONAL_FILTER_NULL
 */
#define OPTIONAL_FILTER_FALSY(optional)                                     \
  (                                                                         \
    (void) &(optional),                                                     \
    OPTIONAL_IS_EMPTY(optional)                                             \
            || !!(OPTIONAL_USE_VALUE(optional))                             \
    ? (optional)                                                            \
    : (typeof(optional)) OPTIONAL_EMPTY                                     \
  )

/**
 * Transforms an Optional containing a null pointer into an empty one.
 *
 * @pre @b optional MUST be an @e lvalue.
 *
 * @b Example:
 * @snippet example.c optional_filter_null
 *
 * @param optional The Optional to filter.
 * @return If @b optional is present and its value is not @p NULL, a new empty
 *   Optional; otherwise, the supplied @b optional.
 *
 * @see OPTIONAL_FILTER
 * @see OPTIONAL_FILTER_FALSY
 */
#define OPTIONAL_FILTER_NULL(optional)                                      \
  (                                                                         \
    (void) &(optional),                                                     \
    OPTIONAL_IS_EMPTY(optional)                                             \
            || OPTIONAL_USE_VALUE(optional) != NULL                         \
    ? (optional)                                                            \
    : (typeof(optional)) OPTIONAL_EMPTY                                     \
  )

/**
 * Transforms the value of an Optional.
 *
 * @pre @b optional MUST be an @e lvalue.
 *
 * @b Example:
 * @snippet example.c optional_map
 *
 * @param optional The Optional whose value will be transformed.
 * @param mapper The mapping function or macro that produces the new value.
 * @param optional_type The type of the transformed Optional type.
 * @return If @b optional is present, a new Optional holding the value produced
 *   by @b mapper; otherwise, the supplied @b optional.
 *
 * @see OPTIONAL_MAP
 */
#define OPTIONAL_MAP(optional, mapper, optional_type)                       \
  (                                                                         \
    (void) &(optional),                                                     \
    OPTIONAL_IS_EMPTY(optional)                                             \
    ? (optional_type) OPTIONAL_EMPTY                                        \
    : (optional_type) OPTIONAL_PRESENT(mapper(OPTIONAL_USE_VALUE(optional)))\
  )

/**
 * Transforms an empty Optional into a different one.
 *
 * @pre @b optional MUST be an @e lvalue.
 *
 * @b Example:
 * @snippet example.c optional_flat_map
 *
 * @param optional The Optional that will be transformed.
 * @param mapper The mapping function or macro that produces the new Optional if
 *   the given @b optional is present.
 * @return If @b optional is present, a new Optional produced by @b mapper;
 *   otherwise, the supplied @b optional.
 *
 * @see OPTIONAL_OR
 */
#define OPTIONAL_FLAT_MAP(optional, mapper)                                 \
  (                                                                         \
    (void) &(optional),                                                     \
    OPTIONAL_IS_EMPTY(optional)                                             \
    ? (typeof(mapper(OPTIONAL_USE_VALUE(optional))))                        \
      OPTIONAL_EMPTY                                                        \
    : (mapper(OPTIONAL_USE_VALUE(optional)))                                \
  )

/**
 * Transforms an empty Optional into a different one.
 *
 * @pre @b optional MUST be an @e lvalue.
 *
 * @b Example:
 * @snippet example.c optional_or
 *
 * @param optional The Optional that will be transformed.
 * @param supplier The expression that produces the new Optional if the given
 *   @b optional is empty.
 * @return If @b optional is empty, a new Optional produced by @b supplier;
 *   otherwise, the supplied @b optional.
 *
 * @see OPTIONAL_FLAT_MAP
 */
#define OPTIONAL_OR(optional, supplier)                                     \
  (                                                                         \
    (void) &(optional),                                                     \
    OPTIONAL_IS_EMPTY(optional)                                             \
    ? (supplier)                                                            \
    : (typeof(supplier)) OPTIONAL_PRESENT(OPTIONAL_USE_VALUE(optional))     \
  )

/**
 * Returns the struct tag for Optionals with the supplied type name.
 *
 * For example, an Optional that can hold an @p int value, has a struct tag:
 * @p optional_int.
 *
 * @b Example:
 * @snippet example.c optional_tag
 *
 * @param type_name The value type name.
 * @return The Optional struct tag.
 *
 * @see OPTIONAL_STRUCT_TAG
 */
#define OPTIONAL_TAG(type_name)                                             \
  optional_ ## type_name

/**
 * Declares an Optional struct with the supplied type.
 *
 * @pre @b struct_tag SHOULD be generated via #OPTIONAL_TAG.
 *
 * @warning
 * The exact sequence of members that make up an Optional struct MUST be
 * considered part of the implementation details. Optionals SHOULD only be
 * created and accessed using the macros provided in this header file.
 *
 * @remark
 * This macro is useful to declare Optional structs.
 *
 * @b Example:
 * @snippet example.c optional_tag
 *
 * @param type The value type.
 * @param struct_tag The struct tag.
 * @return The struct declaration.
 *
 * @see OPTIONAL_STRUCT
 * @see OPTIONAL_TAG
 */
#define OPTIONAL_STRUCT_TAG(type, struct_tag)                               \
  struct struct_tag {                                                       \
    bool _empty;                                                            \
    type _value;                                                            \
  }

#endif
