#include "stdio.h"
#include "WGraph.h"

int main()
{
    int VertexNum = 0;
    char line[100];

    printf("Enter the number of vertices: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &VertexNum);

    Graph g = newGraph(VertexNum);
    
}
