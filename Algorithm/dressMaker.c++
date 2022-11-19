#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
struct Data
{
    double cost;
    int o1, o2;
}a[2000];

int cmp(const void* a, const void* b)
{
    Data x, y;
    x = *(Data*)a;
    y = *(Data*)b;

    if (x.cost - y.cost < 0)         
        return -1;

    else if (x.cost - y.cost > 0)    
        return 1;

    return x.o1 - y.o1;
}

int main()
{
    int T;

    scanf("%d", &T);

    while (T--)
    {
        int n, i;
        double s, t;
        scanf("%d", &n);

        for (i = 1; i <= n; i++)
        {
            scanf("%lf %lf", &s, &t);
            a[i].cost = s / t;
            a[i].o1 = i;
        }

        qsort(&a[1], n, sizeof(a[1]), cmp);

        for (i = 1; i <= n; i++)
        {
            printf("%d", a[i].o1);

            if (i == n)  
                printf("\n");
            else        
                printf(" ");
        }

        if (T != 0)      
            printf("\n");
    }

    return 0;
}