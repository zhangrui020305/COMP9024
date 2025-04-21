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

void dfs(TransportGraph *graph, char *current, char *destination, int currentTime,
         int visited[MAX_LANDMARKS], int *found)
{
   if (*found)
   {
      return;
   }

   if (strcmp(current, destination) == 0)
   {
      *found = 1;
      return;
   }

   visited[getLandmarkIndex(graph, current)] = 1;

   // Try to walk
   for (int i = 0; i < graph->numWalkingLinks; i++)
   {
      // if from == current and place never visited before
      if (strcmp(graph->walkingLinks[i].from, current) == 0 && !visited[getLandmarkIndex(graph, graph->walkingLinks[i].to)])
      {
         // update time
         int nextTime = currentTime + graph->walkingLinks[i].duration;
         printf("Walk %d minute(s):\n", graph->walkingLinks[i].duration);
         printf("  %04d %s\n", currentTime, current);
         printf("  %04d %s\n", nextTime, graph->walkingLinks[i].to);

         dfs(graph, graph->walkingLinks[i].to, destination, nextTime, visited, found);

         // if find a path return
         if (*found)
            return;
      }
   }

   // Try to take ferry
   for (int i = 0; i < graph->numFerrySchedule; i++)
   {
      if (strcmp(graph->ferrySchedule[i].from, current) == 0 && graph->ferrySchedule[i].departTime >= currentTime && !visited[getLandmarkIndex(graph, graph->ferrySchedule[i].to)])
      {
         int depart = graph->ferrySchedule[i].departTime;
         int arrive = graph->ferrySchedule[i].arriveTime;

         printf("Ferry %d minute(s):\n", arrive - depart);
         printf("  %04d %s\n", depart, graph->ferrySchedule[i].from);
         printf("  %04d %s\n", arrive, graph->ferrySchedule[i].to);

         dfs(graph, graph->ferrySchedule[i].to, destination, arrive, visited, found);

         if (*found)
            return;
      }
   }

   visited[getLandmarkIndex(graph, current)] = 0;
}

void findDirectPath(TransportGraph *graph, char *from, char *to, int departTime)
{
   int visited[MAX_LANDMARKS] = {0};
   int found = 0;
   dfs(graph, from, to, departTime, visited, &found);

   if (!found)
   {
      printf("No route.\n");
   }
}
