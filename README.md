# ICP Example Code

Try the examples in this repo in the debugger.

When you try and examine the console you may not see the output.

In this case you need to flush the buffer with `fflush(stdout);` placed after each printf.

Set breakpoints in the debugger. Then click the bug sysmbol. Execution will stop on the breakpoint.

Use step over to execute a line.

Use step into to follow execution into a function call.




## Course Notes and References

This repository includes detailed Markdown guides for various C programming topics, located alongside their respective code examples.

* **[Control Flow and Iteration](Selection_and_Iteration_Examples/control_flow.md)**  
  A guide to program logic and branching. Details selection statements (`if`, `else`, `switch`, ternary operator) and loops (`while`, `do...while`, `for`) for repeating code blocks.

* **[Functions and Scope](Function_Examples/functions.md)**  
  Covers the basics of modular programming. Includes how to declare, define, and call functions, pass parameters, return values, and manage variable scope (local vs. global memory).

* **[Arrays and Pointers](ArraysAndPointers/arrays_and_pointers.md)**  
  Explores fixed-size collections and direct memory access in C. Topics include array indexing, multi-dimensional arrays, pointer operators (`&`, `*`, `->`), pointer arithmetic, and the relationship between arrays and pointers.

# Top Tips
- ifs/whiles/fors do not have a single = for equality checking, it must be == e.g if(a==b) and not if (a=b)
- ifs/whiles/fors do not have a ; on the end (the excption is a do..while(); which does because the while is at the end.
- if/whiles/for you have && and || and not & and |
- ifs/whiles/fors you have put && when you means AND and || when you mean OR, it is a common mistake to just put the wrong one, double check your thinking.

## Note
MakeLists.txt is provided in case you mess the one in your repo up.
