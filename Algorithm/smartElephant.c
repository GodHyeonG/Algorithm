/* Smart Elephant (Dynamic programming) - 202135570 이현지 */
#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define MAX 1000

struct elephant {
    int weight;
    int iq;
} e[MAX];

/* For ascending order */
int compare_a(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}
/* For descending order */
int compare_d(const void *a, const void *b)
{
    return (*(int*)b - *(int*)a);
}

void main()
{
    int eWeight_copy[MAX], eIQ_copy[MAX];
    int w[MAX], iq[MAX];
    int n = 0, num = 0;
    
    //Input data
    while (scanf("%d %d", &e[n].weight, &e[n].iq) != EOF)
    {
        num = n + 1;
        n++;
    }

    for (int i = 0; i < num; i++)
    {
        eWeight_copy[i] = e[i].weight;
        eIQ_copy[i] = e[i].iq;
    }

    /* Ascending order (Weight) */
    qsort(&eWeight_copy, num, sizeof(int), compare_a);
    /* Descending order (IQ) */
    qsort(&eIQ_copy, num, sizeof(int), compare_d);

    /* Weight */
    for (int i = 0; i < num; i++)
    {
        int j, count = 0, same[MAX], index = 0;

        for (j = 0; j < num; j++)
        {
            if (eWeight_copy[i] == e[j].weight)
            {
                count++;
                same[index++] = j;
            }
        }

        if (count == 1)
            w[i] = same[index - 1] + 1;
        else //If there are elephants with same weight
        {
            int temp = 0;
            for (int a = 0; a < index - 1; a++)
            {
                for (int b = a + 1; b < index; b++)
                {
                    if (e[same[a]].iq > e[same[b]].iq)
                    {
                        temp = same[a];
                        same[a] = same[b];
                        same[b] = temp;
                    }
                }
            }

            for (int a = 0; a < index; a++)
            {
                w[i++] = same[a] + 1;
            }
            i--;
        }
    }

    /* IQ */
    for (int i = 0; i < num; i++)
    {
        int j, count = 0, same[MAX], index = 0;

        for (int j = 0; j < num; j++)
        {
            if (eIQ_copy[i] == e[j].iq)
            {
                count++;
                same[index++] = j;
            }
        }

        if (count == 1)
            iq[i] = same[index - 1] + 1;
        else //If there are elephants with same IQ
        {
            int temp = 0;
            for (int a = 0; a < index - 1; a++)
            {
                for (int b = a + 1; b < index; b++)
                {
                    if (e[same[a]].weight < e[same[b]].weight)
                    {
                        temp = same[a];
                        same[a] = same[b];
                        same[b] = temp;
                    }
                }
            }

            for (int a = 0; a < index; a++)
            {
                iq[i++] = same[a] + 1;
            }
            i--;
        }
    }
    
    /* Create table (Using Dynamic Array) */
    int** table = (int**)malloc((num + 1) * sizeof(int*));
    for (int i = 0; i <= num; i++)
        table[i] = (int*)malloc((num + 1) * sizeof(int*));
    
    //First row is all 0
    for (int i = 0; i <= num; i++)
        table[0][i] = 0;
    //First column is all 0
    for (int i = 0; i <= num; i++)
        table[i][0] = 0;
    
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            if (w[i - 1] == iq[j - 1])
                table[i][j] = table[i - 1][j - 1] + 1; //대각선 + 1
            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }
    
    //Length
    int result = table[num][num];
    //Path
    int a = num, b = num;
    int idx = result, r[MAX];
    while (table[a][b] != 0)
    {
        if (table[a][b] == table[a][b - 1])
            b--;

        else if (table[a][b] == table[a - 1][b])
            a--;

        else if (table[a][b] - 1 == table[a - 1][b - 1])
        {
            r[idx - 1] = w[a - 1];
            a--;
            b--;
            idx--;
        }
    }
    //Print result
    printf("%d\n", result);
    for (int i = 0; i < result; i++)
        printf("%d ", r[i]);
    
    free(table);
}