#include <stdio.h>

int parent[10];

int find(int i) {
    while (parent[i]) {
        i = parent[i];
    }
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int cost[10][10], n;
    int i, j, a, b, u, v;
    int ne = 1, min, mincost = 0;

    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 9999;
            }
        }
    }

    while (ne<n) {
        min=9999;
        for(i= 0i; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v)) {
            printf("%d -> %d = %d\n", a, b, min);
            mincost += min;
            ne++;
        }
        cost[a][b] = cost[b][a] = 9999;
    }
    printf("Minimum cost of spanning tree = %d\n", mincost);
    return 0;
}
