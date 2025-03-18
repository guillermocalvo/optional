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

static bool on_present1_executed = false;
static bool on_present2_executed = false;
static bool on_empty1_executed = false;
static bool on_empty2_executed = false;

#define on_present1(_) \
    on_present1_executed = true

#define on_present2(_) \
    on_present2_executed = true

/**
 * Tests `OPTIONAL_IF_PRESENT_OR_ELSE` using macros.
 */
int main() {
    // Given
    const OPTIONAL(int) present = OPTIONAL_PRESENT(512);
    const OPTIONAL(int) empty = OPTIONAL_EMPTY;
    // When
    OPTIONAL_IF_PRESENT_OR_ELSE(present, on_present1, on_empty1_executed = true);
    OPTIONAL_IF_PRESENT_OR_ELSE(empty, on_present2, on_empty2_executed = true);
    // Then
    TEST_ASSERT_TRUE(on_present1_executed);
    TEST_ASSERT_FALSE(on_present2_executed);
    TEST_ASSERT_FALSE(on_empty1_executed);
    TEST_ASSERT_TRUE(on_empty2_executed);
    TEST_PASS;
}
