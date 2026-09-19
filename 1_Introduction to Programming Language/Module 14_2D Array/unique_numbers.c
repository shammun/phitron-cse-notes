/*
  How many different values does the array hold?

  This is the frequency array again, in its simplest form. The idea from
  Module 13 was: keep one box per possible value, and use the value itself as
  the index, so `freq[v]` is where everything about v is recorded. Here we do
  not even need a count - a yes/no is enough:

      freq[v] == 0   ->  v has not been seen before: count it, mark the box
      freq[v] == 1   ->  v has already been counted: skip it

  Using the value as the index is what makes this fast. There is no searching
  and no comparing of elements with each other; one direct look-up per
  element settles it, so the whole job is a single pass over the array.

  unique_characters.c did the same thing for letters, where the index was
  str[i] - 'a'. Here the numbers are already small enough to be indexes
  themselves, so no conversion is needed.
*/

#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    /* One box per possible value, 0 to 100000, which matches the task's
       limit A[i] <= 10^5. Note what decides the size: the LARGEST value the
       input may contain, not n. A thousand numbers still need a hundred
       thousand boxes if that is how far the values can reach.
       `= {0}` fills every box with 0. Without it the boxes would hold
       leftover rubbish and the "is it still 0?" test below would be
       meaningless.
       The limits of the trick: a negative value, or one above 100000, would
       index outside this array. A frequency array only works when the values
       are small whole numbers with a known range. */
    int freq[100001] = {0};
    /* The answer, built up as the second loop goes along. */
    int unique_count = 0;

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    /* The counting pass. The first time a value turns up its box is still 0:
       mark it with 1 and add one to the answer. Every later copy of that
       value finds the 1 already there and changes nothing, so each distinct
       value is counted exactly once, however often it appears. */
    for(int i=0; i<n; i++){
        if(freq[arr[i]] == 0){
            freq[arr[i]] = 1;
            unique_count++;
        }
    }

    /* No "\n" after the number. */
    printf("%d", unique_count);

    return 0;

}