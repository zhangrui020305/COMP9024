#include "stdio.h"
#include "Graph.h"

int countDegree(Graph g, Vertex v)
{
    int deg = 0;

    for (int i = 0; i < numOfVertices(g); i++)
    {
        if (adjacent(g, v, i))
        {
            deg++;
        }
    }
    return deg;
}

int main()
{
    int VertexNum = 0;
    char line[100];

    printf("Enter the number of vertices: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &VertexNum);

    Graph g = newGraph(VertexNum);

    while (1)
    {
        /* code */
        Edge e;
        printf("Enter an edge (from): ");
        if (scanf("%d", &e.v) != 1)
        {
            break;
        }
        printf("Enter an edge (to): ");
        if (scanf("%d", &e.w) != 1)
        {
            break;
        }

        insertEdge(g, e);
    }

    printf("Done\n");

    showGraph(g);

    for (int i = 0; i < numOfVertices(g); i++) {
        printf("Degree of node %d: %d\n", i, countDegree(g, i));
    }
    return 0;
}