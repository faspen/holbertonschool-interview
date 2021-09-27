#include "slide_line.h"

/**
 * slide_right - slide numbers to the right
 * @line: line to slide
 * @size: number of elements
 */
void slide_right(int *line, size_t size)
{
	size_t i, j;

	for (i = size; i > 0; i--)
	{
		for (j = i - 1; j > 0; j--)
		{
			if (line[i - 1] != 0)
			{
				if (line[i - 1] == line[j - 1])
				{
					line[i - 1] = line[i - 1] + line[j - 1];
					line[j - 1] = 0;
					break;
				}
				if (line[i - 1] != line[j - 1] && line[j - 1] != 0)
					break;
			}
			if (line[i - 1] == 0)
			{
				if (line[j - 1] != 0)
				{
					line[i - 1] = line[j - 1];
					line[j - 1] = 0;
					i++;
					break;
				}
			}
		}
	}
}

/**
 * slide_left - slide numbers to the left
 * @line: line to slide
 * @size: number of elements
 */
void slide_left(int *line, size_t size)
{
	size_t i, j, z;

	for (i = 0, j = 0; i < size;)
	{
		if (line[i] == 0)
			for (; line[i] == 0;)
				i++;
		if (i == size - 1)
			break;

		j = i + 1;
		if (line[j] == 0)
			for (; line[j] == 0;)
				j++;
		if (line[i] == line[j])
		{
			line[i] = line[i] + line[j];
			line[j] = 0;
			i = j + 1;
		}
		else
			i++;
		j = 0;
	}
	for (i = 0, z = 0; i < size; i++)
		if (line[i] != 0)
			line[z++] = line[i];
	while (z < size)
		line[z++] = 0;
}

/**
 * slide_line - replicate 2048
 * @line: points to array of ints
 * @size: number of elements
 * @direction: left or right
 * Return: 1 on success, 0 on fail
 */
int slide_line(int *line, size_t size, int direction)
{
	if ((direction != SLIDE_LEFT) && (direction != SLIDE_RIGHT))
		return (0);
	if (direction == 0)
		slide_left(line, size);
	if (direction == 1)
		slide_right(line, size);
	return (1);
}
