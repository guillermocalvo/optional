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
#include <string.h>
#include <assert.h>
#include <optional.h>
#include <stdio.h>
#include "pet-store.h"

int pet_store_application(int argc, char *argv[]);

OPTIONAL_STRUCT(pet_status);

typedef int IMPLEMENTATION;

static struct pet default_pet = {.id = 100, .name = "Default pet", .status = AVAILABLE};
static int side_effect = 0;
static pet_error last_error = OK;


// Returns the default pet if the supplied error code is PET_NOT_FOUND
static OPTIONAL(Pet) pet_get_default(pet_error code) {
    if (code == PET_NOT_FOUND) {
        return (OPTIONAL(Pet)) OPTIONAL_PRESENT(&default_pet);
    }
    return (OPTIONAL(Pet)) OPTIONAL_EMPTY;
}

// Assigns a value to a global variable as a side effect
static void set_side_effect(int value) {
    side_effect = value;
}

// Keeps track of the last error encountered
static void log_error(pet_error error) {
    last_error = error;
}

// Returns the status of a pet by id
OPTIONAL(pet_status) get_pet_status(int id) {
    OPTIONAL(Pet) optional = find_pet(id);
    return OPTIONAL_MAP(optional, PET_STATUS, OPTIONAL(pet_status));
}

/**
 * Example snippets.
 */
int main() {
    {
//! [optional_struct]
OPTIONAL_STRUCT(pet_status);
//! [optional_struct]
    }

    {
//! [optional]
OPTIONAL(pet_status) optional;
//! [optional]
        (void) optional;
    }

    {
//! [optional_tag]
OPTIONAL_STRUCT_TAG(Pet, OPTIONAL_TAG(Pet));
OPTIONAL(Pet) optional = OPTIONAL_EMPTY;
assert(OPTIONAL_IS_EMPTY(optional));
//! [optional_tag]
        (void) optional;
    }

    {
//! [optional_present]
OPTIONAL(pet_status) optional = OPTIONAL_PRESENT(AVAILABLE);
assert(OPTIONAL_IS_PRESENT(optional));
//! [optional_present]
        (void) optional;
    }

    {
//! [optional_empty]
OPTIONAL(pet_status) optional = OPTIONAL_EMPTY;
//! [optional_empty]
        (void)optional;
    }

    {
//! [optional_of_nullable]
Pet pet = NULL;
OPTIONAL(Pet) optional = OPTIONAL_OF_POSSIBLY_FALSY(pet);
assert(OPTIONAL_IS_EMPTY(optional));
//! [optional_of_nullable]
        (void) optional;
    }

    {
        OPTIONAL_STRUCT(int);
//! [optional_of_possibly_falsy]
int age = 0;
OPTIONAL(int) optional = OPTIONAL_OF_POSSIBLY_FALSY(age);
assert(OPTIONAL_IS_EMPTY(optional));
//! [optional_of_possibly_falsy]
        (void) optional;
    }

    {
//! [optional_is_present]
OPTIONAL(pet_status) optional = OPTIONAL_PRESENT(AVAILABLE);
bool is_present = OPTIONAL_IS_PRESENT(optional);
assert(is_present == true);
//! [optional_is_present]
        (void) is_present;
    }

    {
//! [optional_is_empty]
OPTIONAL(pet_status) optional = OPTIONAL_EMPTY;
bool is_empty = OPTIONAL_IS_EMPTY(optional);
assert(is_empty == true);
//! [optional_is_empty]
        (void) is_empty;
    }

    {
//! [optional_use_value]
OPTIONAL(pet_status) optional = OPTIONAL_PRESENT(AVAILABLE);
pet_status value = OPTIONAL_USE_VALUE(optional);
assert(value == AVAILABLE);
//! [optional_use_value]
        (void) value;
    }

    {
//! [optional_get_value]
OPTIONAL(pet_status) optional = OPTIONAL_PRESENT(AVAILABLE);
const pet_status *value = OPTIONAL_GET_VALUE(optional);
assert(*value == AVAILABLE);
//! [optional_get_value]
        (void) value;
    }

    {
//! [optional_or_else]
OPTIONAL(pet_status) optional = OPTIONAL_EMPTY;
pet_status value = OPTIONAL_OR_ELSE(optional, PENDING);
assert(value == PENDING);
//! [optional_or_else]
        (void) value;
    }

    {
OPTIONAL_STRUCT(int);
//! [optional_if_present]
OPTIONAL(int) optional = OPTIONAL_PRESENT(123);
side_effect = 0;
OPTIONAL_IF_PRESENT(optional, set_side_effect);
assert(side_effect == 123);
//! [optional_if_present]
    }

    {
OPTIONAL_STRUCT(int);
//! [optional_if_present_or_else]
OPTIONAL(int) optional = OPTIONAL_EMPTY;
side_effect = 0;
last_error = OK;
OPTIONAL_IF_PRESENT_OR_ELSE(optional, set_side_effect, log_error(PET_NOT_FOUND));
assert(side_effect == 0);
assert(last_error == PET_NOT_FOUND);
//! [optional_if_present_or_else]
    }

    {
#define is_available(pet) (PET_STATUS(pet) == AVAILABLE)
//! [optional_filter]
struct pet sold = {.status = SOLD};
OPTIONAL(Pet) optional = OPTIONAL_PRESENT(&sold);
OPTIONAL(Pet) filtered = OPTIONAL_FILTER(optional, is_available);
assert(OPTIONAL_IS_EMPTY(filtered));
//! [optional_filter]
#undef is_available
        (void) filtered;
    }

    {
        OPTIONAL_STRUCT(int);
//! [optional_filter_falsy]
int age = 0;
OPTIONAL(int) optional = OPTIONAL_PRESENT(age);
OPTIONAL(int) filtered = OPTIONAL_FILTER_FALSY(optional);
assert(OPTIONAL_IS_EMPTY(filtered));
//! [optional_filter_falsy]
        (void) filtered;
    }

    {
//! [optional_filter_null]
Pet pet = NULL;
OPTIONAL(Pet) optional = OPTIONAL_PRESENT(pet);
OPTIONAL(Pet) filtered = OPTIONAL_FILTER_NULL(optional);
assert(OPTIONAL_IS_EMPTY(filtered));
//! [optional_filter_null]
        (void) filtered;
    }

    {
//! [optional_map]
struct pet sold = {.status = SOLD};
OPTIONAL(Pet) optional = OPTIONAL_PRESENT(&sold);
OPTIONAL(pet_status) mapped = OPTIONAL_MAP(optional, PET_STATUS, typeof(mapped));
assert(OPTIONAL_USE_VALUE(mapped) == SOLD);
//! [optional_map]
    }

    {
//! [optional_flat_map]
struct pet sold = {.status = SOLD};
OPTIONAL(Pet) optional = OPTIONAL_PRESENT(&sold);
OPTIONAL(Pet) mapped = OPTIONAL_FLAT_MAP(optional, buy_pet);
assert(OPTIONAL_IS_EMPTY(mapped));
//! [optional_flat_map]
        (void) mapped;
    }

    {
//! [optional_or]
OPTIONAL(Pet) optional = OPTIONAL_EMPTY;
OPTIONAL(Pet) mapped = OPTIONAL_OR(optional, pet_get_default(PET_NOT_FOUND));
assert(strcmp(PET_NAME(OPTIONAL_USE_VALUE(mapped)), "Default pet") == 0);
//! [optional_or]
        (void) mapped;
    }

    {
        OPTIONAL(pet_status) optional1 = get_pet_status(0);
        assert(OPTIONAL_IS_PRESENT(optional1));
        assert(OPTIONAL_USE_VALUE(optional1) == AVAILABLE);
        (void) optional1;
        OPTIONAL(pet_status) optional2 = get_pet_status(-1);
        assert(OPTIONAL_IS_EMPTY(optional2));
        assert(OPTIONAL_IS_EMPTY(optional2) == PET_NOT_FOUND);
        (void) optional2;
    }

    {
        assert(pet_store_application(1, (char * []) { "0" }) == 0);
        assert(pet_store_application(1, (char * []) { "1" }) != 0);
        assert(pet_store_application(1, (char * []) { "2" }) != 0);
        assert(pet_store_application(1, (char * []) { "3" }) != 0);
    }

    return 0;
}
