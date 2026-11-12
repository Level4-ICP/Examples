# Arrays and Pointers

## Overview
- Arrays (revisited)
- Array access
- Multi-Dimensional Arrays
- Pointers in C
- Pointer Specific Operators
- Pointers and Arrays, and Arrays of Pointers
- Pointer Arithmetic
- Summary

---

# Arrays
- Arrays are typically present in most programming languages.
- They allow us to group multiple values and refer to these through a single variable or parameter name.
- Within the C language an array size is fixed, and contains values based on the same data type (i.e. they are homogeneous).
- An array is actually just a contiguous block of memory, large enough to store all values (of the specified type).
- Arrays are the most basic type of "collection" that we can use in our programs.
- The syntax used in C to refer to an array is the square brackets `[ ]`, which are used to both declare an array type variable and also to access the elements of the array.

---

## Arrays - Examples
- Arrays are commonly used to represent Strings in C, as an array of `char` type, e.g.,
  ```c
  char name[] = "Neil Armstrong";
  ```
- However, arrays can be based on any data type, including user-defined types, e.g.,
  ```c
  float averages[100];        // an array of 100 float values
  struct student students[10];  // an array of 10 'student' structs
  ```
- We can also initialise an array when declared, which can auto-size the array, e.g.,
  ```c
  int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
  ```
    - This creates an array of size 8 (each value containing an `int`).

---

## Array Access
- Once declared, we can access (read and write individual values) using a zero-based numerical index (a subscript), as follows:
  ```c
  char name[] = "Neil Armstrong";
  char initial = name[0]; // get the first letter of name
  name[1] = 'i';
  name[2] = 'a';          // changes Neil to Nial
  ```
- **Important:** C does not "bounds check" access to an array, which can lead to a number of difficult-to-locate bugs, and also security issues.
- The following is valid code in C and will execute, but what will this do?
  ```c
  name[10] = 'P';
  ```
    - Well, it will write into some memory (which is not part of the array). If you are lucky this "may" be detected as a security issue, but maybe not!

---

## Multi-Dimensional Arrays
- Arrays can contain more than one dimension, e.g.,
  ```c
  int grid[2][5] = { {1,2,3,4,5}, {1,4,9,16,25} };
  ```
- We then can access these as follows:
  ```c
  int pos = grid[0][3];   // access element 0,3 from the array
  grid[1][2] = 5;         // replace element 1,2
  ```
- At least 256 dimensions can be supported, but in practice anything more than three-dimensional arrays can get difficult to work with.
- You can think of a 1-dimensional array as a list; a 2-dimensional array as a table; and a 3-dimensional array as a cube.
- Working with arrays in C, especially those of more than one dimension, is often done in combination with pointers.

---

## Getting the Size of an Array
- As stated, an Array is simply a block of memory, exactly the right size to store its elements.
- Since arrays are created with a fixed size, we often already know the size of the array, however in some cases it is useful to determine this at run-time.
- No other data is stored which can be used to identify the size of the array, but this can be calculated if required using the `sizeof()` operator, e.g.,
  ```c
  array_size = sizeof(num_list) / sizeof(int);
  ```
- This works since `sizeof()` returns the amount of memory (in bytes) of the whole array, so dividing that by the size of each element gives the size.

Look at `arrays.c` in this repo for working examples of the above. Run it in the debugger
to see exactly how they work.
---

# Pointers
See `pointers.c`

## Computer Memory
- Each byte in memory has an address starting at zero and going up to a big number.
- Typically, the address is expressed in base 16 (hexadecimal).
- This makes addresses more manageable and they line up as 16 is a power of 2.
  - `140734799803920` in hex is `0x7FFF5FBFF610`.
- Because 16 is a power of 2 it maps to binary (base 10 doesn't):
      ```text
      0111 1111 1111 1111 0101 1111 1011 1111 1111 0110 0001 0000
         7    F    F    F    5    F    B    F    F    6    1    0
      ```
      *(Each 4 bits is one hex digit)*

---

## Memory Layout
- Each variable is somewhere in memory.
- We usually don't have to worry about exactly where as it is easier to talk about the variable name.
  ```c
  int num1 = 10;
  ```
- Does two things: it allocates 4 bytes of memory (it's up to the system where) and stores the integer value `10` there.
- When we later read `num1`, it knows where in memory it is, that it is a 4-byte integer and can retrieve its value.
- That's what high-level languages do—stuff for us so we don't have to.

---

## Pointers in C
- The concept of Pointers is one of the most important aspects of the C language.
- Pointers allow us to create a reference to a variable (or function).
- A Pointer is actually just an integer, which stores a memory address.
- Pointers allow us to access memory directly, so are powerful but dangerous.
  - dangerous means incorrect use can cause erratic behaviour and crashes.
- One of the main reasons Pointers exist is for efficiency purposes
  - they are not supported in most other languages.
- The ability to access memory directly is one of the reasons C is used to implement "low-level" programs (such as Operating Systems).

---
## Pointers - Example
- Within C, some specific operators are used to work with pointers, which are `&`, `*`, and `->`.
- We can get the address of a variable (i.e., a pointer) as follows:
  ```c
  int age = 10;
  int *age_ptr = &age; // get a pointer to age (the address of the memory holding age)
  ```
- The ampersand (`&`) indicates we want the memory address of the variable, as opposed to the value stored within the variable.
- The asterisk (`*`) indicates the declared variable's data type is actually a pointer to an integer, rather than an integer value.
- note, you can use int* ptr (C++), or int *ptr (C) both work
  - there is a difference if you declare more than one
  ```C
    int *ptr1,ptr2; //this only declares one pointer, ptr2 is a normal variable
    int* ptr1,ptr2; //this does declare two pointers
    ```
---

## Dereferencing
- To work with pointers we need a way of accessing the value to which they refer, this is called **dereferencing**.
- We do this by again using the asterisk (`*`) character, e.g.:
  ```c
  int age = 10;
  int *age_ptr = &age; // get a pointer to age (the address of the memory holding age)
  int age_copy = *age_ptr;   // copy the referenced integer value
  *age_ptr = 11;             // set the referenced integer value to 11
  ```
- The last example would change the actual value stored by the `age` variable, since `age_ptr` points to the memory address which stores this.
- The best way to read these dereferences is: **"the value pointed to by..."**
  ```c
  (*age_ptr)++; // increment the 'value pointed to by age_ptr'
  ```

---

## Efficiency and Pointers
- People new to C do not always understand why we need pointers, but as already stated, **efficiency** is one of the main reasons.
- Some variable values can require a lot of memory, for example we could create a `struct` type which took hundreds of bytes for a single instance.
- Being able to pass references to values means we only need to copy memory used to store a pointer, rather than the memory of the value itself.
- Passing arrays is another good example; in C we tend to pass a pointer to the array, rather than copying the entire array itself.
- A particularly common use of pointers is when we are passing (potentially large) values to functions as parameters.

---

## Efficiency and Pointers - Example

see `pointers_structs.c`

```c
struct stock_item {
    int id;
    float price;
    unsigned stock_level;
};

void print_stock_item(struct stock_item *item) {
    printf("ID:%d, price:£%.2f, level:%d\n", (*item).id, (*item).price, (*item).stock_level);
}

int main() {
    struct stock_item item = { 10, 1.56, 100};
    print_stock_item(&item);    // pass address of the item
}
```
- Function takes a "pointer" to the structure.
- Only a "pointer" needs to be copied, not the whole structure.
- Parameters need to be dereferenced to access the actual values.

---

## Dereferencing Using `->`
- In the previous example, the `item` parameter needed to be dereferenced before each member of the struct was accessed, since it was a pointer, e.g., `(*item).id`.
- This is dereferencing the pointer, thus getting the struct value, then accessing a member of that struct value.
- Since this is a little ugly, there is an alternative syntax which can be used when accessing members of a struct or union via a pointer, as follows:
  ```c
  item->id
  // the example above should have
  printf("ID:%d, price:$%.2f, level:%d\n", item->id, item->price, item->stock_level);
  ```
- This does exactly the same as the original version, but with a simpler syntax, 
- and is the usual way C programmers dereference when dealing with structs and unions.

---

## Passing Values By Reference
see `pass_by_reference.c`
- In addition to efficiency, another main reason for using pointers is the ability to use **call by reference** semantics when calling functions.
- This is basically the same as we have already seen, but done to allow functions to directly update variables passed as parameters, e.g.:
  ```c
  // A function which takes a 'pointer' to an int
  void sqr_num(int *num) 
  {
     *num = (*num) * (*num); // square the actual value passed
  }

  int main() 
  {
     // call the function, passing the address of the variable 'total'
     int total = 10;
     sqr_num(&total);
     // 'total' will now be set to 100
  }
  ```

---

## Pointers and Arrays
see `arrays_and_pointers.c`
- Pointers and Arrays are often used together in C, however **they are not the same thing** as some people believe.
- Arrays are fixed size blocks of memory which store homogeneous values, whereas Pointers are a reference to some other value.
- However, if we access an array type variable, it provides the address of the first element (i.e. it stores the address of the first byte of the array), e.g.:
  ```c
  int num_array[10];
  int *nums = num_array;  // get a ptr to the first element of the array
  ```
- So, in many cases, array and pointer type values become interchangeable.
- The above is actually exactly the same as doing:
  ```c
  int *nums2 = &num_array[0];  // this would give the same memory address
  ```

---

## Pointers and Arrays (Cont.)
- Since Pointers and Arrays are different, the rules of how they can be used do vary; arrays are typically more restrictive.
- An array variable cannot be directly assigned to, whereas a pointer can, e.g.:
  ```c
  int num_array[10];
  int *num_ptr = NULL;

  num_array = nums;      // illegal, cannot assign to an array
  num_ptr = &some_var;   // totally legal, can assign to a pointer
  ```
- This means we are also not allowed to do arithmetic with arrays, but we can with pointers, e.g.:
  ```c
  num_array++; // illegal, since the array variable cannot be assigned
  num_ptr++;   // legal, updates the pointer to refer to the subsequent value
  ```

---

## Pointers and Arrays (Subtleties)
- There are other subtle similarities and differences also.
- The following both create something that can be used as a string, but are different:
  ```c
  char name1[] = "Mark";  // creates an array initialised to "Mark", chars can be updated at run-time
  char *name2 = "Mark";   // points to the string "Mark" (probably stored in read-only memory)
  ```
    - `name1` characters could be changed, but the `name1` variable cannot.
    - `name2` characters cannot be changed, but the `name2` variable can.
- A pointer can be indexed like an array, e.g. the following is valid:
  ```c
  char initial = name2[0];
  ```
- When an array type value is passed as a function parameter, it is actually passed as a pointer (not an array)—so getting the `sizeof()` an array type param will actually give you the `sizeof()` the pointer.

---

## Arrays of Pointers
- It is very common to see arrays which contain elements which are actually pointers, rather than just regular values.
- We can for example declare an array of pointers to integers as follows:
  ```c
  int *num_plist[10];  // an array of 10 pointers (to int)
  ```
- The values stored in the array are pointers, and not integers.
- It is very common to see arrays of pointers to char, for example the `main` function is often declared as follows:
  ```c
  int main(int argc, char *argv[])
  ```
    - When `main` is called an array of pointers to `char` is passed in the second parameter. Can you guess what these values are? (Command line arguments!)

---

## Pointer Arithmetic
- Since pointers store memory addresses, many arithmetic type operations are of little use to us, e.g., multiplication.
- However **Addition** and **Subtraction** are very useful when working with pointers, especially if the pointer refers to elements of an array.
- Adding `1` to a pointer does not simply add 1 byte to the memory address, it adds the **size of the type** to which the pointer refers.
- When iterating over an array of values, incrementing a pointer is typically faster than indexing into an array, hence this is commonly used.
- Comparison of pointers is also possible using relational operators.

---

## Pointer Arithmetic - Example
- The following example steps through an array, using pointer arithmetic to access each element in turn:
  ```c
  int total = 0;
  unsigned size = sizeof(num_list) / sizeof(int);
  int *next_num = num_list;

  while (size--) {
     total += *next_num;
     next_num++; // inc pointer to address of next array element
  }
  ```
- **Note:** Most C programmers would often combine the access and the increment, e.g.:
  ```c
  total += *next_num++;
  ```

---

## Pointer Aliasing
- **Pointer aliasing** refers to the situation when more than one pointer actually refers to the same thing, e.g.:
  ```c
  int age;
  int *p_age1 = &age;
  int *p_age2 = p_age1; // p_age2 now also refers to 'age'
  ```
- Remember: a pointer is simply a memory address, this means any number of pointers can refer (or update) the exact same value, e.g.:
  ```c
  (*p_age2)++; // increments 'age', since p_age1 and p_age2 refer to same value
  ```
- Therefore, when a pointer is passed to a function, the function has the power to change the actual value passed (not a copy).
- Having multiple pointers referring to the same value can lead to difficult-to-detect bugs, and also dangling pointers (if they refer to variables which no longer exist for example).

---
## Command Line Arguments In C

see `command_line.c`

Programs can accept inputs directly from the terminal when they are executed. 

This is handled through the parameters of the main() function: argc and argv.

`argc` (Argument Count): An integer that stores the number of arguments passed to the 
program, including the program name itself.

`argv` (Argument Vector): An array of pointers to strings (char*) containing the 
actual arguments passed.   Example: Exploring Command-Line ArgumentsThe following 
program prints its own name, counts how many additional parameters were provided
and lists each one:

```c
int main(int argc, char *argv[])
{
    printf("Program name: %s\n",argv[0]);
    printf("There are %d parameters.", argc-1); //-1 because it counts the program name
    for (int i=1; i<argc; i++)
    {
        printf("\nParameter %d : %s",i,argv[i]);
    }

}
```
## Summary
- The C language relies heavily on the use of arrays and pointers, and although often used together these are very **different entities**.
- Arrays provide a simple mechanism for working with collections of values, whereas pointers allow indirect access to values via memory addresses.
- Pointers are declared and manipulated using the `&`, `*`, and `->` operators.
- Using simple arithmetic (add/subtract) operators is common with pointers.
- Support for pointers is what makes C such a powerful and flexible language, but using pointers incorrectly can be dangerous in many ways!