/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jie-lee <jie-lee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:14:08 by jie-lee           #+#    #+#             */
/*   Updated: 2025/04/19 19:02:42 by jie-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_board(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		i++;
		while (j < 4)
		{
			j++;
			write(1, &j, 1);
			if (j < 4 - 1)
				write(1, " ", 1);
		}
		write(1, &i, 1);
	}
	write(1, "\n", 1);
}
