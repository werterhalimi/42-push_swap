/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:06:45 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/22 17:06:30 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_step	*solve_3(int *a)
{
	t_step	*step;
	t_step	c;

	step = &c;
	if (a[0] > a[1] && a[2] > a[0] && a[0] < a[2])
		step->content = "sa";
	else if (a[0] < a[1] && a[2] < a[0] && a[0] > a[2])
		step->content = "rra";
	else if (a[0] < a[1] && a[2] < a[1])
	{
		step->content = "ra";
		ft_lstadd_back(&step, ft_lstnew("sa"));
		ft_lstadd_back(&step, ft_lstnew("rra"));
	}
	else if (a[0] > a[1] && a[2] > a[1])
		step->content = "ra";
	else
	{
		step->content = "sa";
		ft_lstadd_back(&step, ft_lstnew("rra"));
	}
	ft_lstadd_back(&step, ft_lstnew(0));
	return (step);
}

void	solve_three(t_board *board)
{
	t_step	*step;
	t_step	current;

	step = &current;
	if (is_sorted(*board))
		return ;
	if (board->len_a == 2)
	{
		ft_putendl_fd("ra", 1);
		step = ft_lstnew("ra");
		ra(board);
	}
	else
	{
		step = solve_3(board->a);
	}
	do_step(board, step, 1);
}

void	solve_five(t_board *board)
{
	int		i;
	t_map	map;

	map.up = UP;
	map.down = DOWN;
	map.f = ATOB;
	do_step(board, get_top_path(board->len_a, find_lower(*board), map), 1);
	do_step(board, get_top_path(board->len_a, find_lower(*board), map), 1);
	solve_three(board);
	i = 0;
	while (board->a[i] < board->b[0] && board->len_a > i)
	{
		ft_putendl_fd("ra", 1);
		i++;
	}
	ft_putendl_fd("pa", 1);
	ft_putendl_fd("pa", 1);
	if (i > 0)
		ft_putendl_fd("rra", 1);
}
