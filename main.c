/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:46:44 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/16 19:11:48 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	finish(t_board board)
{
	free(board.a);
	free(board.b);
}
#include <stdio.h>
//#define UNIT




#ifndef UNIT
int	main(int argc, char **argv)
{
	(void) argc;
	t_step	*step;
	t_board board;
	int try = 0;
	int		*lowers;
	int		i;
	int		len;
	t_map map;

	
	board = parse(argv[1]);
	int	*result = ft_calloc(sizeof(int) , board.len_a);
	int size = board.len_a;
	while (try < size)
	{
		board = parse(argv[1]);
		board.step = 0;
		board.no_step = 0;

		map.up = UP;
		map.down = DOWN;
		map.f = ATOB;
		while (board.len_a > 0)
		{
			len = try;
			if (len == 0) len = 1;
			if (len > board.len_a)
				len = board.len_a;
			lowers = find_lowers(board, len);
			//lowers = sort(lowers, len);
			i = 0;
			while (i < len)
			{
				step = get_top_path(board.len_a, get_index(board.a, lowers[i], board.len_a),map);
				if (board.step == 0)
					board.step = step;
				else
					ft_lstadd_back(&board.step, step);
				do_step(&board, step);
				i++;
			}
			free(lowers);
		}
		map.up = UP_B;
		map.down = DOWN_B;
		map.f = BTOA;
		while (board.len_b > 0)
		{
			step = get_top_path(board.len_b, find_highest(board.b, board.len_b), map);
			ft_lstadd_back(&board.step, step);
			do_step(&board, step);
		}
		ft_putstr_fd("Chunk of ", 1);
		ft_putnbr_fd(try, 1);
		ft_putstr_fd(" - Nombre d'etapes: ", 1);
		ft_putnbr_fd(board.no_step, 1);
		result[try] = board.no_step;
		ft_putendl_fd("", 1);
		try++;
	}
	ft_putendl_fd("\nGetting lowest...\nIndex ", 1);
	ft_putnbr_fd(find_lower_ar(result, size), 1);
	ft_putendl_fd("\nValue", 1);
	ft_putnbr_fd(result[find_lower_ar(result, size)], 1);
//	ft_printboard(board);
}
#endif

#ifdef UNIT
#include <stdio.h>


void	test_find_lowers(t_board board)
{
	int	i = 0;
	int size = 5;
	int *lowers = find_lowers(board, size);
	while (i < size)
	{
		printf("lowers value: %i\n", lowers[i]);
		i++;
	}

}

int	main(int argc, char **argv)
{
	t_board	board;
	board = parse(argv[1]);
	(void) argc;
	test_find_lowers(board);
	return (0);
/*	lowers = sort(lowers, 5);

	(void) lowers;
	(void) argc;
	ft_putendl_fd("", 1);
	board.step = get_top_path(board, 6);
	print_steps(board);
		ft_putendl_fd("\ntest ra before", 1);
	ft_printboard(board);
	int no_rb = 0;
	while (no_rb < 5)
	{
		ra(&board);
		ft_putstr_fd("\nafter - ",1);
		ft_putnbr_fd(no_rb, 1);
		ft_putendl_fd(" ra", 1);
		ft_printboard(board);
		no_rb++;
	}
	ft_putendl_fd("\ntest rra before", 1);
	ft_printboard(board);
	no_rb = 0;
	while (no_rb < 3)
	{
		rra(&board);
		ft_putstr_fd("\nafter - ",1);
		ft_putnbr_fd(no_rb, 1);
		ft_putendl_fd(" rra", 1);
		ft_printboard(board);
		no_rb++;
	}
	return (0);*/
}
#endif
