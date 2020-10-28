// BFS using C
#include <stdio.h>
#include <stdlib.h>

// Global Variable Declaration/Initialisation
int A[20][20], Q[20], Visited[20], n, i, j, f = 0, r = -1;

// Function to perform BFS
void BFS(int v)
{
    for (i = 1; i <= n; i++)
        if (A[v][i] && !Visited[i])
            Q[++r] = i;

    if (f <= r)
    {
        Visited[Q[f]] = 1;
        BFS(Q[f++]);
    }
}

// Main FUnction, program execution starts here
void main()
{
    system("cls");
    int v;
    printf("\nInput The Number of Vertices :");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        Q[i] = 0;
        Visited[i] = 0;
    }

    printf("\nInput Graph Data in Matrix Form :\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nInput starting vertex:");
    scanf("%d", &v);

    BFS(v); // Function Call

    printf("\nThe Node Which Are Reachable are : ");
    for (i = 1; i <= n; i++)
    {
        if (Visited[i])
            printf("  %d  ", i);
        else
        {
            printf("\nBFS is Not Possible!!\nNot All Nodes Are Reachable!!");
            break;
        }
    }
    printf("\n");
}