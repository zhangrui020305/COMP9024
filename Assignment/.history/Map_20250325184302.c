#include "Map.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/*
void initGraph(TransportGraph *graph);
void addLandmark(TransportGraph *graph, char *name);
void addWalkingLink(TransportGraph *graph, char *name);
void addFerrySchedule(TransportGraph *graph, char *from, char *to, int *depart, int *arrive);
void findPath(TransportGraph *graph, char *from, char *to, int *departTime);
*/

void initGraph(TransportGraph *graph) {
    graph -> numLandmarks = 0;
    graph -> numWalkingLinks = 0;
    graph -> numFerrySchedule = 0;
}

void addLandmark(TransportGraph *graph, char *name) {
    
}