/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:23:36 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/24 19:24:15 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
