#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * topple_pile - topple the sandpile
 * @grid1: grid to topple
 * @grid2: comparison grid
 */
void topple_pile(int grid1[3][3], int grid2[3][3])
{
	int i, j, x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
			grid2[x][y] = grid1[x][y];
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid2[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (j - 1 >= 0)
					grid1[i][j - 1]++;
				if (j + 1 < 3)
					grid1[i][j + 1]++;
				if (i - 1 >= 0)
					grid1[i - 1][j]++;
				if (i + 1 < 3)
					grid1[i + 1][j]++;
			}
		}
	}
}

/**
 * check_stability - check if sandpile is stable
 * @grid: grid to check
 * Return: 0 if stable, 1 if not
 */
int check_stability(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (1);
	}
	return (0);
}

/**
 * sandpiles_sum - add two stable piles
 * @grid1: pile 1
 * @grid2: pile 2
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, stability;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	stability = check_stability(grid1);

	while (stability)
	{
		printf("=\n");
		print_grid(grid1);
		topple_pile(grid1, grid2);
		stability = check_stability(grid1);
	}
}
