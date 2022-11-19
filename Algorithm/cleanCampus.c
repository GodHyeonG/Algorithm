/* Clean Campus (Computational Geometry) - 202135570 이현지 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Point {
    double x;
    double y;
};
double computeAngle(struct Point*, struct Point*, struct Point*);
double computeLength(struct Point*, struct Point*);
int num; //number of point

void main()
{
    scanf("%d", &num);

    //p[] (struct Point)
    struct Point* p = (struct Point*)malloc((num + 1) * sizeof(struct Point)); 
    p[0].x = 0; p[0].y = 0;
    for (int i = 1; i <= num; i++)
        scanf("%lf %lf", &p[i].y, &p[i].x);
    
    //angle[][]
    double** angle = (double**)malloc(num * sizeof(double*));
    for (int i = 0; i <= num; i++)
        angle[i] = (double*)malloc((num + 1) * sizeof(double*));

    double minAngle;
    double result = 0; //Total length of silk
    int i, j, idx = 0, pre_idx = 0, min_idx, last_idx;
    int* passed_idxArr = (int*)malloc((num + 1) * sizeof(int)); //passed_idxArr[]
    int passed_idx = 0; //Already passed point index for idxArr[]
    //Initialized
    for (int z = 0; z <= num; z++)
        passed_idxArr[z] = -1;
    for (i = 0; i <= num; i++)
    {
        minAngle = 360;
        for (j = 0; j <= num; j++)
        {
            for (int z = 0; z < num; z++)
            {
                if (j == passed_idxArr[z])
                {
                    j++;
                    z = 0; //reset
                }    
            }
            if (j > num)
                break;

            if (idx == j) continue;
            else
            {
                angle[idx][j] = computeAngle(&p[idx], &p[j], &p[pre_idx]);
                /* Find minimum angle */
                if (minAngle > angle[idx][j])
                {
                    minAngle = angle[idx][j];
                    min_idx = j;
                }
            }   
        }
        //Last point
        if (j > num && minAngle == 360)
        {
            result += computeLength(&p[idx], &p[0]);
            break;
        }    
        result += computeLength(&p[idx], &p[min_idx]);
        
        pre_idx = idx;
        passed_idxArr[passed_idx++] = idx;
        idx = min_idx; //update
    }
    
    result += 2; //Plus one extra meter at each end to tie it
    printf("Silk length: %.2lf", result);

    free(p); free(angle); free(passed_idxArr);
}

double computeAngle(struct Point* m, struct Point* n, struct Point* pre)
{
    double dx, dy, angle;
    double a, b = -1, c;
    if (m->x == 0 && m->y == 0) //First
    {
        dx = n->x - m->x;
        dy = n->y - m->y;
    }
    else
    {
        //dy: Distance of ax + by + c = 0, point(x,y)
        a = (m->y - pre->y) / (m->x - pre->x);
        c = -1 * a * pre->x + pre->y;
        dy = (double)abs(a * n->x + b * n->y + c) / sqrt(pow(a, 2) + pow(b, 2));
        dx = sqrt(pow(computeLength(m, n), 2) - pow(dy, 2));
        if (n->x < 0) dx *= -1;
        if (n->y < 0) dy *= -1;
    }
    
    if (dx >= 0 && dy == 0) angle = 0;
    else
    {
        angle = (double)abs(dy) / (abs(dx) + abs(dy));

        if ((dx < 0) && (dy >= 0)) //2사분면
            angle = 2 - angle;
        else if ((dx <= 0) && (dy < 0)) //3사분면
            angle = 2 + angle;
        else if ((dx > 0) && (dy < 0)) //4사분면
            angle = 4 - angle;
    }
    return (angle * 90.0);
}

double computeLength(struct Point* m, struct Point* n)
{
    double len = sqrt(pow(m->x - n->x, 2) + pow(m->y - n->y, 2));
    return len;
}