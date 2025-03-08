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
 * Tests `OPTIONAL_IS_PRESENT`.
 */
int main() {
    // Given
    const OPTIONAL(int) present = OPTIONAL_PRESENT(512);
    const OPTIONAL(int) empty = OPTIONAL_EMPTY;
    // Then
    TEST_ASSERT_TRUE(OPTIONAL_IS_PRESENT(present));
    TEST_ASSERT_FALSE(OPTIONAL_IS_PRESENT(empty));
    TEST_PASS;
}
