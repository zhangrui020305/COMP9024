#include "Map.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*
void initGraph(TransportGraph *graph);
void addLandmark(TransportGraph *graph, char *name);
void addWalkingLink(TransportGraph *graph, char *from, char *to, char *duration);
void addFerrySchedule(TransportGraph *graph, char *from, char *to, int *depart, int *arrive);
void findDirectPath(TransportGraph *graph, char *from, char *to, int *departTime);
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
    strcpy(graph -> ferrySchedule[graph->numFerrySchedule].from, from);
    strcpy(graph -> ferrySchedule[graph->numFerrySchedule].to, to);
    graph->ferrySchedule[graph->numFerrySchedule].departTime = depart;
    graph->ferrySchedule[graph->numFerrySchedule].arriveTime = arrive;
    graph->numFerrySchedule++;
}

void findDirectPath(TransportGraph *graph, char *from, char *to, int *departTime) {
    printf("From: %s\n", from);
    printf("To: %s\n", to);
    printf("Departure time: %d\n", departTime);

    for (int i = 0; i < graph->numWalkingLinks; i++) {
        if (strcmp())
    }
}