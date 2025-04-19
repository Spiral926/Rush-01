/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jie-lee <jie-lee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:33:38 by jie-lee           #+#    #+#             */
/*   Updated: 2025/04/19 18:52:14 by jie-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

typedef struct
{
	int	value;
} Clue;

int	parse_input(char *input, Clue clue[]);
int	solver(int grid[4][4], Clue clue[], int position);
void	print_grid(int grid[4][4]);

int	main(int argc, char **argv)
{
	Clue clues[4];
	int	grid[4][4] = {0};
	int	clues[16];
	int	grid[4][4];

	if (argc != 2 || !parse_input(argv[1], clues))
	{
		write (1, "Error\n", 6);
		return (1);
	}
	if (!solver(grid, clues, 0))
	{
		write (1, "Error\n", 6);
		return (1);
	}
	print_grid(grid);
	return (0);
}
