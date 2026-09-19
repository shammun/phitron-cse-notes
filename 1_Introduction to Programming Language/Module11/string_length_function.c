/*
  The same length, this time with strlen.

  string_length.c counted the characters with its own loop, stopping at the
  '\0'. strlen does exactly that walk for you, so the loop, the counter and
  the '\0' test all collapse into one call. That is the whole contrast
  between the two files: by hand, then with the library. The answer is the
  same and the work is the same; only the typing is shorter.

  The string here is "abcd ab?" rather than "abcd" to make a second point.
  strlen counts characters, not letters: the space counts and the '?' counts.
  The answer is 8.
*/

#include <stdio.h>
#include <string.h>
/* strlen lives in <string.h>, together with strcpy, strcat and strcmp. */

int main() {
    /* 8 characters plus the '\0' is 9 of the 10 slots. The longest string
       that fits in `char str[10]` is 9 characters long, because one slot
       always belongs to the end marker. */
    char str[10] = "abcd ab?";

    /* strlen walks from str[0] to the first '\0' and reports how many
       characters it passed: 8 here. Not 10, which is the array size, and not
       6, which would be the count if only letters were counted.
       The trap: strlen stops at the FIRST '\0'. If one ever sits in the
       middle of the array - "hi\0there" - strlen answers 2 and everything
       after it is invisible to every other string function too.
       strlen hands back a size_t, an unsigned count; storing it in an int is
       fine for short strings like this one. */
    int length = strlen(str);
    printf("%d", length);

    return 0;
}