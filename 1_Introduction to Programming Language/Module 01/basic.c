/*
Mutli-line comment
author: Shammunul Islam
date: 10-01-2022
code: nothing interesting
*/

// single-line comment
// author: Shammunul Islam

// The below part is called preprocessor directives
// or linking section
#include <stdio.h>
// standard input output library
# include<math.h>
// math library
// we can also include our own libraries

// Definition section
// we can define values or declare macros here
#define pi 3.14
// define long long as ll so that we can use long long using ll
#define long long ll

// Global declaration section
// global variable
int N = 100;
// define function
int sum(int x, int y);

// main function section
int main(){
    
    return 0;
}

// Sub program section
// function definition
int sum(int x, int y){
    return x + y;
}