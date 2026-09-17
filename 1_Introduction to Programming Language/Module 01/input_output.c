#include <stdio.h>

int main() {

    int a, b, c;
    short int e = -32;
    short int d;
    char ch;

    float f;
    double g;

    scanf("%d %d %d %hd", &a, &b, &c, &d);
    scanf("\n%c", &ch);
    scanf("\n%.2f", &f); // print 2 decimal places
    scanf("%lf", &g);
    printf("a = %d, b = %d, c = %d, d = %hd, ch = %c\n, f = %f, g = %lf", a, b, c, d, ch, f, g);
    printf("\nd = %hd, c = %d, a = %d, b = %d, e = %hd", d, c, a, b, e);
    
    /* 
    
    int a = 10;
    printf("%04d", a); // 00010
    
    long long int num;
    scanf("%lld", &num);
    printf("%lld", num);


    */
    
    return 0;
}

/*

Format specifier

%d - int
%hd - short int
%ld - long int
%lld - long long int
%d - integer
%lf - double
%Lf - long double 
%c - char
%f - float

%u - unsigned int
%hu - unsigned short int
%lu - unsigned long int
%llu - unsigned long long int


%s - string
%c - character
%lf - long float
%Lf - long double
%Lf - long long
%p - pointer
%x - hexadecimal
%o - octal
%e - exponential
%g - general
%u - unsigned integer
%n - number of characters written so far
%i - integer
%f - float


 */