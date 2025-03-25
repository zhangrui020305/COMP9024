#include <stdio.h>

#define MAX_LANDMARKS 100
#define MAX_NAME_LEN 50

typedef struct WalkingLink
{
    /* data */
    char from[MAX_NAME_LEN];
    char to[MAX_NAME_LEN];
    int duration;
} WalkingLink;

typedef struct FerrySchedule
{
    /* data */
    char from[MAX_NAME_LEN];
    char to[MAX_NAME_LEN];
    int departTime;
    int arriveTime;
} FerrySchedule;

typedef struct Landmark
{
    /* data */
    char name[MAX_NAME_LEN];
} Landmark;

typedef struct TransportGraph
{
    /* data */
    Landmark landmarks[MAX_LANDMARKS];
};



