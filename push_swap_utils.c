/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:50:40 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/22 17:14:00 by shalimi          ###   ########.fr       */
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

int	ar_contain(int *ar, int len, int contain)
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

int	abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}
