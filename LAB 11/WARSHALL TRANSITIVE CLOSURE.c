#include<stdio.h>
 
// Number of vertices in the graph
#define V 4
 

void printSolution(int reach[][V]);
 
void transitiveClosure(int graph[][V])
{
    int reach[V][V], i, j, k;
 
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            reach[i][j] = graph[i][j];

    for (k = 0; k < V; k++)
    {

        for (i = 0; i < V; i++)
        {

            for (j = 0; j < V; j++)
            {

                reach[i][j] = reach[i][j] ||
                  (reach[i][k] && reach[k][j]);
            }
        }
    }
 
    printSolution(reach);
}

void printSolution(int reach[][V])
{
    printf ("Following matrix is transitive");
    printf("closure of the given graph\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
              /* because "i==j means same vertex"
               and we can reach same vertex
               from same vertex. So, we print 1....
               and we have not considered this in
               Floyd Warshall Algo. so we need to
               make this true by ourself
               while printing transitive closure.*/
              if(i == j)
                printf("1 ");
              else
                printf ("%d ", reach[i][j]);
        }
        printf("\n");
    }
}
 

int main()
{
    /* Create the following weighted graph
            
       (0)--->(3)
       /|\\   
        |  \   
        |   \   
        |   _\|
       (1)<---(2)
                      */
    int graph[V][V] = { {1, 0, 1, 1},
                        {1, 1, 0, 0},
                        {0, 1, 1, 0},
                        {0, 0, 0, 1}
                      };
 
    transitiveClosure(graph);
    return 0;
}
