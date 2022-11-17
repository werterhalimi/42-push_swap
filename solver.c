/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:06:34 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/17 01:42:34 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_step	*get_top_path(int len, int index, t_map map)
{
	t_step	*ret;
	char	*name;
	int		step;

	step = 0;
	if (len - index < index)
	{
		step = len - index;
		name = map.down;
	}
	else
	{
		step = index;
		name = map.up;
	}
	ret = ft_lstnew(name);
	while (step-- > 1)
		ft_lstadd_back(&ret, ft_lstnew(name));
	ft_lstadd_back(&ret, ft_lstnew(map.f));
	ft_lstadd_back(&ret, ft_lstnew(0));
	if (index == 0)
		return (ret->next);
	return (ret);
}

void	do_step(t_board *board, t_step *step, int print)
{
	while (step->next)
	{
		if (ft_strncmp(step->content, UP_B, ft_strlen(UP_B)) == 0)
			rb(board);
		if (ft_strncmp(step->content, DOWN_B, ft_strlen(DOWN_B)) == 0)
			rrb(board);
		if (ft_strncmp(step->content, UP, ft_strlen(UP)) == 0)
			ra(board);
		if (ft_strncmp(step->content, DOWN, ft_strlen(DOWN)) == 0)
			rra(board);
		if (ft_strncmp(step->content, ATOB, ft_strlen(ATOB)) == 0)
			push_b(board);
		if (ft_strncmp(step->content, BTOA, ft_strlen(BTOA)) == 0)
			push_a(board);
		board->no_step += 1;
		if (print)
			ft_putendl_fd(step->content, 1);
		step = step->next;
	}
}

void	print_steps(t_board board)
{
	while (board.step->content)
	{
		ft_putendl_fd(board.step->content, 1);
		board.step = board.step->next;
	}
}
