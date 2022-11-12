/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:06:34 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/12 22:15:00 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_step	*get_top_path(t_board board, int index)
{
	t_step	*ret;
	char	*name;
	int		step;

	step = 0;
	if (board.len_a - index < index)
	{
		step = board.len_a - index;
		name = DOWN;
	}
	else
	{
		step = index;
		name = UP;
	}
	ret = ft_lstnew(name);
	while (step > 1)
	{
		ft_lstadd_back(&ret, ft_lstnew(name));
		step--;
	}
	ft_lstadd_back(&ret, ft_lstnew(0));
	return (ret);
}

void	print_steps(t_board board)
{
	while (board.step->content)
	{
		ft_putendl_fd(board.step->content, 1);
		board.step = board.step->next;
	}
}
