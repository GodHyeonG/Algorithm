#include <stdio.h>
#include <stdlib.h>
void main()
{
    int num; //number of students
    int sum = 0, tenwon = 0, equalizedCost = 0;
    int result = 0;

    scanf("%d", &num);
    //cost[num]: students' each cost
    int* cost = (int*)malloc(num * sizeof(int)); 
    
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &cost[i]); //Input each cost (10 won units)
        sum += cost[i]; //Total amount of money
    }
    
    tenwon = sum % 100; 
    int t = tenwon / 10; //10의 자릿수
    equalizedCost = (sum - tenwon) / num + (t / num * 10);
    
    for (int i = 0; i < num; i++)
    {
        if (equalizedCost >= cost[i])
            result += equalizedCost - cost[i];
    }

    printf("Total exchanged : %d", result);
    free(cost);
}