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

# include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    /* Whole years first: integer division throws the fraction away, which is
       exactly what "how many complete years" means. */
    int years = n / 365;

    /* What is left after taking the years out. */
    int rest = n % 365;

    int months = rest / 30;
    int days = rest % 30;

    printf("%d years\n", years);
    printf("%d months\n", months);
    printf("%d days\n", days);

    return 0;
}
