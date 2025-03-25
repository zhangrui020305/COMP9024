#include "stdio.h"
#include "Graph.h"

int main(){
    int VertexNum = 0;


    printf("Enter the number of vertices" );
    scanf("%d", &VertexNum);

    Graph g = newGraph(VertexNum);
    
    for (int i = 0; i < VertexNum; i++) {
        int fromVertex;
        int toVertex;
        printf("Enter an edge (from): ");
        if (scanf("%d", &fromVertex) != 1) {
            break;
        }
        if (scanf("%d", &toVertex) != 1) {
            break;
        }
    }
    printf("Done");
    return 0;
}