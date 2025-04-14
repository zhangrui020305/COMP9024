#include "Graph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    TransportGraph graph;
    initGraph(&graph);

    int numOfLandmarks = 0;
    printf("Number of landmarks: ");
    scanf("%d", &numOfLandmarks);
    for (int i = 0; i < numOfLandmarks; i++)
    {
        char name[MAX_NAME_LEN];
        scanf("%s", name);
        addLandmark(&graph, name);
    }

    int numOfWalkingLinks = 0;
    printf("Number of walking links: ");
    scanf("%d", &numOfWalkingLinks);
    for (int i = 0; i < numOfWalkingLinks; i++)
    {
        char fromName[MAX_NAME_LEN];
        char toName[MAX_NAME_LEN];
        int duration = 0;
        scanf("%s", fromName);
        scanf("%s", toName);
        scanf("%d", &duration);
        addWalkingLink(&graph, fromName, toName, duration);
    }

    int numOfFerry = 0;
    printf("Number of ferry schedules: ");
    scanf("%d", &numOfFerry);
    for (int i = 0; i < numOfFerry; i++)
    {
        char fromName[MAX_NAME_LEN];
        char toName[MAX_NAME_LEN];
        int depart = 0;
        int arrive = 0;
        scanf("%s", fromName);
        scanf("%d", &depart);
        scanf("%s", toName);
        scanf("%d", &arrive);
        addFerrySchedule(&graph, fromName, toName, depart, arrive);
    }

    while (1)
    {
        char from[MAX_NAME_LEN], to[MAX_NAME_LEN];
        int departTime;

        printf("\nFrom: ");
        scanf("%s", from);
        if (strcmp(from, "done") == 0)
        {
            printf("Happy travels!\n");
            break;
        }

        printf("To: ");
        scanf("%s", to);
        printf("Departure time: ");
        scanf("%d", &departTime);

        findDirectPath(&graph, from, to, departTime);
    }
    return 0;
}