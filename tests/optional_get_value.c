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

#include <stddef.h>
#include <optional.h>
#include "test.h"

OPTIONAL_STRUCT(int);

/**
 * Tests `OPTIONAL_GET_VALUE`.
 */
int main() {
    // Given
    const OPTIONAL(int) present = OPTIONAL_PRESENT(512);
    const OPTIONAL(int) empty = OPTIONAL_EMPTY;
    // When
    const int *present_get_value = OPTIONAL_GET_VALUE(present);
    const int *empty_get_value = OPTIONAL_GET_VALUE(empty);
    // Then
    TEST_ASSERT_NOT_NULL(present_get_value);
    TEST_ASSERT_NULL(empty_get_value);
    TEST_ASSERT_INT_EQUALS(*present_get_value, 512);
    TEST_PASS;
}
