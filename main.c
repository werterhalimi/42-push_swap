/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:46:44 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/14 19:38:51 by shai             ###   ########.fr       */
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
	ft_putendl_fd("\ntest rb\n before", 1);
	ft_printboard(board);
	int no_rb = 0;
	while (no_rb < board.len_a)
	{
		rb(&board);
		ft_putstr_fd("\nafter - ",1);
		ft_putnbr_fd(no_rb, 1);
		ft_putendl_fd(" rb", 1);
		ft_printboard(board);
		no_rb++;
	}
	free(lowers);
	return (0);
}
