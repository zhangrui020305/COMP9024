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

void has3Clique(Graph g)
{
    int nV = numOfVertices(g);

    for (int u = 0; u < nV; u++)
    {
        for (int v = u + 1; v < nV; v++)
        {
            if (!adjacent(g, u, v))
                continue;
            for (int w = v + 1; w < nV; w++)
            {
                if (adjacent(g, v, w) && adjacent(g, u, w))
                {
                    printf("3-clique found: {%d, %d, %d}\n", u, v, w);
                }
            }
        }
    }
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

    // showGraph(g);

    for (int i = 0; i < numOfVertices(g); i++)
    {
        printf("Degree of node %d: %d\n", i, countDegree(g, i));
    }
    has3Clique(g);
    return 0;
}