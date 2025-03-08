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

/**
 * Tests `OPTIONAL_OR`.
 */
int main() {
    // Given
    const OPTIONAL(int) present = OPTIONAL_PRESENT(512);
    const OPTIONAL(int) empty1 = OPTIONAL_EMPTY;
    const OPTIONAL(int) empty2 = OPTIONAL_EMPTY;
    const OPTIONAL(int) optional0 = OPTIONAL_EMPTY;
    const OPTIONAL(int) optional1 = OPTIONAL_EMPTY;
    const OPTIONAL(int) optional2 = OPTIONAL_PRESENT(1);
    // When
    const OPTIONAL(int) mapped_present = OPTIONAL_OR(present, optional0);
    const OPTIONAL(int) mapped_empty1 = OPTIONAL_OR(empty1, optional1);
    const OPTIONAL(int) mapped_empty2 = OPTIONAL_OR(empty2, optional2);
    // Then
    TEST_ASSERT(OPTIONAL_IS_PRESENT(mapped_present));
    TEST_ASSERT_INT_EQUALS(OPTIONAL_USE_VALUE(mapped_present), 512);
    TEST_ASSERT(OPTIONAL_IS_EMPTY(mapped_empty1));
    TEST_ASSERT(OPTIONAL_IS_PRESENT(mapped_empty2));
    TEST_ASSERT_INT_EQUALS(OPTIONAL_USE_VALUE(mapped_empty2), 1);
    TEST_PASS;
}
