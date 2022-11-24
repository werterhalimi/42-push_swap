/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:31:02 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/22 16:14:20 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	ret;
	int			i;

	ret = 0;
	i = 1;
	while ((*str >= 10 && *str <= 13) || *str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		ret = ret * 10 + (*str - 48);
		str++;
	}
	if (ret < -2147483648 || ret > 2147483647)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	return ((int)ret * i);
}
