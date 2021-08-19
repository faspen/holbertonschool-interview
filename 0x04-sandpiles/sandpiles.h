#ifndef SAND_H
#define SAND_H

#include <stdio.h>
#include <stdlib.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
static void print_grid(int grid[3][3]);
void topple_pile(int grid1[3][3], int grid2[3][3]);
int check_stability(int grid[3][3]);

#endif
