# The first Python program, after a year of C and C++.
#
# This is the whole file. Compare it with the C version you have written many times:
#
#     #include <stdio.h>          <- Python has no #include here. print is always there.
#     int main(){                 <- Python has no main. The file itself is the program,
#                                    and the interpreter runs it from the first line to
#                                    the last, in order.
#         printf("Hello World\n");
#         return 0;               <- Python has no return 0. The script ends when the
#     }                              lines run out.
#
# Three more things that have quietly disappeared:
#   * No semicolons. The end of the line ends the statement.
#   * No braces and no types. Nothing here needs to be declared before it is used.
#   * No compiling. There is no gcc step and no .exe; you run the source file directly
#     with `python first.py` and the output appears at once. Python reads and executes,
#     which is why it is called an interpreted language.
#
# The one line below:
#   print   - a function that is built into the language, so no header is needed.
#   ( ... ) - the brackets are how you call it, and in Python 3 they are required.
#             `print "Hello World"` is old Python 2 syntax and is a SyntaxError now.
#   " ... " - a string. Single quotes work exactly the same: 'Hello World'.
#
# And one difference that is easy to miss: there is no \n in the text. printf prints
# exactly what you give it, so in C you had to add the newline yourself. Python's print
# adds a newline after every call, so two prints already give two lines.
print("Hello World")
