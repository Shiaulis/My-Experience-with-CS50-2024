#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int is_jpeg(BYTE buffer[]);

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "rb");

    // Create a buffer for a block of data
    BYTE buffer[512];

    FILE *jpeg = NULL;
    char *filename = malloc(10);
    int files_counter = 0;

    // While there's still data left to read from the memory card
    while (fread(&buffer, 1, 512, card) == 512)
    {
        if (is_jpeg(buffer) == 0)
        {
            if (jpeg != NULL)
            {
                // close previous file
                fclose(jpeg);
            }

            // making new file
            sprintf(filename, "%03i.jpg", files_counter);
            jpeg = fopen(filename, "ab");
            files_counter++;
        }

        if (jpeg != NULL)
        {
            fwrite(&buffer, 1, 512, jpeg);
        }
    }

    free(filename);
    fclose(jpeg);
    fclose(card);
}

int is_jpeg(BYTE buffer[])
{
    if (buffer[0] != 0xff)
    {
        return 1;
    }

    if (buffer[1] != 0xd8)
    {
        return 1;
    }

    if (buffer[2] != 0xff)
    {
        return 1;
    }

    if (buffer[3] < 0xe0 || buffer[3] > 0xef)
    {
        return 1;
    }

    return 0;
}
