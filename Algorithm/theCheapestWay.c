/* the cheapest way (Dynamic programming) - 202135570 이현지 */
#include <stdio.h>
#define MAX_R 10
#define MAX_C 100
int find_min(int ,int);
void print_path();
int m, n; //m: row, n: column
int table[MAX_R][MAX_C], cost[MAX_R][MAX_C], path[MAX_C];
    
void takeInput()
{
    while (scanf("%d %d", &m, &n) != EOF)
    {
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++)
                scanf("%d", &table[i][j]);
        }
    }
}

/* Create cost matrix (Calculate costs using table[][]) */
void create_costTable()
{
	for (int c = 0; c < n; c++)
	{
		for (int r = 0; r < m; r++)
		{
			if (c == 0) //first column
				cost[r][0] = table[r][0];
			else {
				int idx = find_min(r, c);
				cost[r][c] = table[r][c] + cost[idx][c - 1];
			}
		}
	}
}

int find_min(int r, int c)
{    
	//Use %(mod) because the matrix is "wrapping"
	int row = r, next_row = (r + 1) % m, pre_row = (r - 1 + m) % m; 
    int left, upperLeft, lowerLeft, min;

	upperLeft = cost[pre_row][c - 1]; //Upper diagonal
    left = cost[row][c - 1]; //Horizontal
    lowerLeft = cost[next_row][c - 1]; //Lower diagonal
    
    //Find minimum cost
    if (upperLeft < left) {
		if (upperLeft < lowerLeft)
			min = pre_row;
		else
			min = next_row;
	}
	else {
		if (left < lowerLeft)
			min = row;
		else
			min = next_row;
	}
    return min; //row index
}

/* Create the cheapest path[] with backtracking action */
void create_cheapestPath(int r_idx)
{
	int c = n, p_idx = n - 1;
	for (int i = 0; i < n; i++)
	{
		if (c == n)	{
			path[p_idx] = table[r_idx][c - 1];
			c--;
		}
		else {
			r_idx = find_min(r_idx, c);
			path[p_idx] = table[r_idx][c - 1];
			c--;
		}
		p_idx--;
	}
	print_path();
}

void print_path()
{
    for (int i = 0; i < n; i++)
        printf("%d ", path[i]);
    printf("\n");
}

void main()
{
    takeInput();
	create_costTable();
	//Find minimum cost & row index, at last column
	int minCost = cost[0][n - 1], r_idx = 0;
	for (int i = 1; i < m; i++)
	{
		if (minCost > cost[i][n - 1])
		{
			minCost = cost[i][n - 1];
			r_idx = i;
		}
	}
	create_cheapestPath(r_idx);
	printf("%d\n", minCost);
}