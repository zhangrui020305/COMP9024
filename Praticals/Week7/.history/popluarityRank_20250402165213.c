#include "stdio.h"
#include "WGraph.h"

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

int outDegree(Graph g, int v)
{
    int count = 0;
    for (int i = 0; i < numOfVertices(g); i++)
    {
        if (adjacent(g, v, i))
        {
            count++;
        }
    }
    return count;
}

double popularityCalculator(Graph g, int v)
{
    //  popularityRank(v) = inDegree(v) / outDegree(v)
    double popularity = inDegree(g, v) / outDegree(g, v);
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
            insertEdge(g, e);
        }
    }

    printf("Done.\n");

    for (int i = 0; i < numOfVertices(g); i++)
    {
        /* code */
        printf("%f\n", popularityCalculator(g, i));
    }
    return 0;
}
