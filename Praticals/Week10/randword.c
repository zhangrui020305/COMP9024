#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <word_length> <seed>\n", argv[0]);
        return 1;
    }

    int length = atoi(argv[1]);
    int seed = atoi(argv[2]);

    if (length <= 0)
    {
        printf("Word length must be positive.\n");
        return 1;
    }

    srand(seed);

    for (int i = 0; i < length; i++)
    {
        char letter = 'a' + (rand() % 26);
        printf("%c", letter);
    }
    printf("\n");

    return 0;
}
