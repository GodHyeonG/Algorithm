#include <stdio.h>
struct Box {
    int c; //Cost
    int n; //Number of pearls
    int m;  //Number of box required
};
struct Box box1;
struct Box box2;
int totalN; //Total number of pearls

/* Find Minimum total cost */
int minCost(int cheaper)
{
    int i, j; 
    int m1, m2; //Number of each boxs required
    if (cheaper == box1.n)
    {
        for (i = totalN; i >= 0; i--)
        {
            m1 = i;
            for (j = 0; j <= totalN; j++)
            {
                m2 = j;
                if (((box1.n * m1) + (box2.n * m2)) == totalN)
                {
                    box1.m = m1;
                    box2.m = m2;
                    return 0;
                }
            }
        }
        if (i < 0)
            return -1;
    }
    else if (cheaper == box2.n)
    {
        for (i = totalN; i >= 0; i--)
        {
            m2 = i;
            for (j = 0; j <= totalN; j++)
            {
                m1 = j;
                if (((box2.n * m2) + (box1.n * m1)) == totalN)
                {
                    box1.m = m1;
                    box2.m = m2;
                    return 0;
                }
            }
        }
        if (i < 0)
            return -1;
    }
}

void main()
{
    scanf("%d", &totalN);
    scanf("%d %d", &box1.c, &box1.n);
    scanf("%d %d", &box2.c, &box2.n);

    /* To find minimum total cost */
    int cheaper; //Cheaper box's pearls
    if (((double)box1.n / box1.c) > ((double)box2.n / box2.c))
        cheaper = box1.n;
    else
        cheaper = box2.n;
    
    //Result
    if (minCost(cheaper) == -1)
        printf("failed");
    else
        printf("Box1: %d, Box2: %d", box1.m, box2.m);
}