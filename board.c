/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:51:55 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/12 04:06:01 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_board	new_board(int *input, int len)
{
	t_board ret;

	ret.len_a = len;
	ret.len_b = 0;
	ret.a = input;
	ret.b = ft_calloc(sizeof(int), len);
	return (ret);
}

int	get_lower_index(t_board board)
{
	int	i;
	int	index;
	int	tmp;

	i = 1;
	index = 0;
	tmp = board.a[index];
	while (i < board.len_a)
	{
		if (tmp > board.a[i])
		{
			index =i;
			tmp = board.a[i];
		}
		i++;
	}
	return (index);
}

int	is_sorted(t_board board)
{
	int	i;

	i = 0;
	while (i < board.len_a)
	{
		if (board.a[i] > board.a[i + 1])
			return (0);
		i++;
	}
	return (1);
}


