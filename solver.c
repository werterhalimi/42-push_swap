/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:06:34 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/22 16:50:45 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_step	*get_top_path(int len, int index, t_map map)
{
	t_step	*ret;
	char	*name;
	int		step;

	step = 0;
	if (len - index < index)
	{
		step = len - index;
		name = map.down;
	}
	else
	{
		step = index;
		name = map.up;
	}
	ret = ft_lstnew(name);
	while (step-- > 1)
		ft_lstadd_back(&ret, ft_lstnew(name));
	ft_lstadd_back(&ret, ft_lstnew(map.f));
	if (index == 0)
	{
		free(ret);
		return (ret->next);
	}
	return (ret);
}

void	do_step(t_board *board, t_step *step, int print)
{
	t_step	*tmp;

	while (step)
	{
		if (ft_strncmp(step->content, UP_B, ft_strlen(UP_B)) == 0)
			rb(board);
		if (ft_strncmp(step->content, DOWN_B, ft_strlen(DOWN_B)) == 0)
			rrb(board);
		if (ft_strncmp(step->content, UP, ft_strlen(UP)) == 0)
			ra(board);
		if (ft_strncmp(step->content, DOWN, ft_strlen(DOWN)) == 0)
			rra(board);
		if (ft_strncmp(step->content, ATOB, ft_strlen(ATOB)) == 0)
			push_b(board);
		if (ft_strncmp(step->content, BTOA, ft_strlen(BTOA)) == 0)
			push_a(board);
		board->no_step += 1;
		if (print)
			ft_putendl_fd(step->content, 1);
		tmp = step;
		step = step->next;
		free(tmp);
	}
}

int	redirect(int argc, char **argv, t_board *board)
{
	if (argc < 2)
		return (0);
	if (argc > 2)
		*board = parse_ar(argc, argv);
	else
		*board = parse(argv[1]);
	if (!is_uniq(*board))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	if (is_sorted(*board))
	{
		free(board->a);
		free(board->b);
		finish(*board);
		return (0);
	}
	if (board->len_a <= 3)
		solve_three(board);
	else if (board->len_a <= 5)
		solve_five(board);
	if (board->len_a <= 5)
		finish(*board);
	return (1);
}

int	str_has_digit(char *str)
{
	int	len;
	int	i;

	i = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	len = ft_strlen(str);
	while (str[i])
	{
		if ((str[i] != '-' || len == 1 || i != 0) && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if ((str[0] == ' ' || str[0] == '\t') && len == 1)
		return (0);
	return (1);
}
