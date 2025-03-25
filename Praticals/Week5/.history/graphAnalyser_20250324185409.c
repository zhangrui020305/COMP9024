#include "stdio.h"
#include "Graph.h"

int edgeCnt = 0;

int countDegree(Graph g, Vertex v)
{
    int deg = 0;

    for (int i = 0; i < numOfVertices(g); i++)
    {
        if (adjacent(g, v, i))
        {
            deg++;
        }
    }
    return deg;
}

void has3Clique(Graph g)
{
    printf("3-cliques:\n");
    int nV = numOfVertices(g);

    for (int u = 0; u < nV; u++)
    {
        for (int v = u + 1; v < nV; v++)
        {
            if (!adjacent(g, u, v))
                continue;
            for (int w = v + 1; w < nV; w++)
            {
                if (adjacent(g, v, w) && adjacent(g, u, w))
                {
                    printf("%d-%d-%d\n", u, v, w);
                }
            }
        }
    }
}

// 获取图中的边数
int getNumEdges(Graph g) {
    assert(g != NULL);
    int E = 0;
    int V = numOfVertices(g);

    // 遍历邻接矩阵的上三角部分
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (g->edges[i][j]) {  // 如果存在边 (i, j)
                E++;
            }
        }
    }
    return E;
}

// 计算图密度
void calDensity(Graph g) {
    int E = getNumEdges(g);  // 使用自定义函数获取边数
    int V = numOfVertices(g);
    double ans = (2.0 * E) / (V * V);
    printf("E: %d, V: %d\n", E, V);
    printf("Density: %.3f\n", ans);
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
        edgeCnt++;
    }

    printf("Done.\n");

    for (int i = 0; i < numOfVertices(g); i++)
    {
        printf("Degree of node %d: %d\n", i, countDegree(g, i));
    }

    showGraph(g);
    has3Clique(g);
    calDensity(g);

    return 0;
}