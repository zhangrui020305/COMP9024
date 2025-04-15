#include "Graph.h"
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

void initGraph(TransportGraph *graph)
{
   graph->numLandmarks = 0;
   graph->numWalkingLinks = 0;
   graph->numFerrySchedule = 0;
}

void addLandmark(TransportGraph *graph, char *name)
{
   strcpy(graph->landmarks[graph->numLandmarks].name, name);
   graph->numLandmarks++;
}

void addWalkingLink(TransportGraph *graph, char *from, char *to, int duration)
{
   strcpy(graph->walkingLinks[graph->numWalkingLinks].from, from);
   strcpy(graph->walkingLinks[graph->numWalkingLinks].to, to);
   graph->walkingLinks[graph->numWalkingLinks].duration = duration;
   graph->numWalkingLinks++;

   strcpy(graph->walkingLinks[graph->numWalkingLinks].from, to);
   strcpy(graph->walkingLinks[graph->numWalkingLinks].to, from);
   graph->walkingLinks[graph->numWalkingLinks].duration = duration;
   graph->numWalkingLinks++;
}

void addFerrySchedule(TransportGraph *graph, char *from, char *to, int depart, int arrive)
{
   strcpy(graph->ferrySchedule[graph->numFerrySchedule].from, from);
   strcpy(graph->ferrySchedule[graph->numFerrySchedule].to, to);
   graph->ferrySchedule[graph->numFerrySchedule].departTime = depart;
   graph->ferrySchedule[graph->numFerrySchedule].arriveTime = arrive;
   graph->numFerrySchedule++;
}

int getLandmarkIndex(TransportGraph *graph, const char *name)
{
   for (int i = 0; i < graph->numLandmarks; i++)
   {
      if (strcmp(graph->landmarks[i].name, name) == 0)
      {
         return i;
      }
   }
   return -1;
}

void dfsWalk(TransportGraph *graph, char *current, char *destination, int currentTime, int visited[], int *found)
{
   int currIdx = getLandmarkIndex(graph, current);
   visited[currIdx] = 1;

   if (strcmp(current, destination) == 0)
   {
      *found = 1;
      return;
   }

   for (int i = 0; i < graph->numWalkingLinks; i++)
   {
      if (strcmp(graph->walkingLinks[i].from, current) == 0)
      {
         int nextIdx = getLandmarkIndex(graph, graph->walkingLinks[i].to);
         if (!visited[nextIdx])
         {
            printf("Walk %d minute(s):\n", graph->walkingLinks[i].duration);
            printf("  %04d %s\n", currentTime, graph->walkingLinks[i].from);
            printf("  %04d %s\n", currentTime + graph->walkingLinks[i].duration, graph->walkingLinks[i].to);
            dfsWalk(graph, graph->walkingLinks[i].to, destination, currentTime + graph->walkingLinks[i].duration, visited, found);
            if (*found)
               return;
         }
      }
   }
}

void findDirectPath(TransportGraph *graph, char *from, char *to, int departTime)
{
    int visited[MAX_LANDMARKS] = {0};
    int found = 0;

    int fromIdx = getLandmarkIndex(graph, from);
    int toIdx = getLandmarkIndex(graph, to);
    if (fromIdx == -1 || toIdx == -1) {
        printf("No route.\n");
        return;
    }

    dfsWalk(graph, from, to, departTime, visited, &found);
    if (!found) {
        for (int i = 0; i < graph->numFerrySchedule; i++) {
            if (strcmp(graph->ferrySchedule[i].from, from) == 0 &&
                strcmp(graph->ferrySchedule[i].to, to) == 0 &&
                graph->ferrySchedule[i].departTime >= departTime) {
                printf("Ferry %d minute(s)\n", graph->ferrySchedule[i].arriveTime - graph->ferrySchedule[i].departTime);
                printf("  %04d %s\n", graph->ferrySchedule[i].departTime, graph->ferrySchedule[i].from);
                printf("  %04d %s\n", graph->ferrySchedule[i].arriveTime, graph->ferrySchedule[i].to);
                return;
            }
        }
        printf("No route.\n");
    }
}