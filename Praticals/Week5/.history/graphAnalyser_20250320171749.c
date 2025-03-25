#include "stdio.h"
#include "Graph.h"

int main(){
    int VertexNum = 0;


    printf("Enter the number of vertices: " );
    scanf("%d", &VertexNum);
    getchar();

    // Graph g = newGraph(VertexNum);
    
    for (int i = 0; i < VertexNum; i++) {
        int fromVertex;
        int toVertex;
        printf("Enter an edge (from): ");
        if (scanf("%d", &fromVertex) != 1) {
            break;
        }
        getchar();
        if (scanf("%d", &toVertex) != 1) {
            break;
        }
        getchar();
    }
    printf("Done\n");
    return 0;
}