#include <stdio.h>
#include <string.h>
#define MAX 240
struct apm {
    double time1; //Time which the appointment starts
    double time2; //TIme which the appointment ends
    char a[];
};
void main()
{
    int s; //Number of scheduled appointments
    int hh1, mm1, hh2, mm2; //[Time] hh1:mm1, hh2:mm2
    char appointment[MAX];
    //apm[s] {time1, time2, a}
    struct apm* apm = (struct apm*)malloc(s * sizeof(struct apm));

    int idx = 0; //index of struct apm[]
    for (int i = 0; i < s; i++)
    {
        scanf("%d:%d %d:%d %s", &hh1, &mm1, &hh2, &mm2, appointment);
        apm[idx].time1 = hh1 + (mm1 * 0.01);
        apm[idx].time2 = hh2 + (mm2 * 0.01);
        strcpy(apm[idx].a, appointment);
    }
}