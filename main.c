/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:46:44 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/24 19:45:18 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_map	reset_board(t_board *board, int a)
{
	t_map	map;

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
		do_step(board, step, print);
		i++;
	}
	free(lowers);
}

void	resolve(t_board *board, int try, int print, int *result)
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
		do_step(board, step, print);
	}
	free(board->a);
	free(board->b);
	(void) result;
}

int	main(int argc, char **argv)
{
	t_board	board;
	int		try;
	int		*result;
	int		size;

	if (!redirect(argc, argv, &board))
		return (0);
	size = board.len_a / 5;
	result = ft_calloc(sizeof(int), size);
	try = 0;
	while (try < size)
	{
		resolve(&board, try, 0, 0);
		result[try] = board.no_step;
		try++;
		if (argc > 2)
			board = parse_ar(argc, argv);
		else
			board = parse(argv[1]);
	}
	resolve(&board, find_lower_ar(result, size), 1, result);
	free(result);
	return (0);
}
