/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:13:18 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/12 04:20:18 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_char(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	str = ft_strtrim(str, " ");
	while (str[i])
	{
		if (str[i] == c)
		{
			count++;
			while (str[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	free(str);
	return (count + 1);
}

int	*ft_stois(char *args, int *len)
{
	int		*ret;
	char	**values;
	int		i;

	i = 0;
	values = ft_split(args, ' ');
	*len = count_char(args, ' ');
	ret = ft_calloc(sizeof(int), *len);
	if (!ret)
		return (0);
	while (i < *len)
	{
		ret[i] = ft_atoi(values[i]);
		i++;
	}
	return (ret);
}

t_board	parse(char *args)
{
	t_board	ret;
	int		len;
	int		*a;

	a = ft_stois(args, &len);
	ret = new_board(a, len);
	return (ret);
}
