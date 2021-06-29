#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int n;

int find(int i, int parent[])
{
    while(parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j, int parent[])
{
    if(i == j)
        return 0;
    parent[j] = i;
    return 1;
}

void mst(int graph[n][n])
{
    printf("Edge \tWeight\n");
    int edges = 1, a, b, u, v, cost = 0;
    int parent[n];
    for(int i = 0; i < n; i++)
        parent[i] = 0;
    while(edges <= n-1)
    {
        int min = 10000;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(graph[i][j] < min)
                    min = graph[i][j], a = u = i, b = v = j;
            }
        }
        u = find(u, parent);
        v = find(v, parent);
        if(uni(u, v, parent))
        {
            printf("%d - %d \t%d \n", a, b, min);
            edges++;
            cost += min;
        }
        graph[a][b] = graph[b][a] = 10000;
    }
    printf("Minimum cost = %d\n",cost);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    int graph[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == 0)
                graph[i][j] = 10000;
        }
    }
    mst(graph);
    return 0;
}
