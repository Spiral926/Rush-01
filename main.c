/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jie-lee <jie-lee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:33:38 by jie-lee           #+#    #+#             */
/*   Updated: 2025/04/20 16:06:10 by jie-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	solve(int grid[4][4], int clues[16], int row, int col);

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	print_grid(int grid[4][4])
{
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			write(1, &("01234"[grid[r][c]]), 1);
			if (c < 3)
				write(1, " ", 1);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}

int	main(int argc, char **argv)
{
	int	clues[16];
	int	grid[4][4];
	int	i;
	int	r;
	int	c;

	i = 0;
	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			grid[r][c] = 0;
			c++;
		}
		r++;
	}
	if (argc != 17)
	{
		write(1, "Error(a)\n", 9);
		return (1);
	}
	while (i < 16)
	{
		clues[i] = ft_atoi(argv[i + 1]);
		if (clues[i] < 1 || clues[i] > 4)
		{
			write(1, "Error(b)\n", 9);
			return (1);
		}
		i++;
	}
	if (solve(grid, clues, 0, 0))
		print_grid(grid);
	else
		write(1, "Error(c)\n", 9);
	return (0);
}
