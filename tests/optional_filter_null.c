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

#include <optional.h>
#include "test.h"

OPTIONAL_STRUCT_TAG(const char *, OPTIONAL_TAG(text));

/**
 * Tests `OPTIONAL_FILTER_NULL`.
 */
int main() {
    // Given
    const OPTIONAL(text) present1 = OPTIONAL_PRESENT("Hello");
    const OPTIONAL(text) present2 = OPTIONAL_PRESENT(NULL);
    const OPTIONAL(text) empty = OPTIONAL_EMPTY;
    // When
    const OPTIONAL(text) filtered_present1 = OPTIONAL_FILTER_NULL(present1);
    const OPTIONAL(text) filtered_present2 = OPTIONAL_FILTER_NULL(present2);
    const OPTIONAL(text) filtered_empty = OPTIONAL_FILTER_NULL(empty);
    // Then
    TEST_ASSERT(OPTIONAL_IS_PRESENT(filtered_present1));
    TEST_ASSERT_STR_EQUALS(OPTIONAL_USE_VALUE(filtered_present1), "Hello");
    TEST_ASSERT(OPTIONAL_IS_EMPTY(filtered_present2));
    TEST_ASSERT(OPTIONAL_IS_EMPTY(filtered_empty));
    TEST_PASS;
}
