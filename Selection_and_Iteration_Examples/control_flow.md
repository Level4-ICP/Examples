# Control Flow and Modular Programming
**Introduction to the C programming language**

## Overview
* Selection using Conditional Statements
* Iteration using Loops
* Functions
* Variable Scope
* Modular Programming
* Using Header Files
* Summary

---

## Selection with Conditional Statements
* To solve a problem within a program we implement an algorithm which contains a combination of sequence, selection and iteration
* Selection refers to the ability to execute a certain set of instructions conditionally (i.e. sometime, but not always)
* The C language provides several statements which allow programmers to implement the concept of selection:
  * `if..else` statements
  * `switch` (case) statements
  * ternary operators

---

## The 'if' statement
* The `if` statement exists in almost all programming languages
* This allows programmers to specify a condition which is evaluated, and code to be executed 'if' that condition evaluates to true (non-zero in C)
* The grammar is extremely simple, the only variation occurs when either a single or multiple statements occur in the code to be executed, e.g.

```c
if ( total > 100 ) {    // condition expression to be evaluated
    printf("The total is more than 100\n"); // code executed when true
}
```
* In the above example the `{` `}` are optional, but must be provided if more than one statement needs to be conditionally executed (creating a code block)

---

## The 'else' statement
* In some circumstances it is convenient to provide code to be executed when the condition is not true also, i.e. when the condition is false 
* We do this by adding an additional `else` clause to the end of the `if` statement, e.g.

```c
if ( total > 100 ) {
    printf("The total is more than 100\n");
}
else {  // code executed when the condition is false
    printf("The total is less or equal to 100\n");
}
```

---

## Chaining 'else if' statements
* It is possible to chain several `if` and `else` statements together. In this case the final `else` can only appear as the final clause (only one of these will ever execute), e.g.

```c
if ( total > 100 ) {
    printf("The total is more than 100\n");
}
else if ( total > 50 ) {
    printf("The total is more than 50, but less or equal to 100\n");
}
else if ( total > 25 ) {
    printf("The total is more than 25, but less or equal to 50\n");
}
else {  // final 'else' clause, executes if all other statements fail to execute
    printf("The total is less or equal to 25 \n");
}
```

---

## The 'switch' statement
* Long chains of `if..else` statements can be inefficient, or awkward to read in code
* If all conditions examine the same variable for equality against constant values, then a `switch` statement is an alternative option to using `if`
* These type of statements are much more restrictive than `if` statements, since they effectively only implement the `==` operator as a condition
* They can also only compare values which are integer types
* Each `case` identifies the matching value, and associated code, followed by a `break` statement indicating the end of that specific case

---

## A 'switch' example
```c
switch (input) { // evaluates the same as if (input == 'A')
    case 'A':   
        printf("Character is the vowel 'A'");   
        break; // end of the code executed, for this 'case'
    case 'E':   
        printf("Character is the vowel 'E'");   
        break;
    case 'I':   
        printf("Character is the vowel 'I'");   
        break;
    case 'O':   
        printf("Character is the vowel 'O'");      
        break;
    case 'U':   
        printf("Character is the vowel 'U'");   
        break;
    default: // optional 'default' code executed if all other cases fail
        printf("Character is a consonant\n");   
        printf("Please enter a vowel");   
        break;
}
```
* **Note:** the `break` statements are optional in C, and if not present execution falls through to the code in the subsequent case

---

## The Ternary Operator
* C includes a special operator which can be used as a compact form of `if..else`
* This can be placed directly within expressions, and is used to select a specific value to be used (e.g. assign a variable or pass a parameter)
* It is called the ternary operator, since it includes three operands, i.e. a condition, the value when true, and the value when false, e.g.

```c
int vat_rate = (is_food_item == 1) ? 0 : 20;
//             [condition expr]      [true val] : [false val]
```

---

## Iteration using loops
* Iteration refers to the ability to execute a certain set of instructions multiple times while a specific condition holds true
* The C language provides several statements which allow programmers to implement the concept of iteration (often referred to as loops):
  * `while` statements
  * `do…while` statements
  * `for` statements
* Iteration can also be implemented using a technique called recursion, however this is a topic best left until later in the course.

---

## The 'while' statement
* The `while` statement is the simplest way to implement iteration in C
* It takes the same form as `if` in that it provides a condition and some associated code to be executed, repeatedly as long as the condition evaluates to true
* If the condition never evaluates to true, then the code never executed, i.e. the code may execute zero to many times

```c
int count = 10;
while ( count > 0 ) { // condition expression
    // code block executed while the condition is true
    printf("The count is now %d\n", count); 
    count--;
}
printf("Loop has now finished, continuing with the program...\n");
```

---

## The 'do…while' statement
* The `do..while` statement is very similar to the `while` statement
* The difference being that the condition is evaluated **after** the code is executed, rather than before 
* The means code within a `do..while` loop is executed one to many times

```c
int count = 10;
do {
    // code block executed while the condition is true
    printf("The count is now %d\n", count);   
    count--;
} while ( count > 0 ); // condition expression, evaluated at the end of each iteration
```

---

## The 'for' statement
* The `for` statement provides a concise mechanism for implements loops, and includes a control variable as part of the syntax 
* These are often used as alternatives to while loops, and are more compact in most instances
* A `for` statement includes three (optional) expressions, called an init-expression; condition-expression; and a loop-expression
  * The **init-expression** is executed (once) prior to the loop being entered
  * The **condition-expression** is evaluated to determine if the loop should continue
  * The **loop-expression** is executed once the code within the loop has executed

---

## The 'for' statement syntax
The following is an equivalent to the two previous examples:
```c
//  [init]        [condition]  [loop]
for(int count = 10; count > 0; count-- ) {   
    // code block executed within the loop, the 'count' variable only exists within the loop
    printf("The count is now %d\n", count);
}
```

The following would implement an infinite loop, which never finishes:
```c
for(int count = 10; count > 0; count++ ) { 
    printf("I am stuck within an infinite loop!\n");
}
```


## Summary
* C provides `if`, `switch` and the ternary operator to allow us to implement selection (conditional behaviour) within code
* The `while`, `do…while` and `for` statements allow us to implement iteration in the forms of loops
