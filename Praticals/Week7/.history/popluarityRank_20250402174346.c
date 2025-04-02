#include "stdio.h"
#include "WGraph.h"

double inDegree(Graph g, int v)
{
    double count = 0;
    for (int i = 0; i < numOfVertices(g); i++)
    {
        if (adjacent(g, i, v))
        {
            count++;
        }
    }
    return count;
}

double outDegree(Graph g, int v)
{
    double count = 0;
    for (int i = 0; i < numOfVertices(g); i++)
    {
        if (adjacent(g, v, i))
        {
            count++;
        }
        else
        {
            count = 0.5;
        }
    }
    return count;
}

double popularityCalculator(Graph g, int v)
{
    //  popularityRank(v) = inDegree(v) / outDegree(v)
    double popularity = (double)inDegree(g, v) / (double)outDegree(g, v);
    return popularity;
}

int main()
{
    int VertexNum = 0;
    char line[100];
    int edgeCnt = 0;

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

        if (!adjacent(g, e.v, e.w))
        {
            edgeCnt++;
            e.weight = 1;
            insertEdge(g, e);
        }
    }

    printf("Done.\n");

    printf("Popularity :\n");
    for (int i = 0; i < numOfVertices(g); i++)
    {
        /* code */
        printf("%d %.1f\n", i, popularityCalculator(g, i));
    }
    return 0;
}
