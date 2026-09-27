/*

R. Age in Days

Given a person's age in days, print that age as years, months and days.
Count 365 days in a year and 30 days in a month, and ignore anything finer
than that.

Input
One line containing a number N (1 <= N <= 10^6), the age in days.

Output
Three lines:
  <years> years
  <months> months
  <days> days

Example

input
400

output
1 years
1 months
5 days

Note
400 days is one full year (365 days) with 35 days left over. Those 35 days
make one month of 30 days, and 5 days remain.

*/

/* stdio.h ("standard input output") declares scanf and printf. The
   space in "# include" is allowed; it means the same as #include. */
# include <stdio.h>

int main() {            /* the program starts running here */
    int n;              /* the input number N */
    scanf("%d", &n);    /* %d = read a whole number; &n = where to put it */

    /* Whole years first: integer division throws the fraction away, which is
       exactly what "how many complete years" means. */
    int years = n / 365;

    /* What is left after taking the years out. */
    int rest = n % 365;

    int months = rest / 30;     /* complete 30-day months in the rest */
    int days = rest % 30;       /* what is left after those months */
    /* Trace 400: years = 400 / 365 = 1, rest = 400 % 365 = 35,
       months = 35 / 30 = 1, days = 35 % 30 = 5. */

    /* Each %d is replaced by the value after the comma; \n ends the line. */
    printf("%d years\n", years);
    printf("%d months\n", months);
    printf("%d days\n", days);

    return 0;   /* 0 = the program finished normally */
}
