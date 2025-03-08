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
 * Tests `OPTIONAL_OF_NULLABLE`.
 */
int main() {
    // Given
    const char* pointer1 = "OK";
    const char* pointer2 = NULL;
    const OPTIONAL(text) optional1 = OPTIONAL_OF_NULLABLE(pointer1);
    const OPTIONAL(text) optional2 = OPTIONAL_OF_NULLABLE(pointer2);
    // Then
    TEST_ASSERT_FALSE(optional1._empty);
    TEST_ASSERT_TRUE(optional1._value == pointer1);
    TEST_ASSERT_TRUE(optional2._empty);
    TEST_ASSERT_NULL(optional2._value);
    TEST_PASS;
}
