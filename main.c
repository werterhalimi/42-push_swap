/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:46:44 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/11 23:30:03 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish(t_board board)
{
	free(board.b);
}

int	main(void)
{
	t_board	board;
	int		input[5] = {1, 2, 0, 4, 5};

	board = new_board(input, 5);
	ft_putnbr_fd(get_lower_index(board), 1);
	ft_putendl_fd("", 1);
	return (0);
}
