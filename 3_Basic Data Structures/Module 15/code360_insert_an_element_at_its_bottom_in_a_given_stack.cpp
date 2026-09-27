/*

Insert An Element At Its Bottom In A Given Stack (Code360)
https://www.naukri.com/code360/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166

The problem, in my own words
  You get a stack and a number x. Put x at the very BOTTOM of the stack,
  under everything that is already there, and return the stack. The other
  values must stay in their original order.

Function to write (Code360 signature)
  stack<int> pushAtBottom(stack<int>& myStack, int x)

Input used by the test driver
  first line t (test cases); each case: n and x, then the n values of the
  stack from bottom to top.

Sample
  n = 4, x = 9, stack (bottom -> top) 7 1 4 5   ->   9 7 1 4 5
  n = 1, x = 2, stack 8                         ->   2 8

*/

/*
 * The idea: a stack only lets you touch the top, so to reach the bottom you
 * have to lift everything off first - and keep it somewhere so you can put
 * it back in the same order.
 *
 * A second stack is the perfect "somewhere":
 *   1. pop every value from myStack and push it on `helper`
 *      (helper now holds them upside down),
 *   2. myStack is empty, so pushing x now puts it at the bottom,
 *   3. pop everything from helper back onto myStack. Reversing twice gives
 *      the original order again, now sitting on top of x.
 */

stack<int> pushAtBottom(stack<int>& myStack, int x)
{
    stack<int> helper;   // holds the values while we dig down to the bottom

    // Step 1: empty myStack into helper. The old top goes in first, so it
    // ends up at the bottom of helper.
    while(!myStack.empty()){
        helper.push(myStack.top());
        myStack.pop();
    }

    // Step 2: myStack is empty, so x becomes its bottom.
    myStack.push(x);

    // Step 3: pour helper back. The old bottom comes out of helper first
    // and lands right on top of x, so the order is restored.
    while(!helper.empty()){
        myStack.push(helper.top());
        helper.pop();
    }

    return myStack;
}
