#include "stdio.h"
#include "Graph.h"

int main() {
    int VertexNum = 0;
    char line[100];

    printf("Enter the number of vertices: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &VertexNum);

    Graph g = newGraph(VertexNum);

    for (int i = 0; i < VertexNum; i++) {
        int fromVertex, toVertex;

        printf("Enter an edge (from): ");
        fgets(line, sizeof(line), stdin);
        if (sscanf(line, "%d", &fromVertex) != 1) {
            break;
        }

        printf("Enter an edge (to): ");
        fgets(line, sizeof(line), stdin);
        if (sscanf(line, "%d", &toVertex) != 1) {
            break;
        }

        insertEdge(g, [fromVertex, toVertex]);
        
    }


    printf("Done\n");
    return 0;
}