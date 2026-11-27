# The Standard Library
**Introduction to the C programming language**

---

## Overview

* What is the C Standard Library?
* Commonly Used Headers
  * Input/Output, Utilities, Maths, String and Character manipulation
* Usage Examples
* Linking to the math library
* Summary

---

## The C Standard Library

* A library is a collection of pre-written functionality which allows programmers to perform common tasks by calling functions.
* The C language includes the standard C library.
* Although much smaller than standard libraries of other languages, the C standard library provides an extremely useful set of functions.
* The library is divided into multiple components, typically grouped into functions that support related functionality.
* We access these components by first including the appropriate C header (`.h`) file, e.g., `#include <stdio.h>`.
* Header files usually contain function prototypes, variable declarations, and macros.

---

## Commonly Used Headers

As of the C23 standard there are over thirty header files within the standard library. The most commonly used of these are as follows:

* [stdio.h](https://www.w3schools.com/c/c_ref_stdio.php) - Support for Input/Output operations
* [stdlib.h](https://www.w3schools.com/c/c_ref_stdlib.php) - Provides standard general utility functions
* [math.h](https://www.w3schools.com/c/c_ref_math.php) - Support for Mathematical operations
* [string.h](https://www.w3schools.com/c/c_ref_string.php) - Functions to manipulate C strings and memory
* [time.h](https://www.w3schools.com/c/c_ref_time.php) - Provides access to date and time information
* [ctype.h](https://www.w3schools.com/c/c_ref_ctype.php) - Character handling functions
* Other headers include `limits.h`, `threads.h`, `stdarg.h`, `signal.h`, etc.

---

## Standard Input/Output (`stdio.h`)

* This is one of the most commonly used headers, since it provides functions to perform input and output operations.
* These operations typically work with files, or standard input/output.
* Functions for file manipulation such as `fopen()`, `fclose()`, `fseek()`, `ftell()`, `remove()`, `rename()`, etc. are defined in this header.
* Functions to perform output operations are also defined, e.g., `printf()`, `puts()`, `fputc()`, `fwrite()`, etc.
* Finally, functions are included to support input operations, e.g., `scanf()`, `fgets()`, `fgetc()`, `fread()`, etc.

---

## Standard Utilities Library (`stdlib.h`)

* The functions provided within this header are less cohesive in nature; they support useful (but often unrelated) functionality.
* Memory management functions such as `malloc()`, `calloc()`, `realloc()`, and `free()` are declared in this header.
* Functions for converting string type values to numeric type values are also declared, such as `atoi()`, `atol()`, and `atof()`.
* The random number generator `rand()` function, and integer arithmetic functions, such as `abs()` and `div()`, are also provided.
* Environment control functions, such as `exit()`, `system()`, and `getenv()`, are also provided.

---

## Standard Utilities Library - Example

```c
#include <stdio.h>
#include <stdlib.h>

void main()
{
    /* generate 10 random numbers between 1 and 100 */
    for(int i=0; i < 10; i++)
    {
        // use rand() function defined in stdlib.h
        int next = rand() % 100 + 1;
        printf("%d ", next);
    }
}
```

When compiled and run, the above code may generate something like:

```text
84 87 78 16 94 36 87 93 50 22
```

---

## Mathematics Library (`math.h`)

* The math library is obviously very important for any program which performs some mathematical calculations, i.e., most programs.
* Trigonometry functions such as `sin()`, `cos()`, `tan()` are provided.
* Functions to support exponents and logarithms are also present, such as `exp()`, `log()`, `log2()`.
* Functions related to powers are present, such as `pow()`, `sqrt()`, `hypot()`.
* Rounding and remainder functions include `round()`, `trunc()`, `ceil()`, `floor()`.
* Functions for comparing floating-point values correctly are also provided, including `isgreaterequal()`, `isless()`, `islessequal()`, etc.

---

## Mathematics Library - Example

```c
#include <stdio.h>
#include <math.h>

double pythag(double a, double b)
{
    double c = sqrt( pow(a, 2.0) + pow(b, 2.0) );
    return c;
}

void main()
{
    printf("A triangle with sides 3 and 4, has a third side of %f\n", pythag(3,4));
}
```

> ```text
> A triangle with sides 3 and 4, has a third side of 5.000000
> ```

---

## String and Memory Manipulation (`string.h`)

* This header declares functions which allow manipulation of both strings and general blocks of memory.
* Functions to support copying include `strcpy()`, `strncpy()`, `memcpy()`.
* String and memory comparison can be performed using functions such as `strcmp()`, `strncmp()`, and `memcmp()`.
* Also there are a lot of useful functions for searching inside strings, such as `strstr()` and `strchr()`.
* Finally, `strlen()` is very commonly used to get the length of a C string, and `memset()` is used to fill a block of memory.

---

## String Manipulation - Example

```c
#include <stdio.h>
#include <string.h>

void main()
{
    char str[] = "A string containing the name Mark";
    printf("Attempting to locate 'M' in \"%s\"\n", str);
    char *ch = strchr(str, 'M');
    if (ch != NULL)
        printf("Found at position %d\n", ch - str);
}
```

When compiled and run, the above code may generate something like:

```text
Attempting to locate 'M' in "A string containing the name Mark"
Found at position 29
```

---

## Time and Date Manipulation (`time.h`)

* The `time.h` header provides functions for accessing the current `time()`, as well as displaying times and dates in text, via `asctime()` and `ctime()`.
* Custom display formats are also possible using `strftime()`.
* Time conversion functions are also available, which allow support for local and GMT time.
* The `difftime()` function can be used to calculate the difference between two times.
* Finally, a `clock()` function is also provided to measure the amount of time consumed by the process, useful for benchmarking.

---

## Time and Date - Example

```c
#include <stdio.h>
#include <time.h>

void main()
{
    time_t rawtime;
    time (&rawtime);
    printf ("The current local time is: %s", ctime (&rawtime));
}
```

When compiled and run, the above code may generate something like:

```text
The current local time is: Tue Nov 26 16:36:44 2024
```

---

## Character Manipulation (`ctype.h`)

* Functions provided by `ctype.h` allow manipulation of individual characters.
* The majority of the functions allow testing of a character type, e.g.:
  * `isalpha()` — Check if character is alphabetic
  * `isdigit()` — Check if character is decimal digit
  * `islower()` — Check if character is lowercase letter
  * `ispunct()` — Check if character is a punctuation character
  * `isspace()` — Check if character is a white-space
  * `isupper()` — Check if character is uppercase letter
* Two functions also exist that allow a character to be changed to `toupper()` or `tolower()` case.

---

## Character Manipulation - Example

```c
#include <stdio.h>
#include <ctype.h>

void main()
{
    char str[]="A string containing digits (1,2,3) and characters";
    int count = 0, i = 0;
    while (str[i])
    {
        if (isdigit(str[i]))
            count++;
        i++;
    }
    printf("The string contains %d digits.\n", count);
}
```

When compiled and run, the above code may generate something like:

```text
The string contains 3 digits.
```

---

## Summary

* The C standard library provides the bulk of common functionality required by most programs.
* Programs access these using the `#include <header_name.h>` directive to get access to declared function prototypes, variables, and macros.
* The Standard Input/Output (`stdio.h`) and the Standard Utilities library (`stdlib.h`) are the two most commonly used.
* The Mathematical support library (`math.h`) must be explicitly linked during the build process (as do all third-party libraries).
* For information on the C Library: [https://cplusplus.com/reference/clibrary/](https://cplusplus.com/reference/clibrary/)