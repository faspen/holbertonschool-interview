#include "menger.h"

/**
 * menger - draw a 2D menger sponge
 * @level: size of the sponge
 * Return: nothing
 */
void menger(int level)
{
	int i = 0, j = 0, row = 0, column = 0, size = pow(3, level);
	char hash;

	if (level < 0)
		return;

	while (i < size)
	{
		for (j = 0; j < size; j++)
		{
			row = i;
			column = j;
			hash = '#';

			while (row > 0 && column > 0)
			{
				if (row % 3 == 1 && column % 3 == 1)
					hash = ' ';
				row = row / 3;
				column = column / 3;
			}
			printf("%c", hash);
		}
		printf("\n");
		i++;
	}
}
