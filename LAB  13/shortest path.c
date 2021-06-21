#include<stdio.h>
 

#define V 4 // Number of vertices in the graph

#define INF 99999

void printSolution(int dist[][V]);

void floydWarshall (int graph[][V])
{
    int dist[V][V], i, j, k;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
 
    for (k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist);
}

void printSolution(int dist[][V])
{
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    /* Create the following weighted graph
            2
       (0)------->(3)
       /|\        /|\
      5 |          |
        |          | 1
        |          |
       (1)------->(2)
            10           */
    int graph[V][V] = { {0,   INF,  INF, 2},
                        {5, 0,   10, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };

    floydWarshall(graph);
    return 0;
}
