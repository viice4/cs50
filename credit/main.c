#include <stdio.h>
#include <cs50.h>

int main()
{
    long long number  = get_long_long("Number: ");

    int dig1 = 0, dig2 = 0, sum1 = 0, sum2 = 0, cts = 1;

    while (number > 0)
    {
        dig2 = dig1;
        dig1 = number % 10;
        if (cts % 2 != 0)
        {
            sum1 += dig1;
        }
        else
        {
            int multi = dig1 * 2;
            sum2 += (multi / 10) + (multi % 10);
        }
        number = number / 10;
        cts++;
    }
    bool if_valid = (sum1 + sum2) % 10 == 0;
    int fst_two = (dig1 * 10) + dig2;

    if (cts == 15 && (fst_two == 34 || fst_two == 37) && if_valid)
    {
        printf("AMEX\n");
    }
    else if (cts == 16 && fst_two >= 51 && fst_two <= 55 && if_valid)
    {
        printf("MASTERCARD\n");
    }
    else if (cts>= 13 && cts <= 16 && dig1 == 4 && if_valid)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
