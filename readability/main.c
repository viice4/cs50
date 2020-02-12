#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");

    int lt = 0, n = strlen(text);

    for (int i = 0; i <= n; i++)
    {
        if (text[i] >= 'a' - 32 && text[i] <= 'z')
        {
            lt++;
        }
    }

    int wd = 0;
    for (int j = 0; j <= n; j++)
    {
        if ((text[j] < 'a' - 32 || text[j] > 'z') && (text[j+1] >= 'a' - 32 && text[j+1] <= 'z') && text[j] != '\'')
        {
            wd++;
        }
    }

    int stc = 0;
    for (int k = 0; k <= n; k++)
    {
        if (text[k] == '.' || text[k] == '?' || text[k] == '!')
        {
            stc++;
        }
    }


    double index;
    index = 0.0588 * lt * 100 / wd - 0.296 * stc * 100 / wd - 15.8;

    int index0 = round(index);

    if (index0 >= 1 && index0 <= 16)
    {
        printf("Grade %i\n", index0);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index0 > 16)
    {
        printf("Grade 16+\n");
    }
}
