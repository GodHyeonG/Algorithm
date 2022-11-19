/* Lab1: Distinct Subsequences - 202135570 이현지 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Length no greater than 10
#define MAX_S 11 
#define MAX_T 11
void main()
{
    char s[MAX_S], t[MAX_T]; //t is subsequence of s

    scanf("%s", s);
    scanf("%s", t);
    int len_s = strlen(s);
    int len_t = strlen(t);
    
    /* Create 2-D matrix: dp[len_t + 1][len_s + 1] (Using dynamic array) */
    int** dp = (int**)malloc((len_t + 1) * sizeof(int*));
    for (int i = 0; i < len_t + 1; i++)
        dp[i] = (int*)malloc((len_s + 1) * sizeof(int*));
    
    /* Initializing */
    for (int j = 0; j < len_s + 1; j++)
        dp[0][j] = 1;
    for (int i = 1; i < len_t + 1; i++)
        dp[i][0] = 0;
    
    /* Create dp table */
    for (int i = 1; i < len_t + 1; i++)
    {
        for (int j = 1; j < len_s + 1; j++)
        {
            if (t[i - 1] == s[j - 1]) //Matching
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            else //Not matching
                dp[i][j] = dp[i][j - 1];
        }
    }

    int result = dp[len_t][len_s]; //Last value
    printf("%d", result);
    free(dp); //free malloc
}