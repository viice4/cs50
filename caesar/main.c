#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usege: ./caesar key\n");
        return 1;
    }

    else
    {
        for (int i = 0, n = strlen(argv[1]); i <= n; i++)
        {
            if (argv[1][i] <= '9' && argv[1][i] >= '0')
            {
                int k = atoi(argv[1]) % 26;

                string plt = get_string("plaintext: ");
                printf("ciphertext: ");

                for (int j = 0, m = strlen(plt); j <= m; j++)
                {
                    if (plt[j] >= 'a' && plt[j] <= 'z')
                    {
                        int ck1 = plt[j] + k;
                        if (ck1 <= 'z')
                        {
                            printf("%c", ck1);
                        }
                        else
                        {
                            printf("%c", ck1 - 26);
                        }
                    }

                    else if (plt[j] >= 'A' && plt[j] <= 'Z')
                    {
                        int ck2 = plt[j] + k;
                        if (ck2 <= 'Z')
                        {
                            printf("%c", ck2);
                        }
                        else
                        {
                            printf("%c", ck2 - 26);
                        }
                    }

                    else
                    {
                        printf("%c", plt[j]);
                    }
                }
                printf("\n");
                return 0;
            }

            else
            {
                printf("Usege: ./caesar key\n");
                return 1;
            }
        }
    }
}
