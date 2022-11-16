/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 02:29:30 by shai              #+#    #+#             */
/*   Updated: 2022/11/16 17:23:25 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_board *board)
{
	int	tmp;
	int	i;
	
	i = 1;
	tmp = board->b[0];
	while (i < board->len_b)
	{
		board->b[i - 1] = board->b[i];
		i++;
	}
	board->b[i - 1] = tmp;
}

void	rrb(t_board *board)
{
	int	tmp;
	int	i;
	
	i = board->len_b - 1;
	tmp = board->b[board->len_b - 1];
	while (i >= 1)
	{
		board->b[i] = board->b[i - 1];
		i--;
	}
	board->b[0] = tmp;
}


void	rra(t_board *board)
{
	int	tmp;
	int	i;
	
	i = board->len_a - 1;
	tmp = board->a[board->len_a - 1];
	while (i >= 1)
	{
		board->a[i] = board->a[i - 1];
		i--;
	}
	board->a[0] = tmp;
}


void	ra(t_board *board)
{
	int	tmp;
	int	i;
	
	i = 1;
	tmp = board->a[0];
	while (i < board->len_a)
	{
		board->a[i - 1] = board->a[i];
		i++;
	}
	board->a[i - 1] = tmp;
}

void	push_a(t_board *board)
{
	int	tmp;
	int	i;
	int	*a;
	int	*b;

	a = board->a;
	b = board->b;
	i = 1;
	tmp = board->b[0];
	while (i < board->len_b)
	{
		b[i - 1] = b[i];
		i++;
	}
	i = board->len_a - 1;
	while (i >= 0)
	{
		a[i + 1] = a[i];
		i--;
	}
	a[0] = tmp;
	board->len_b -= 1;
	board->len_a += 1;
}

void	push_b(t_board *board)
{
	int	tmp;
	int	i;
	int	*a;
	int	*b;

	a = board->a;
	b = board->b;
	i = 1;
	tmp = board->a[0];
	while (i < board->len_a)
	{
		a[i - 1] = a[i];
		i++;
	}
	i = board->len_b - 1;
	while (i >= 0)
	{
		b[i + 1] = b[i];
		i--;
	}
	b[0] = tmp;
	board->len_a -= 1;
	board->len_b += 1;
}
