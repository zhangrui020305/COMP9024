#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALPHABET_LENGTH 128
#define MAX_PATTERN_LENGTH 128
#define MAX_TEXT_LENGTH 1024
#define TEXT_FORMAT_STRING "%[^\n]%*c"

int *lastOccurrence(char *pattern, char *alphabet)
{
    int m = strlen(pattern);
    int *last = (int *)malloc(MAX_ALPHABET_LENGTH * sizeof(int));

    if (last == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_ALPHABET_LENGTH; i++)
    {
        last[i] = -1;
    }

    for (int i = 0; i < m; i++)
    {
        last[(int)pattern[i]] = i;
    }

    return last;
}

int boyerMoore(char *text, char *pattern, int *last)
{
    int n = strlen(text);
    int m = strlen(pattern);

    int i = m - 1;

    while (i < n)
    {
        int j = m - 1;
        int k = i;

        while (j >= 0 && text[k] == pattern[j])
        {
            k--;
            j--;
        }

        if (j < 0)
        {
            return k + 1;
        }
        else
        {
            int l = last[(int)text[k]];
            int shift = (j - l > 1) ? j - l : 1;
            i += shift;
        }
    }

    return -1;
}

int main()
{
    char alphabet[MAX_ALPHABET_LENGTH];
    char text[MAX_TEXT_LENGTH];
    char pattern[MAX_PATTERN_LENGTH];

    printf("Enter alphabet: ");
    scanf(TEXT_FORMAT_STRING, alphabet);

    printf("Enter text: ");
    scanf(TEXT_FORMAT_STRING, text);

    printf("Enter pattern: ");
    scanf(TEXT_FORMAT_STRING, pattern);

    int *last = lastOccurrence(pattern, alphabet);

    printf("\n");
    for (int i = 0; i < strlen(alphabet); i++)
    {
        printf("L[%c] = %d\n", alphabet[i], last[(int)alphabet[i]]);
    }
    int pos = boyerMoore(text, pattern, last);

    if (pos == -1)
    {
        printf("\n");
        printf("No match.\n");
    }
    else
    {
        printf("\n");
        printf("Match found at position %d.\n", pos);
    }

    free(last);
    return 0;
}
