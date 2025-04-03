#include "stdio.h"
#include "stdbool.h"
#include "WGraph.h"

typedef struct 
{
    /* data */
};

int inDegree(Graph g, int v)
{
    int count = 0;
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
    bool hasOutEdge = false;
    for (int i = 0; i < numOfVertices(g); i++)
    {
        if (adjacent(g, v, i))
        {
            count++;
            hasOutEdge = true;
        }
    }
    return hasOutEdge ? count : 0.5;
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
