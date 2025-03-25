#include "stdio.h"
#include "Graph.h"

int main() {
    int VertexNum = 0;
    char line[100];

    printf("Enter the number of vertices: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &VertexNum);

    Graph g = newGraph(VertexNum);

    // for (int i = 0; i < VertexNum; i++) {
    //     int fromVertex, toVertex;

    //     printf("Enter an edge (from): ");
    //     fgets(line, sizeof(line), stdin);
    //     if (sscanf(line, "%d", &fromVertex) != 1) {
    //         break;
    //     }

    //     printf("Enter an edge (to): ");
    //     fgets(line, sizeof(line), stdin);
    //     if (sscanf(line, "%d", &toVertex) != 1) {
    //         break;
    //     }

    //     Edge e;
    //     e.v = fromVertex;
    //     e.w = toVertex;

    //     insertEdge(g, e);
        
    // }

    while (1)
    {
        /* code */
        Edge e;
        printf("Enter an edge (from): ");
        if(scanf("%d", &e.v) != 1) {
            break;
        }
        printf("Enter an edge (to): ");
        if(scanf("%d", &e.w) != 1) {
            break;
        }

        insertEdge(g, e);
    }
    
    printf("Done\n");

    showGraph(g);
    return 0;
}