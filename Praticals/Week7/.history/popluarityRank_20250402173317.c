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
    printf("inDegree of %d: %d\n", v, count);
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
    printf("inDegree of %d: %d\n", v, count);
    return count;
}

double popularityCalculator(Graph g, int v)
{
    //  popularityRank(v) = inDegree(v) / outDegree(v)
    double popularity = (double)inDegree(g, v) / (double)outDegree(g, v);
    printf("popularity of %d: %f \n", v, popularity);
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
            printf("Edge inserted from %d to %d\n", e.v, e.w);
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
