/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:46:44 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/12 22:19:32 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish(t_board board)
{
	free(board.a);
	free(board.b);
}

int	main(int argc, char **argv)
{
	t_board	board;
	board = parse(argv[1]);

	int *lowers = find_lower(board, board.len_a / 2);
	(void) lowers;
	(void) argc;
	ft_putnbr_fd(lowers[0],1);
	ft_putendl_fd("", 1);
	board.step = get_top_path(board, 6);
	print_steps(board);


	free(lowers);
	return (0);
}
