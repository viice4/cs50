#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int cents = 0;
    do
    {
        float dollars = get_float("change owned: ");
        cents = round(dollars * 100);
    }
    while (cents <= 0);

    int q, d, n, p;

    q = cents / 25;
    d = (cents % 25) / 10;
    n = ((cents % 25) % 10) / 5;
    p = ((cents % 25) % 10) % 5;

    int sum = q + d + n + p;

    printf("%i\n", sum);
}
