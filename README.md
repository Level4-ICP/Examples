# ICP Example Code
CMakeLists.txt is provided in case you mess the one in your repo up.

Try the examples in the debugger, but when you try and examine the console you may not see the output. In this case you need to flush the buffer with fflush(stdout); placed after each printf

# Top Tips
- ifs/whiles/fors do not have a single = for equality checking, it must be == e.g if(a==b) and not if (a=b)
- ifs/whiles/fors do not have a ; on the end (the excption is a do..while(); which does because the while is at the end.
- if/whiles/for you have && and || and not & and |
- ifs/whiles/fors you have put && when you means AND and || when you mean OR, it is a common mistake to just put the wrong one, double check your thinking.
