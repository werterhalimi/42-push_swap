/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:47:20 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/12 04:19:28 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_board
{
	int	len_a;
	int	len_b;
	int	*a;
	int	*b;
}	t_board;

t_board	new_board(int *input, int len);
void	finish(t_board board);
int		is_sorted(t_board board);
int		get_lower_index(t_board board);
t_board	parse(char *args);
#endif
