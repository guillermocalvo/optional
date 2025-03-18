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

#define POINT(x, y) \
    ((point) { x, y })

static OPTIONAL(int) validate(const point p) {
    return p.x == 0 && p.y == 0
               ? (OPTIONAL(int)) OPTIONAL_EMPTY
               : (OPTIONAL(int)) OPTIONAL_PRESENT(p.x + p.y);
}

/**
 * Tests `OPTIONAL_FLAT_MAP` using functions.
 */
int main() {
    // Given
    const OPTIONAL(point) present1 = OPTIONAL_PRESENT(POINT(123, 456));
    const OPTIONAL(point) present2 = OPTIONAL_PRESENT(POINT(0, 0));
    const OPTIONAL(point) empty = OPTIONAL_EMPTY;
    // When
    const OPTIONAL(int) mapped_present1 = OPTIONAL_FLAT_MAP(present1, validate);
    const OPTIONAL(int) mapped_present2 = OPTIONAL_FLAT_MAP(present2, validate);
    const OPTIONAL(int) mapped_empty = OPTIONAL_FLAT_MAP(empty, validate);
    // Then
    TEST_ASSERT(OPTIONAL_IS_PRESENT(mapped_present1));
    TEST_ASSERT_INT_EQUALS(OPTIONAL_USE_VALUE(mapped_present1), 579);
    TEST_ASSERT(OPTIONAL_IS_EMPTY(mapped_present2));
    TEST_ASSERT(OPTIONAL_IS_EMPTY(mapped_empty));
    TEST_PASS;
}
