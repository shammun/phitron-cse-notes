/*
Add up an array using recursion.

The recursions earlier in this module printed as they went and returned
nothing. This one hands a value back, and that is the new idea: the sum of
the array from index i onwards is a[i] plus the sum of the array from i+1
onwards. The smaller answer comes back out of the recursive call, and this
call adds its own element to it.

    getSum(0, 5) = a[0] + getSum(1, 5)
                 = a[0] + (a[1] + getSum(2, 5))
                 = 1 + (2 + (3 + (4 + (5 + 0)))) = 15

The base case is i == n, one step past the last element: there is nothing
left to add, and the sum of no numbers is 0. That 0 is what the whole chain
is built on.

Notice that each addition happens only after its recursive call has
returned, so the adding really runs from the back of the array forwards -
the same "work after the call" shape as recursion_print_N_to_1.c.

This file also brings in the other new thing of the module, the array: a
list of values under one name, where a[i] picks out the one at position i,
counting from 0.
*/

#include <stdio.h>

/* The array is declared outside main, which makes it global: getSum can read
   it without being handed it. A global array is also zero-filled to start
   with, and it lives outside the small stack area, which is why 100000 boxes
   are safe here when the same declaration inside main might not be. */
int a[100000];

/*
Function name: getSum
Parameters:
    - i: the index this call starts from
    - n: the number of elements, so n-1 is the last valid index
Return value: the sum of a[i], a[i+1], ... , a[n-1]
*/
int getSum(int i, int n){
    // Base case: i has reached n, one past the last element, so nothing is
    // left to add. Note it is i == n, not i == n-1: the element at n-1 still
    // has to be counted.
    if(i == n){
        return 0;
    }
    // This element, plus whatever the rest of the array adds up to. The
    // addition cannot happen until the inner call comes back with its
    // number, so every call is parked holding its own a[i].
    return a[i] + getSum(i+1, n);
}

int main(){
    int n;
    scanf("%d", &n);

    // Fill the array: one pass of the loop, one box. scanf is given &a[i],
    // the address of the box, exactly as it is given &n for a plain variable.
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    // Start at index 0, which means "sum the whole array".
    // total_sum is an int, and so is the return type of getSum. That is fine
    // for small values; with large ones the total would overflow and both
    // would have to become long long.
    int total_sum = getSum(0, n);
    printf("%d\n", total_sum);

    return 0;
}