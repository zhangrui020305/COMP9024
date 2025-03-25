#include <stdio.h>

#define MAX_LANDMARKS 100
#define MAX_NAME_LEN 50

typedef struct WalkingLink
{
    char from[MAX_NAME_LEN];
    char to[MAX_NAME_LEN];
    int duration;
};
