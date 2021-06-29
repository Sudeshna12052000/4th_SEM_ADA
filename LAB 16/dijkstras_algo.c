#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int n;

int min_distance(int dist[], bool included[])
{
    int min = INT_MAX, index;
    for(int i = 0; i < n; i++)
    {
        if(!included[i] && dist[i] < min)
            min = dist[i], index = i;
    }
    return index;
}

void dijkstra(int graph[n][n], int source)
{
    int dist[n];
    bool included[n];

    for(int i = 0; i < n; i++)
        dist[i] = INT_MAX, included[i] = false;
    
    dist[source] = 0;

    for(int i = 0; i < n; i++)
    {
        int d = min_distance(dist, included);
        included[d] = true;
        for(int j = 0; j < n; j++)
        {
            if(!included[j] && graph[d][j] && dist[d] != INT_MAX && dist[d] + graph[d][j] < dist[j])
                dist[j] = graph[d][j] + dist[d];
        }
    }

    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("\t%d \t\t\t %d\n", i, dist[i]);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d",&n); // Number of nodes

    int graph[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    dijkstra(graph, 0);
    return 0;
}
