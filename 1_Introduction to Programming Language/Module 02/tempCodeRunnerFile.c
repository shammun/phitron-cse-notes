
    else if(marks >= 70)

/* ---------------------------------------------------------------------
 * The comments have to go BELOW the fragment, not above it, so that the
 * compiler still reports the error on line 2 exactly as the notes show.
 *
 * This file is not a lesson and not a program. VS Code's Code Runner
 * creates a file called tempCodeRunnerFile.c whenever you run a
 * SELECTION instead of a whole file: it copies the highlighted text into
 * this scratch file and compiles that instead. Someone highlighted one
 * line of marks.c, pressed Run, and this is what was left behind.
 *
 * It cannot compile, and the error is worth reading once:
 *
 *     error: expected identifier or '(' before 'else'
 *
 * At the top level of a file C expects the start of something it can
 * declare - a type, a function, a variable. An else is not such a thing.
 * It is the tail of an if statement and means nothing on its own, in the
 * same way that a sentence beginning "otherwise..." means nothing with
 * no sentence before it. It would only be legal inside a function body,
 * directly after an if.
 *
 * Nothing depends on this file. You can delete it, and adding a line
 *     tempCodeRunnerFile.*
 * to your .gitignore keeps the next one from being committed.
 * ------------------------------------------------------------------- */
