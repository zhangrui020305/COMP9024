// Starting code for Dijkstra's algorithm ... COMP9024 25T1

#include <stdio.h>
#include <stdbool.h>
#include "PQueue.h"

#define VERY_HIGH_VALUE 999999

int weight[MAX_NODES][MAX_NODES];

void dijkstraSSSP(Graph g, Vertex source)
{
    int dist[MAX_NODES];
    int pred[MAX_NODES];
    bool vSet[MAX_NODES]; // vSet[v] = true <=> v has not been processed
    int s;

    PQueueInit();
    int nV = numOfVertices(g);
    for (s = 0; s < nV; s++)
    {
        joinPQueue(s);
        dist[s] = VERY_HIGH_VALUE;
        pred[s] = -1;
        vSet[s] = true;
    }
    dist[source] = 0;

    /* NEEDS TO BE COMPLETED */
    while (!PQueueIsEmpty())
    {
        Vertex u = leavePQueue(dist);
        vSet[u] = false;

        for (Vertex v = 0; v < nV; v++)
        {
            if (adjacent(g, u, v) && vSet[v])
            {
                if (dist[u] + weight[u][v] < dist[v])
                {
                    dist[v] = dist[u] + weight[u][v];
                    pred[v] = u;
                }
            }
        }
    }

    for (int v = 0; v < nV; v++)
    {
        if (dist[v] == VERY_HIGH_VALUE)
        {
            printf("%d: no path\n", v);
        }
        else
        {
            printf("%d: distance = %d, shortest path: ", v, dist[v]);

            int path[MAX_NODES], len = 0;
            for (int x = v; x != -1; x = pred[x])
                path[len++] = x;

            for (int i = len - 1; i >= 0; i--)
            {
                printf("%d", path[i]);
                if (i > 0)
                    printf("-");
            }
            printf("\n");
        }
    }
}

void reverseEdge(Edge *e)
{
    Vertex temp = e->v;
    e->v = e->w;
    e->w = temp;
}

int main(void)
{
    Edge e;
    int n, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    Graph g = newGraph(n);

    printf("Enter the source node: ");
    scanf("%d", &source);
    printf("Enter an edge (from): ");
    while (scanf("%d", &e.v) == 1)
    {
        printf("Enter an edge (to): ");
        scanf("%d", &e.w);
        printf("Enter the weight: ");
        scanf("%d", &e.weight);
        insertEdge(g, e);

        weight[e.v][e.w] = e.weight;
        
        reverseEdge(&e); // ensure to add edge in both directions
        insertEdge(g, e);

        weight[e.v][e.w] = e.weight;

        printf("Enter an edge (from): ");
    }
    printf("Done.\n");

    dijkstraSSSP(g, source);
    freeGraph(g);
    return 0;
}
