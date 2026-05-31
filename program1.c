#include <stdio.h>

#define MAX 100

int main()
{
    int graph[MAX][MAX];
    int indeg[MAX];
    int q[MAX];
    int topo[MAX];
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        indeg[i] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
                indeg[j]++;
        }
    }

    int front = 0, rear = -1;

    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            q[++rear] = i;
    }

    int count = 0;

    while (front <= rear)
    {
        int v = q[front++];
        topo[count++] = v;

        for (int j = 0; j < n; j++)
        {
            if (graph[v][j] == 1)
            {
                indeg[j]--;

                if (indeg[j] == 0)
                    q[++rear] = j;
            }
        }
    }

    if (count == n)
    {
        printf("Topological Order:\n");
        for (int i = 0; i < n; i++)
            printf("%d ", topo[i]);
    }
    else
    {
        printf("Cycle exists. Topological ordering is not possible.");
    }

    return 0;
}