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

#define main pet_store_application

/** [application] */
#include <stdlib.h>
#include <stdio.h>
#include "pet-store.h"

// Prints pet details
static void print_pet(const struct pet *pet) {
  printf(">>> Pet(id: %d, name: %s, status: %s)\n",
    PET_ID(pet),
    PET_NAME(pet),
    pet_status_name(PET_STATUS(pet)));
}

// Prints pet error
static void print_error(const pet_error error) {
  printf(">>> Error: %s\n", pet_error_message(error));
}

// Pet store application
int main(int argc, char *argv[]) {
  int pet_id;
  OPTIONAL(Pet) optional;

  if (argc != 1) {
    printf("Error: Please provide one argument (pet ID)\n");
    return EXIT_FAILURE;
  }

  if (sscanf(argv[0], "%d", &pet_id) != 1) {
    printf("Error: Illegal pet ID provided: %s\n", argv[0]);
    return EXIT_FAILURE;
  }

  printf("Finding pet %d...\n", pet_id);
  optional = find_pet(pet_id);
  OPTIONAL_IF_PRESENT_OR_ELSE(optional, print_pet, print_error);

  printf("Buying pet...\n");
  optional = OPTIONAL_FLAT_MAP(optional, buy_pet);
  OPTIONAL_IF_PRESENT_OR_ELSE(optional, print_pet, print_error);

  if (OPTIONAL_IS_EMPTY(optional)) {
    printf("Sorry!\n");
    return EXIT_FAILURE;
  }

  printf("Thank you!\n");
  return EXIT_SUCCESS;
}
/** [application] */

#undef main
