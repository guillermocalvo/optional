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

typedef struct {
    int x;
    int y;
} point;

OPTIONAL_STRUCT(int);

OPTIONAL_STRUCT(point);

#define point_get_x(p) \
    p.x

/**
 * Tests `OPTIONAL_MAP` using macros.
 */
int main() {
    // Given
    const point p = {123, 456};
    const OPTIONAL(point) present = OPTIONAL_PRESENT(p);
    const OPTIONAL(point) empty = OPTIONAL_EMPTY;
    // When
    const OPTIONAL(int) mapped_present = OPTIONAL_MAP(present, point_get_x, OPTIONAL(int));
    const OPTIONAL(int) mapped_empty = OPTIONAL_MAP(empty, point_get_x, OPTIONAL(int));
    // Then
    TEST_ASSERT(OPTIONAL_IS_PRESENT(mapped_present));
    TEST_ASSERT_INT_EQUALS(OPTIONAL_USE_VALUE(mapped_present), 123);
    TEST_ASSERT(OPTIONAL_IS_EMPTY(mapped_empty));
    TEST_PASS;
}
