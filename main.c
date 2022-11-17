/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:46:44 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/17 03:33:36 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish(t_board board)
{
	free(board.a);
	free(board.b);
}

t_map	reset_board(t_board *board, int a)
{
	t_map	map;

	board->step = 0;
	if (a)
	{
		board->no_step = 0;
		map.up = UP;
		map.down = DOWN;
		map.f = ATOB;
	}
	else
	{
		map.up = UP_B;
		map.down = DOWN_B;
		map.f = BTOA;
	}
	return (map);
}

void	sort_chunk(t_board *board, int len, int print, t_map map)
{
	t_step	*step;
	int		i;
	int		*lowers;

	if (len == 0)
		len = 1;
	if (len > board->len_a)
		len = board->len_a;
	lowers = find_lowers(*board, len);
	i = 0;
	while (i < len)
	{
		step = get_top_path(board->len_a,
				get_index(board->a, lowers[i], board->len_a), map);
		if (board->step == 0)
			board->step = step;
		else
			append_board_step(board, *step);
		do_step(board, step, print);
		i++;
	}
	free(lowers);
}

void	resolve(t_board *board, int try, int print)
{	
	t_step	*step;
	int		len;
	t_map	map;

	map = reset_board(board, 1);
	while (board->len_a > 0)
	{
		len = try;
		sort_chunk(board, len, print, map);
	}
	map = reset_board(board, 0);
	while (board->len_b > 0)
	{
		step = get_top_path(board->len_b,
				find_highest(board->b, board->len_b), map);
		ft_lstadd_back(&board->step, step);
		do_step(board, step, print);
	}
}

#ifndef UNIT

int	main(int argc, char **argv)
{
	t_board	board;
	int		try;
	int		*result;
	int		size;

	if (argc < 2)
	{
		ft_putendl_fd("try ./push_swap \"1 2 3\"", 1);
		return (0);
	}
	if (argc > 2)
		board = parse_ar(argc, argv);
	else
		board = parse(argv[1]);
	if (!is_uniq(board))
	{
		ft_putendl_fd("Error (with newline)", 1);
		return (0);
	}
	if (is_sorted(board))
		return (0);
	size = board.len_a / 5;
	result = ft_calloc(sizeof(int), size);
	try = 0;
	while (try < size)
	{
		if (argc > 2)
			board = parse_ar(argc, argv);
		else
			board = parse(argv[1]);
		resolve(&board, try, 0);
		result[try] = board.no_step;
		try++;
	}
	if (argc > 2)
		board = parse_ar(argc, argv);
	else
		board = parse(argv[1]);
	resolve(&board, find_lower_ar(result, size), 1);
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
