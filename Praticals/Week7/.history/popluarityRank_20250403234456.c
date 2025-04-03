#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "WGraph.h"

typedef struct
{
    int vertex;
    double popularity;
} VertexPopularity;

void insertionSort(VertexPopularity array[], int n)
{
    int i;
    for (i = 1; i < n; i++)
    {
        VertexPopularity element = array[i]; // 当前要插入的元素
        int j = i - 1;

        // 先按popularity降序排序，相同则按vertex升序排序
        while (j >= 0 &&
               (array[j].popularity < element.popularity ||   // popularity大的排前面
                (array[j].popularity == element.popularity && // popularity相同
                 array[j].vertex > element.vertex)))
        {                            // vertex小的排前面
            array[j + 1] = array[j]; // 向后移动元素
            j--;
        }
        array[j + 1] = element; // 插入到正确位置
    }
}

int inDegree(Graph g, int v)
{
    int count = 0;
    for (int i = 0; i < numOfVertices(g); i++)
    {
        if (adjacent(g, i, v))
        {
            count++;
        }
    }
    return count;
}

double outDegree(Graph g, int v)
{
    double count = 0;
    bool hasOutEdge = false;
    for (int i = 0; i < numOfVertices(g); i++)
    {
        if (adjacent(g, v, i))
        {
            count++;
            hasOutEdge = true;
        }
    }
    return hasOutEdge ? count : 0.5;
}

double popularityCalculator(Graph g, int v)
{
    //  popularityRank(v) = inDegree(v) / outDegree(v)
    double popularity = (double)inDegree(g, v) / (double)outDegree(g, v);
    return popularity;
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
            e.weight = 1;
            insertEdge(g, e);
        }
    }

    printf("Done.\n");

    // printf("Popularity :\n");
    // for (int i = 0; i < numOfVertices(g); i++)
    // {
    //     /* code */
    //     printf("%d %.1f\n", i, popularityCalculator(g, i));
    // }
    // return 0;

    VertexPopularity *vertices = malloc(numOfVertices(g) * sizeof(VertexPopularity));
    for (int i = 0; i < numOfVertices(g); i++)
    {
        vertices[i].vertex = i;
        vertices[i].popularity = popularityCalculator(g, i);
    }

    insertionSort(vertices, numOfVertices(g));

    printf("Popularity ranking:\n");
    for (int i = 0; i < numOfVertices(g); i++)
    {
        printf("%d %.2f\n", vertices[i].vertex, vertices[i].popularity);
    }

    free(vertices);
    freeGraph(g);
    return 0;
}
