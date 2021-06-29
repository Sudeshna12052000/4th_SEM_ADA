#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int n;

int minWeight(int weight[], bool included[])
{
    int min = INT_MAX, index = -1;
    for(int i = 0; i < n; i++)
    {
        if(!included[i] && weight[i] < min)
            min = weight[i], index = i;
    }
    return index;
}

void mst(int graph[n][n])
{
    int parent[n], weight[n];
    bool included[n];
    for(int i = 0; i < n; i++)
        weight[i] = INT_MAX, included[i] = false;
    weight[0] = 0;
    parent[0] = -1;

    for(int i = 0; i < n-1; i++)
    {
        int k = minWeight(weight, included);
        included[k] = true;
        for(int j = 0; j < n; j++)
        {
            if(graph[i][j] && !included[j] &&  graph[i][j] < weight[j])
                parent[j] = i, weight[j] = graph[i][j];
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
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
            scanf("%d",&graph[i][j]);
    }
    mst(graph);
    return 0;
}
