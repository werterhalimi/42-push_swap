/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:46:44 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/12 04:06:03 by shalimi          ###   ########.fr       */
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
	(void) argc;
	return (0);
}
