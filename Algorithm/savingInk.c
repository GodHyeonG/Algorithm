/* Saving ink (Kruskal's algorithm) - 202135570 이현지 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct edge {
    int v1; //Current vertex
    int v2; //Next vertex
    double d; //Distance between v1, v2
};

/* For ascending order */
int compare(const void *a, const void *b)
{
    if (((struct edge*)a)->d > ((struct edge*)b)->d) return 1;
	if (((struct edge*)a)->d < ((struct edge*)b)->d) return -1;
	return 0;
}

int main()
{
    double minLength = 0;
    int num; //number of dots (0 < num < 30)

    scanf("%d", &num);
    if (num < 0 || num > 30) return -1; //Terminate program (Invalid input)

    //Create 2-D matrix dots[num][2] (using Dynamic Memory Allocation)
    double** dots = (double**)malloc(num * sizeof(double*));
    for (int i = 0; i < num; i++)
        dots[i] = (double*)malloc(2 * sizeof(double*));

    //Input dots
    for (int x = 0; x < num; x++)
        scanf("%lf %lf", &dots[x][0], &dots[x][1]);

    //Create struct e[] {v1, v2, d}
    int tot_num = (num * (num - 1)) / 2; //Total number of edges
    struct edge* e = (struct edge*)malloc(tot_num * sizeof(struct edge));
    int idx = 0; //e[]'s index

    /* Saving all edges connecting two different vertex (v1, v2) */
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            e[idx].v1 = i;
            e[idx].v2 = j;
            e[idx].d = sqrt(pow(dots[i][0] - dots[j][0], 2) + pow(dots[i][1] - dots[j][1], 2));
            idx++;
        }
    }
    /* Ascending order (Distance) */
    qsort(e, tot_num, sizeof(struct edge), compare);

    //Create array set[num]: Find-set (Save vertex)
    int* set = (int*)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++)
        set[i] = i;

    /* Kruskal's Algorithm */
    for (int i = 0; i < tot_num; i++)
    {
        //Disjoint-set data structure
        if (set[e[i].v1] != set[e[i].v2])
        {
            int temp = set[e[i].v1];
            for (int j = 0; j < num; j++)
            {
                if (set[j] == temp)
                    set[j] = set[e[i].v2]; //update
            }
            minLength += e[i].d; //Add minimum distance
        }
    }

    printf("%.2lf", minLength);
    free(dots); free(e); free(set); return 0;
}