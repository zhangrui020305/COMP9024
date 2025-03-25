#include "stdio.h"
#include "Graph.h"
#include <stdbool.h>

bool hasCycleDFS(Graph g, Vertex v, bool visited[], Vertex parent)
{
    visited[v] = true;

    for (int i = 0; i < numOfVertices(g); i++)
    {
        if (adjacent(g, v, i))
        {
            if (!visited[i]) // 发现新的未访问节点，继续 DFS
            {
                if (hasCycleDFS(g, i, visited, v))
                {
                    return true;
                }
            }
            else if (i != parent) // 发现回边，且不是父节点
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

    // 初始化 visited 数组
    for (int i = 0; i < nV; i++)
    {
        visited[i] = false;
    }

    // 确保每个连通分量都被遍历，防止孤立点或孤立边影响结果
    for (int u = 0; u < nV; u++)
    {
        if (!visited[u]) // 确保遍历所有连通分量
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
        printf("The graph has a cycle.\n");
    }
    else
    {
        printf("The graph is acyclic.\n");
    }

    return 0;
}
