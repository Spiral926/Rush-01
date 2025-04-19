/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jie-lee <jie-lee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:42:25 by jie-lee           #+#    #+#             */
/*   Updated: 2025/04/19 18:40:25 by jie-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_in_row(int grid[4][4], int row, int num)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (grid[row][col] == num)
			return (1);
		col++;
	}
	return (0);
}

int	is_in_col(int grid[4][4], int col, int num)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (grid[row][col] == num)
			return (1);
		row++;
	}
	return (0);
}

int	parse_input(char *input, int *clues)
{
	int	i;

	i = 0;
	while (*input)
	{
		if (*input >= '1' && *input <= '4')
		{
			if (i >= 16)
				return (0);
			clues[i++] = *input - '0';
		}
		else if (*input != ' ')
			return (0);
		input++;
	}
	return (i == 16);
}
