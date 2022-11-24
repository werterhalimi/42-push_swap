/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:09:51 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/24 19:11:41 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish(t_board board)
{
	free(board.a);
	free(board.b);
	exit(0);
}

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}
