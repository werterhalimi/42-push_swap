/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:51:55 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/17 01:46:57 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_board	new_board(int *input, int len)
{
	t_board	ret;

	ret.step = 0;
	ret.no_step = 0;
	ret.len_a = len;
	ret.len_b = 0;
	ret.a = input;
	ret.b = ft_calloc(sizeof(int), len);
	return (ret);
}

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
			ret = i;
		tmp = board.a[i];
		i++;
	}
	return (ret);
}

int	find_highest(int	*ar, int len)
{
	int	i;
	int	ret;

	i = 1;
	ret = 0;
	while (i < len)
	{
		if (ar[i] > ar[ret])
			ret = i;
		i++;
	}
	return (ret);
}

int	get_index(int	*ar, int value, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (ar[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	*find_lowers(t_board board, int size)
{
	int	*ret;
	int	i;
	int	j;
	int	count;
	int	p;

	if (board.len_a < size)
		size = board.len_a;
	ret = malloc(sizeof(int) * size);
	if (!ret)
		return (0);
	i = 0;
	p = 0;
	while (i < board.len_a)
	{
		j = 0;
		count = 0;
		while (j < board.len_a)
		{
			if (j != i && board.a[j] < board.a[i])
				count++;
			if (count >= size)
				break ;
			j++;
		}
		if (count < size)
		{
			ret[p] = board.a[i];
			p++;
		}
		i++;
	}
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

void	ft_printboard(t_board board)
{
	int	i;
	int	m;

	m = max(board.len_a, board.len_b);
	i = 0;
	while (i < m)
	{
		if (m - i <= board.len_a)
			ft_putnbr_fd(board.a[i - (m - board.len_a)], 1);
		else
			ft_putchar_fd('*', 1);
		ft_putchar_fd(' ', 1);
		if (m - i <= board.len_b)
			ft_putnbr_fd(board.b[i - (m - board.len_b)], 1);
		else
			ft_putchar_fd('*', 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putendl_fd("-----------", 1);
}
