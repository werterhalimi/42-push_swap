/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:06:34 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/12 18:36:22 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_arcpy(int *dest, int *src, size_t n)
{
	size_t	i;

	if (dest == src)
		return (dest);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	ar_contain(int	*ar, int len, int contain)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (ar[i] == contain)
			return (1);
		i++;
	}
	return (0);
}

int	*find_lower(t_board board, int number)
{
	int	*ret;
	int	i;
	int	j;

	i = 0;
	ret = ft_calloc(sizeof(int), number);
	if (!ret)
		return (0);
	ft_arcpy(ret, board.a, (size_t) number);
	while (i < board.len_a)
	{
		j = 0;
		while (j < number)
		{
			if (board.a[i] < ret[j] && !ar_contain(ret, number, board.a[i]))
			{
				ret[j] = board.a[i];
				i = -1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (ret);
}
