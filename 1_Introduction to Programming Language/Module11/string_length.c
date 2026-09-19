/*
  Counting the length of a string by hand.

  A C string is nothing but a char array with one extra rule attached: the
  characters are followed by the null character '\0', which marks the end.
  So "abcd" is five chars in memory - 'a' 'b' 'c' 'd' '\0' - not four.

  That single rule is the whole reason the loop below can work. Nothing in C
  stores the length of a string anywhere; you find it out by walking from the
  start until you meet the '\0'.

  This file does that walk itself. Its partner, string_length_function.c,
  gets the same answer in one line with strlen from <string.h>. The pair is
  the same lesson told twice, and the point of the pair is this: strlen is
  not magic, strlen is this loop. Write the loop once so you know what you
  are buying, then use strlen everywhere afterwards.
*/

#include <stdio.h>

int main() {
    /* 10 slots reserved, 5 of them used: 'a' 'b' 'c' 'd' '\0'. The size of
       the array and the length of the string are two different numbers, and
       it is the second one the program has to work out. */
    char str[10] = "abcd";

    /* Nothing counted yet. */
    int length = 0;

    /* The condition is the whole idea: keep going while the current
       character is not the end marker. i visits 0, 1, 2 and 3; at i = 4 it
       finds '\0' and the loop stops, so the '\0' is never counted.
       Do not write `i < 10` here. The slots after the '\0' are not part of
       the string and hold whatever was in that memory before. */
    for(int i=0; str[i] != '\0'; i++){
        length++;
    }

    /* Prints 4 - the letters, not the array size 10. There is no "\n", so
       whatever is printed next lands on the same line. */
    printf("%d", length);

    return 0;
}
