/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:13:18 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/24 19:05:13 by shalimi          ###   ########.fr       */
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

int	*ft_stois(int *len, char **values)
{
	int		*ret;
	int		i;
	int		j;

	i = 0;
	ret = ft_calloc(sizeof(int), *len);
	while (i < *len)
	{
		j = 0;
		while (j < (int) ft_strlen(values[i]))
		{
			if (values[i][j] == '-' && ft_isdigit(values[i][j + 1])
				&& (j == 0 || values[i][j - 1] == ' '))
				j++;
			else if (!ft_isdigit(values[i][j++]))
				error();
		}
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
	a = ft_stois(&argc, argv);
	ret = new_board(a, argc);
	return (ret);
}

t_board	parse(char *args)
{
	t_board	ret;
	int		len;
	int		*a;
	char	**values;

	if (count_char(args, ' ') == 1 && str_has_digit(args))
		exit(0);
	values = ft_split(args, ' ');
	len = count_char(args, ' ');
	a = ft_stois(&len, values);
	ret = new_board(a, len);
	free(values);
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
