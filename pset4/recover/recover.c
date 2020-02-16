#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover file_to_be_recovered\n");
        return 1;
    }

    FILE *infile = fopen(argv[1], "r");

    if (infile == NULL)
    {
        fprintf(stderr, "Could not open it.\n");
        return 2;
    }

    int count = 0;
    char filename[8];

    unsigned char buffer[512];

    FILE *outfile = NULL;

    while (fread(&buffer, 512, 1, infile))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (outfile != NULL)
            {
                fclose(outfile);
            }

            sprintf(filename, "%03i.jpg", count++);
            printf("%s\n", filename);
            outfile = fopen(filename, "w");
            fwrite(&buffer, 512, 1, outfile);
        }
        else if (outfile != NULL)
        {
            fwrite(&buffer, 512, 1, outfile);
        }
    }

    fclose(infile);
    fclose(outfile);
    return 0;
}
