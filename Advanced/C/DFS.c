// Code-For-Hacktoberfest2020
// @Agarwal-Kritik
// Depth First Search in C Programming

//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Global Initialisation
int A[20][20], Visited[20], n;

//Function to perform DFS
void DFS(int v)
{
    int i;
    Visited[v] = 1;
    for (i = 1; i <= n; i++)
        if (A[v][i] && !Visited[i])
        {
            printf("\n %d -> %d ", v, i);
            DFS(i);
        }
}

//Main Function
void main()
{
    system("cls"); // Clear Screen Code if using on Windows
    //clrscr(); // Clear Screen Code if using on Mac/Ubuntu/Linux
    int i, j, c = 0;
    printf("\nInput The Number of Vertices :");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        Visited[i] = 0;
        for (j = 1; j <= n; j++)
            A[i][j] = 0;
    }
    printf("\nInput The Adjacency Matrix :\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &A[i][j]);
    DFS(1);
    printf("\n");
    for (i = 1; i <= n; i++)
    {
        if (Visited[i])
            c++;
    }
    if (c == n)
        printf("\nGraph: Connected!!\n\n");
    else
        printf("\nGraph: Not Connected!!\n\n");
}