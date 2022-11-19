#include <stdio.h>
int least();
int ary[10][10], completed[10], n, cost = 0;

void takeInput()
{
    int i, j;
    
    printf("Enter the number of villages: ");
    scanf("%d", &n);
    
    printf("\nEnter the Cost Matrix\n");
    
    for(i = 0; i < n; i++)
    {
        printf("\nEnter Elements of Row: %d\n", i + 1);
        
        for( j = 0; j < n; j++)
            scanf("%d", &ary[i][j]);
        
        completed[i] = 0; //Not yet visited
    }
    
    printf("\n\nThe cost list is:");
    
    for(i = 0; i < n; i++)
    {
        printf("\n");
        
        for(j = 0; j < n; j++)
            printf("\t%d", ary[i][j]);
    }
    /* Cost matrix is symmetric (ex. "1->2 cost" == "2->1 cost") */
}
 
void mincost(int city)
{
    int i, ncity; //ncity: next city
    
    completed[city] = 1; //Visit completed
    
    printf("%d--->", city + 1);
    ncity = least(city);
    
    //Visited all cities
    if(ncity == 999)
    {
        ncity = 0; //Go back to first visited city
        printf("%d", ncity + 1);
        cost += ary[city][ncity];
        
        return;
    }
    
    mincost(ncity);
}

/* Find next city to visit (Calculate least cost) */
int least(int c)
{
    int i, nc = 999; //nc: next city
    int min = 999, kmin; //kmin: Least cost of next city
    
    for(i = 0; i < n; i++)
    {
        /* If ary[c][i] == 0, city that currently visiting
           If completed[i] != 0, city that already visited */
        if((ary[c][i] != 0) && (completed[i] == 0))
        {
            if(ary[c][i] + ary[i][c] < min)
            {
                min = ary[i][0] + ary[c][i];
                kmin = ary[c][i];
                nc = i;
            }
        }
    }
    
    if(min != 999)
        cost += kmin;
    
    return nc;
}
 
int main()
{
    takeInput();
    
    printf("\n\nThe Path is:\n");
    mincost(0); //passing 0 because starting vertex
    
    printf("\n\nMinimum cost is %d\n ", cost);
    
    return 0;
}