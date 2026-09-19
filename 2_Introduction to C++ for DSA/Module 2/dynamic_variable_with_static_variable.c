/*
    This file holds no code - only this note. It was started to record the third answer
    to the question the last two files asked, and the code was never typed in.

    The question: a function makes a variable, a pointer outside the function remembers
    its address, the function returns. Is the address still worth anything?

      dynamic_variable_with_stack_variable.cpp - `int x = 10;` inside fun().
          x lives in fun's stack frame. The frame is released when fun returns, so the
          saved address points at dead memory and main printed garbage.

      dynamic_variable_with_dynamic_variable.cpp - `int *x = new int;` inside fun().
          The heap block is not tied to the frame, so main still reads 10. The cost is
          that someone must call delete, or the block leaks.

      this file - `static int x = 10;` inside fun().
          A static local is not built on the stack at all. It is created once, before
          main starts, and lives until the program ends; fun() returning does not touch
          it. So &x stays valid and main reads 10 - the heap result without new, and
          without any delete to remember.

    The price is that "once" is literal: there is a single copy of x shared by every call
    to fun(), so a counter written this way keeps counting across calls instead of
    starting over. And `static int x = 10;` runs its initialiser once, not on each call.
    Use a static local when one shared, long-lived value is what you want; use new when
    you need a fresh block per call.

    Because there is no code here, the site runs the small C program from the module notes
    in its place; it prints `Fun -> 10` and then `Main -> 10`.
*/
