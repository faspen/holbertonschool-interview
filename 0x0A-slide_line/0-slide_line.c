#include "slide_line.h"

/**
 * slide_left - slide numbers to the left
 * @line: line to slide
 * @size: number of elements
 */
void slide_left(int *line, size_t size)
{

}

/**
 * slide_right - slide numbers to the right
 * @line: line to slide
 * @size: number of elements
 */
void slide_right(int *line, size_t size)
{

}

/**
 * slide_line - replicate 2048
 * @line: points to array of ints
 * @size: number of elements
 * @direction: left or right
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
