---

## Functions in C
* Functions are the mechanism in C used to define reusable chunks of code
* They allow us to divide and conquer and support the reuse of pre-written code to be shared by multiple programs 
* We have already used (called) several functions, such as `printf()` and `fgets()`
* C programs are composed of one or more functions, starting with the `main()` function which serves as the entry point
* Each function has an associated code block, to be executed when the function is called
* A function may accept parameter values, and return a result value

---

## Defining Functions
* We define a function using a **signature**, followed by the associated code block
* A signature contains a return type, a function name, and a formal parameter list (of zero or more parameters which are expected)
* Functions are declared at the top level within a compilation unit (i.e. within a .c file, and not nested within another code block)

```c
// [return type] [function name] ([parameter type and name])
float calc_taxable_value(float amount) {   
    float result = amount * 0.20;   
    result += amount;   
    return result; // value returned to the caller of the function
}
```

---

## Calling a Function
* Once a function is known (declared), code to call the function can be written
* Calling a function causes the code block of the function to be executed, and the result to be returned to the caller, e.g.

```c
int main(void) {   
    // float total is the returned value
    // 121 is the value passed as the actual parameter, accessed as 'amount' 
    float total = calc_taxable_value(121);   
    printf("The total amount due on £121 is £%.2f\n", total);   
    
    total = calc_taxable_value(290);   
    printf("The total amount due on £290 is £%.2f\n", total);
}
```

---

## Function Declarations
* Within the C, functions must be declared before they can be called, i.e. the compiler must have seen the function prior to any calls being made
* In practice, we split our code (and different functions) across several source code files, so the order of compilation can become complicated
* Even within the same `.c` file we may have many functions, which may wish to call each other (resulting in many chicken and egg type situations)
* To help this dependency issue we can declare a function, prior to actually providing the function definition (i.e. function with its associated code)
* A declaration is provided using just the signature, with no associated code, e.g.

```c
float calc_taxable_value(float amount); // a function declaration
```
* When using `#include` directives, we are typically just reading a file containing multiple function declarations, thus allowing us to write code calling these functions

---

## Function Declaration Example
```c
// Function "Declarations" allow functions to be called (before code provided)
void funcA(float amount);
float funcB(float amount, int mult);

int main(void) {   
   funcA(100);          // Can call Functions, since "declared" above   
   funcB(12.4, 10);     // Without declarations, these calls would be reported as an error
}

// Function "Definitions" provides actual implementation
void funcA(float amount) {   
   printf("FuncA called with %f\n", amount);
}

float funcB(float amount, int mult) {   
   float result = amount * mult;   
   printf("FuncB calculated result to be returned as %f\n", result);   
   return result;
}
```

---

## Variable Scope
* All variables within the C language have a scope, which determines from where the variable can be accessed
* Variables which are declared within a code block, i.e. surrounded by `{...}` can only be accessed from within that block
* Variable do not exists outside their own scope, this is also true of parameters within functions (i.e. they only exist within their owning function), these are hence called **local variables**
* This means variables with the same name can exist within different code blocks, and although they have the same name, do not contain the same value
* If we declare a variable outside of code block (usually at the top of our `.c` file) then it is accessible to all functions, and sometimes called **global variables**

---

## Variable Scope Example
```c
float total_diff = 0;   // a global variable, accessible everywhere

void diff(int first, int second) {   
    // this local variable 'diff' is only accessible within this function   
    int diff = second - first; 
    printf("Difference is = %d", diff); 
    total_diff += diff;     // total_diff is global (shared by all)
}

void diff_float(float first, float second) {   
    // this local variable 'diff' is different to the 'diff' in the other function   
    float diff = second - first;  
    printf("Difference is = %f", diff); 
    total_diff += diff;
}

int main(void) {   
    diff(100, 200);   
    diff(50, 75); 
    diff_float(65.2, 100.2); 
    printf("The Total Difference is = %f", total_diff);
}
```

---

## Modular Programming
* Large programs, written in almost all languages, need to be broken up into manageable portions or modules
* Within C we typically write large programs using functions spread across multiple source files (`.c`), with these functions calling each other
* However, as stated earlier, a function can only be called once declared (seen by the compiler)
* To deal with this we also create what are called **header files** (`.h` files) which contains the declarations of the functions we wish to be called from other functions
* Within these header files we can even make global variables visible to other source files also

---

## Header File Example

**Header file `my_str_lib.h`** (declares the functions to be made available to other source files. This can be `#include`'d when required)
```c
// my_str_lib.h header file
#ifndef MY_STR_LIB_H
#define MY_STR_LIB_H

int get_length(char str[]);
void make_uppercase(char str[]);
void make_lowercase(char str[]);
int get_word_count(char str[]);
int get_vowel_count(char str[]);

#endif //MY_STR_LIB_H
```

**Source file `my_str_lib.c`** (provides the implementation code for each of the declared functions, this also `#include`'s the file header file)
```c
// my_str_lib.c source file
#include "my_str_lib.h"

// function implementations appear here
```

---

## Summary
* Functions are a key mechanism for managing complexity and allowing re-use of code, they have a return type, name, and formal parameter list
* Functions need to be declared prior to use, using just their signature
* Variables have a scope, which determines from where they can be accessed, generally we think of this as either local or global
* We often separate code into multiple source (`.c`) and header (`.h`) files to support the concept of modular programming