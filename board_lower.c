/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_lower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:20:34 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/24 19:22:28 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_lower_ar(int *a, int len_a)
{
	int	i;
	int	ret;
	int	tmp;

	i = 1;
	ret = 0;
	tmp = a[0];
	while (i < len_a)
	{
		if (a[i] < tmp)
		{
			ret = i;
			tmp = a[i];
		}
		i++;
	}
	return (ret);
}

int	find_lower(t_board board)
{
	int	i;
	int	ret;
	int	tmp;

	i = 1;
	ret = 0;
	tmp = board.a[0];
	while (i < board.len_a)
	{
		if (board.a[i] < tmp)
		{
			ret = i;
			tmp = board.a[i];
		}
		i++;
	}
	return (ret);
}

int	*place_lower(t_board *board, int **ret, int size, int *i)
{
	int	j;
	int	count;
	int	p;

	p = 0;
	while (*i < board->len_a)
	{
		j = 0;
		count = 0;
		while (j < board->len_a)
		{
			if (j != *i && board->a[j] < board->a[*i])
				count++;
			if (count >= size)
				break ;
			j++;
		}
		if (count < size)
		{
			(*ret)[p] = board->a[*i];
			p++;
		}
		(*i) += 1;
	}
	return (*ret);
}

int	*find_lowers(t_board board, int size)
{
	int	*ret;
	int	i;
	int	p;

	if (board.len_a < size)
		size = board.len_a;
	ret = ft_calloc(sizeof(int), size);
	i = 0;
	p = 0;
	ret = place_lower(&board, &ret, size, &i);
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
			index = i;
			tmp = board.a[i];
		}
		i++;
	}
	return (index);
}
