# Drift

A header-only C++ helper library I built from the functions I kept rewriting while solving the [Programming Advices roadmap](https://github.com/abod1nd/programming-advices-roadmap) problems.

## Usage

Add one line at the top of your file:

```cpp
#include "C:/path/to/Drift/Drift.h"
```

If you use any random function, call `srand((unsigned)time(NULL));` once at the start of `main`.

To use only one part, include its file instead of `Drift.h` (for example `PrintLib.h`).
`ArrayLib.h` also brings in `InputLib.h`, `RandomLib.h` and `MathLib.h`.

Don't write a function with the same name as a library function in a file that includes the library.

## Files and naming rules

| File | Section | Naming rule |
|---|---|---|
| `InputLib.h` | Reading from the user | `Read` + what it reads (returns it). `Ask` for yes/no questions (returns `bool`). The first parameter is always `string Message`. |
| `RandomLib.h` | Random | `Random` + the type of one random value. `Generate` + what it builds from several random values. |
| `PrintLib.h` | Printing | `Print` + what it prints. Returns `void` and prints no titles or extra blank lines. |
| `StringLib.h` | Strings and characters | A verb (`Upper`, `Lower`, `Encrypt`...) + the part that changes. Takes the text and returns a changed copy, with no reading or printing. |
| `MathLib.h` | Numbers and math | `Is` + property + `Number` returns `bool`. My versions of C++ functions start with `My`. The number is always the first parameter. |
| `ArrayLib.h` | 1D arrays | Every name contains `Array`. The array comes first, then its length, then anything else. |
| `MatrixLib.h` | 2D arrays | Every name contains `Matrix` (or `Matrices`). Matrices come first, then `Rows` and `Cols`, then anything else. |
| `FileLib.h` | Files | A verb (`Load`, `Save`, `Delete`, `Update`, `Print`) + where (`FromFile`, `ToFile`, `InFile`). `FileName` is always the first parameter. |
| `ScreenLib.h` | Console screen (Windows) | `Reset` / `Set` + `Screen` + what changes. |

## Conventions

- Header-only: every file holds the full functions, so `#include` is all you need.
- 1D arrays are `int Arr[100]` with a `Length`.
- 2D arrays are `int Matrix[10][10]` with `Rows` and `Cols` (any size up to 10x10).
- Enums are `enum class`, used like `enNumberType::Prime`.
- Some functions have optional parameters:

```cpp
ReadNumber("Enter a number:");          // any int
ReadNumber("Enter a number:", 1);       // 1 or more
ReadNumber("Enter a number:", 1, 10);   // from 1 to 10

CopyArray(A, n, B, m);                          // copy everything
CopyArray(A, n, B, m, enNumberType::Prime);     // copy primes only
CountNumbersInArray(A, n, enNumberType::Odd);   // count odd numbers
```

## Adding a function

1. Put it in the file of its section and name it by that section's rule.
2. Place it below any function it calls.
3. Add a quick check for it in `Test.cpp`.

Commit messages: `<file>: <what changed>`, for example `StringLib: add InvertLetterCase`.
