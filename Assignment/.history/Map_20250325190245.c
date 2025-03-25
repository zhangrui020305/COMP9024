#include "Map.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/*
void initGraph(TransportGraph *graph);
void addLandmark(TransportGraph *graph, char *name);
void addWalkingLink(TransportGraph *graph, char *from, char *to, char *duration);
void addFerrySchedule(TransportGraph *graph, char *from, char *to, int *depart, int *arrive);
void findPath(TransportGraph *graph, char *from, char *to, int *departTime);
*/

void initGraph(TransportGraph *graph) {
    graph -> numLandmarks = 0;
    graph -> numWalkingLinks = 0;
    graph -> numFerrySchedule = 0;
}

void addLandmark(TransportGraph *graph, char *name) {
    strcpy(graph -> landmarks[graph->numLandmarks].name, name);
    graph->numLandmarks++;
}

void addWalkingLink(TransportGraph *graph, char *from, char *to, char *duration) {
    strcpy(graph -> walkingLinks[graph->numWalkingLinks].from, from);
    strcpy(graph -> walkingLinks[graph->numWalkingLinks].to, to);
    graph->walkingLinks[graph->numWalkingLinks].duration = duration;
    graph->numWalkingLinks++;
}

void addFerrySchedule(TransportGraph *graph, char *from, char *to, int *depart, int *arrive) {
    strcpy(graph -> )
}