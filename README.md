
[![Build Status][BADGE_BUILD_STATUS]][BUILD_STATUS]
[![Quality Gate Status][BADGE_QUALITY_GATE]][QUALITY_GATE]
[![Docs Status][BADGE_DOCS_STATUS]][DOCS]
[![Latest Release][BADGE_LATEST_RELEASE]][LATEST_RELEASE]

![Optional Library][LOGO]

## A General-Purpose Maybe Type for C

Represent missing values explicitly without `NULL` or *sentinel values*.

![][EXAMPLE]

> [!NOTE]
> [Schrödinger's cat][SCHRODINGERS_CAT] is inside a box. Until you look, you don't know if it's *alive* or *dead*. A
> [Maybe type][MAYBE_TYPE] works the same way. It either contains a cat, meaning you have a value, or it's empty,
> meaning you have nothing. Instead of risking errors when there's no cat, **Optional** makes you handle both cases
> explicitly, eliminating the need for [null checks][NULL_CHECKING] or [sentinel values][SENTINEL_VALUE].


## Author

Copyright 2025 [Guillermo Calvo][AUTHOR].

[![][GUILLERMO_IMAGE]][GUILLERMO]


## License

This library is licensed under the *Apache License, Version 2.0* (the "License");
you may not use it except in compliance with the License.

You may obtain a copy of the License at <http://www.apache.org/licenses/LICENSE-2.0>

Unless required by applicable law or agreed to in writing, software distributed under the License
is distributed on an "AS IS" BASIS, **WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND**, either express or implied.

See the License for the specific language governing permissions and limitations under the License.


**Permitted:**

- **Commercial Use**: You may use this library and derivatives for commercial purposes.
- **Modification**: You may modify this library.
- **Distribution**: You may distribute this library.
- **Patent Use**: This license provides an express grant of patent rights from contributors.
- **Private Use**: You may use and modify this library without distributing it.

**Required:**

- **License and Copyright Notice**: If you distribute this library you must include a copy of the license and copyright
  notice.
- **State Changes**: If you modify and distribute this library you must document changes made to this library.

**Forbidden:**

- **Trademark use**: This license does not grant any trademark rights.
- **Liability**: The library author cannot be held liable for damages.
- **Warranty**: This library is provided without any warranty.


[AUTHOR]:                       https://github.com/guillermocalvo/
[BADGE_BUILD_STATUS]:           https://github.com/guillermocalvo/optional/workflows/Build/badge.svg
[BADGE_DOCS_STATUS]:            https://github.com/guillermocalvo/optional/workflows/Docs/badge.svg
[BADGE_LATEST_RELEASE]:         https://img.shields.io/github/v/release/guillermocalvo/optional
[BADGE_QUALITY_GATE]:           https://sonarcloud.io/api/project_badges/measure?project=guillermocalvo_optional&metric=alert_status
[BUILD_STATUS]:                 https://github.com/guillermocalvo/optional/actions?query=workflow%3ABuild
[DOCS]:                         https://optional.guillermo.dev/
[EXAMPLE]:                      docs/example.png
[GUILLERMO]:                    https://guillermo.dev/
[GUILLERMO_IMAGE]:              https://guillermo.dev/assets/images/thumb.png
[LATEST_RELEASE]:               https://github.com/guillermocalvo/optional/releases/latest
[LOGO]:                         docs/optional-logo.svg
[MAYBE_TYPE]:                   https://en.wikipedia.org/wiki/Option_type
[NULL_CHECKING]:                https://en.wikipedia.org/wiki/Nullable_type#Compared_with_null_pointers
[QUALITY_GATE]:                 https://sonarcloud.io/dashboard?id=guillermocalvo_optional
[SCHRODINGERS_CAT]:             https://en.wikipedia.org/wiki/Schr%C3%B6dinger%27s_cat
[SENTINEL_VALUE]:               https://en.wikipedia.org/wiki/Sentinel_value
