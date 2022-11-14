/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:47:20 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/14 19:38:09 by shai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# define UP "ra"
# define DOWN "rra"
# define ATOB "pb"
# define BTOA "pa"

typedef struct s_board
{
	int		len_a;
	int		len_b;
	int		*a;
	int		*b;
	t_list	*step;
}	t_board;

typedef t_list	t_step;

t_board	new_board(int *input, int len);
void	finish(t_board board);
int		is_sorted(t_board board);
int		get_lower_index(t_board board);
t_board	parse(char *args);
int		is_uniq(t_board board);
int		*find_lower(t_board board, int number);
t_step	*get_top_path(t_board board, int index);
int		ar_contain(int	*ar, int len, int contain);
void	print_steps(t_board board);
void	*ft_arcpy(int *dest, int *src, size_t n);
void	ft_printboard(t_board board);
int	abs(int i);
int	max(int a, int b);
void	push_b(t_board *board);
void 	ra(t_board *board);
void 	rb(t_board *board);
#endif
