/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 02:29:30 by shai              #+#    #+#             */
/*   Updated: 2022/11/14 19:37:52 by shai             ###   ########.fr       */
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

void	push_b(t_board *board)
{
	ft_memmove(&board->b[1], &board->b[0], board->len_b);
	board->b[0] = board->a[0];

	//ft_memcpy(&board->b[1], board->b, board->len_b);
	//board->b[0] = board->a[0];
	ft_memmove(&board->a[0], &board->a[1], board->len_a - 1);
	board->len_a -= 1;
	board->len_b += 1;
}
