/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:13:18 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/17 01:46:01 by shalimi          ###   ########.fr       */
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

int	*ft_stois(char *args, int *len, char **values)
{
	int		*ret;
	int		i;

	i = 0;
	if (!values)
	{
		values = ft_split(args, ' ');
		*len = count_char(args, ' ');
	}
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

t_board	parse_ar(int argc, char **argv)
{
	t_board	ret;
	int		*a;

	argc--;
	argv++;
	a = ft_stois(0, &argc, argv);
	ret = new_board(a, argc);
	return (ret);
}

t_board	parse(char *args)
{
	t_board	ret;
	int		len;
	int		*a;

	a = ft_stois(args, &len, 0);
	ret = new_board(a, len);
	return (ret);
}

int	is_uniq(t_board board)
{
	int	i;
	int	j;

	i = 0;
	while (i < board.len_a)
	{
		j = 0;
		while (j < board.len_a && j != i)
		{
			if (board.a[i] == board.a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
