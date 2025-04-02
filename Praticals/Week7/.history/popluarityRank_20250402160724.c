#include "stdio.h"
#include "WGraph.h"

double popularityCalculator() {
    
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
}
