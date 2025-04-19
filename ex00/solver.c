/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jie-lee <jie-lee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:01:17 by jie-lee           #+#    #+#             */
/*   Updated: 2025/04/19 18:54:16 by jie-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define SIZE 4

typedef struct
{
	int	value;
} Clue;

int	is_in_row(int grid[4][4], int row, int num);
int	is_in_col(int grid[4][4], int col, int num);
int	check_visibility(int grid[4][4], Clue clues[]);
int	is_safe(int grid[4][4], int row, int col, int num);
int	solve(int grid[4][4], Clue clues[], int pos);

int	solve(int grid[4][4], int *clues, int posi)
{
	int	row;
	int	col;
	int	num;

	row = posi / 4;
	col = posi % 4;
	if (posi == 16)
	{
		return (check_visibility(grid, clues));
	}
	num = 1;
	while (num <= 4)
	{
		if (is_safe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, clues, posi + 1))
				return (1);
			grid[row][col] = 0;
		}
	}
	return (0);
}
