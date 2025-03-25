#include "stdio.h"
#include "Graph.h"

// 辅助函数：DFS 检查环
bool hasCycleDFS(Graph g, Vertex v, bool visited[], Vertex parent) {
    visited[v] = true;  // 标记当前顶点为已访问

    // 遍历所有邻接顶点
    for (int i = 0; i < numOfVertices(g); i++) {
        if (adjacent(g, v, i)) {  // 如果 v 和 i 之间有边
            if (!visited[i]) {    // 如果 i 未被访问过
                if (hasCycleDFS(g, i, visited, v)) {  // 递归检查
                    return true;
                }
            } else if (i != parent) {  // 如果 i 已被访问过且不是父节点
                return true;  // 发现环
            }
        }
    }
    return false;  // 未发现环
}

// 检查图中是否存在环
bool hasCycle(Graph g) {
    int nV = numOfVertices(g);
    bool visited[nV];  // 记录顶点是否被访问过
    for (int i = 0; i < nV; i++) {
        visited[i] = false;  // 初始化 visited 数组
    }

    // 对每个未访问的顶点进行 DFS 检查
    for (int u = 0; u < nV; u++) {
        if (!visited[u]) {  // 如果顶点 u 未被访问过
            if (hasCycleDFS(g, u, visited, -1)) {  // 调用 DFS 检查
                return true;  // 发现环
            }
        }
    }
    return false;  // 未发现环
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
    if (hasCycle)
    {
        /* code */
        printf("The graph has cycle.");
    }
    else {
        printf("The graph is acyclic.")
    }
    

    // showGraph(g);

    return 0;
}