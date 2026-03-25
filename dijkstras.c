#include <stdio.h>
#define INF 9999
#define MAX 10

void dijkstra(int c[MAX][MAX], int n, int s, int d[MAX]) {
    int v[MAX], i, j, u, min;
    for (i = 0; i < n; i++) {
        d[i] = c[s][i];
        v[i] = 0;
    }
    d[s] = 0;
    v[s] = 1;

    for (i = 1; i < n; i++) {
        min = INF;
        u = -1;

        for (j = 0; j < n; j++) {
            if (v[j] == 0 && d[j] < min) {
                min = d[j];
                u = j;
            }
        }
        if (u == -1) break;
        v[u] = 1;
        for (j = 0; j < n; j++) {
            if (v[j] == 0 && (d[u] + c[u][j]) < d[j]) {
                d[j] = d[u] + c[u][j];
            }
        }
    }
}
int main() {
    int n, s;
    int c[MAX][MAX], d[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix : \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
            if(c[i][j]==0){
                c[i][j]=INF;
            }
        }
    }

    printf("Enter source vertex (0-based index): ");
    scanf("%d", &s);

    dijkstra(c, n, s, d);

    printf("Shortest distances from source %d:\n", s);
    for (int i = 0; i < n; i++) {
        printf("To %d: %d\n", i, d[i]);
    }

    return 0;
}
