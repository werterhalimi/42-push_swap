/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:51:55 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/12 22:27:37 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_board	new_board(int *input, int len)
{
	t_board	ret;

	ret.len_a = len;
	ret.len_b = 0;
	ret.a = input;
	ret.b = ft_calloc(sizeof(int), len);
	return (ret);
}

//leaks
int	*find_lower(t_board board, int number)
{
	int	*ret;
	int	*tmp;
	int	i;
	int	j;

	i = 0;
	tmp = ft_calloc(sizeof(int), number);
	ret = ft_calloc(sizeof(int), number);
	if (!tmp || !ret)
		return (0);
	ft_arcpy(tmp, board.a, (size_t) number);
	while (i < board.len_a)
	{
		j = 0;
		while (j < number)
		{
			if (board.a[i] < tmp[j] && !ar_contain(tmp, number, board.a[i]))
			{
				tmp[j] = board.a[i];
				ret[j] = i;
				i = -1;
				break ;
			}
			j++;
		}
		i++;
	}
	free(tmp);
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
