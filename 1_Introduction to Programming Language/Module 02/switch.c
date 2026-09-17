#include <stdio.h>

int main() {
    char grade;
    int day;

    printf("Enter your grade (A, B, C, D, F): ");
    scanf("%c", &grade);

    switch(grade) {
        case 'A':
            printf("Excellent!\n");
            break;
        case 'B':
            printf("Well done!\n");
            break;
        case 'C':
            printf("Good!\n");
            break;
        case 'D':
            printf("Sufficient!\n");
            break;
        case 'F':
            printf("Failed!\n");
            break;
        default:
            printf("Invalid grade!\n");
    }

    printf("Enter your day (1-7): ");
    scanf("%d", &day);

    switch(day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Invalid day!\n");
    }
}