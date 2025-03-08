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

OPTIONAL_STRUCT(int);

static bool is_within_range(int x) {
    return x >= 1 && x <= 10;
}

/**
 * Tests `OPTIONAL_FILTER` using functions.
 */
int main() {
    // Given
    const OPTIONAL(int) present1 = OPTIONAL_PRESENT(5);
    const OPTIONAL(int) present2 = OPTIONAL_PRESENT(-10);
    const OPTIONAL(int) empty = OPTIONAL_EMPTY;
    // When
    const OPTIONAL(int) filtered_present1 = OPTIONAL_FILTER(present1, is_within_range);
    const OPTIONAL(int) filtered_present2 = OPTIONAL_FILTER(present2, is_within_range);
    const OPTIONAL(int) filtered_empty = OPTIONAL_FILTER(empty, is_within_range);
    // Then
    TEST_ASSERT(OPTIONAL_IS_PRESENT(filtered_present1));
    TEST_ASSERT_INT_EQUALS(OPTIONAL_USE_VALUE(filtered_present1), 5);
    TEST_ASSERT(OPTIONAL_IS_EMPTY(filtered_present2));
    TEST_ASSERT(OPTIONAL_IS_EMPTY(filtered_empty));
    TEST_PASS;
}
