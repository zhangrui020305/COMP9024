#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LANDMARKS 100
#define MAX_NAME_LEN 50

typedef struct WalkingLink
{
   char from[MAX_NAME_LEN];
   char to[MAX_NAME_LEN];
   int duration;
} WalkingLink;

typedef struct FerrySchedule
{
   char from[MAX_NAME_LEN];
   char to[MAX_NAME_LEN];
   int departTime;
   int arriveTime;
} FerrySchedule;

typedef struct Landmark
{
   char name[MAX_NAME_LEN];
} Landmark;

typedef struct TransportGraph
{
   Landmark landmarks[MAX_LANDMARKS];
   int numLandmarks;
   WalkingLink walkingLinks[MAX_LANDMARKS];
   int numWalkingLinks;
   FerrySchedule ferrySchedule[MAX_LANDMARKS];
   int numFerrySchedule;
} TransportGraph;

void initGraph(TransportGraph *graph);
void addLandmark(TransportGraph *graph, char *name);
void addWalkingLink(TransportGraph *graph, char *from, char *to, int duration);
void addFerrySchedule(TransportGraph *graph, char *from, char *to, int depart, int arrive);
void findDirectPath(TransportGraph *graph, char *from, char *to, int departTime);
