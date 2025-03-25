#include "stdio.h"
#include "Graph.h"


bool hasCycleDFS(Graph g, Vertex v, bool visited[], Vertex parent)
{
    visited[v] = true; 

   
    for (int i = 0; i < numOfVertices(g); i++)
    {
        if (adjacent(g, v, i))
        { 
            if (!visited[i])
            {
                if (hasCycleDFS(g, i, visited, v))
                { 
                    return true;
                }
            }
            else if (i != parent)
            {                
                return true; 
            }
        }
    }
    return false; 
}


bool hasCycle(Graph g)
{
    int nV = numOfVertices(g);
    bool visited[nV]; 
    for (int i = 0; i < nV; i++)
    {
        visited[i] = false; 
    }

   
    for (int u = 0; u < nV; u++)
    {
        if (!visited[u])
        {
            if (hasCycleDFS(g, u, visited, -1))
            {                
                return true;
            }
        }
    }
    return false; 
}

int main()
{
    int VertexNum = 0;
    char line[100];

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

        insertEdge(g, e);
    }

    printf("Done.\n");
    if (hasCycle(g))
    {
        /* code */
        printf("The graph has cycle.\n");
    }
    else
    {
        printf("The graph is acyclic.\n");
    }

    return 0;
}