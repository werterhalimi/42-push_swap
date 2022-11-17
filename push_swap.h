/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:47:20 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/17 01:44:36 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# define UP "ra"
# define DOWN "rra"
# define ATOB "pb"
# define BTOA "pa"
# define UP_B "rb"
# define DOWN_B "rrb"

typedef struct s_board
{
	int		len_a;
	int		len_b;
	int		*a;
	int		*b;
	t_list	*step;
	int		no_step;
}	t_board;

typedef struct s_map
{
	char	*up;
	char	*down;
	char	*f;
}	t_map;

typedef t_list	t_step;

t_board	new_board(int *input, int len);
void	finish(t_board board);
int		is_sorted(t_board board);
int		get_lower_index(t_board board);
t_board	parse(char *args);
t_board	parse_ar(int argc, char **argv);
int		is_uniq(t_board board);
int		find_lower(t_board board);
int		*find_lowers(t_board board, int size);
t_step	*get_top_path(int len, int index, t_map map);
int		ar_contain(int	*ar, int len, int contain);
void	print_steps(t_board board);
void	*ft_arcpy(int *dest, int *src, size_t n);
void	ft_printboard(t_board board);
int		abs(int i);
int		max(int a, int b);
void	push_b(t_board *board);
void	push_a(t_board *board);
void	ra(t_board *board);
void	rra(t_board *board);
void	rrb(t_board *board);
void	rb(t_board *board);
void	do_step(t_board *board, t_step *step, int print);
int		*sort(int	*ar, int len);
int		find_highest(int *ar, int len);
int		get_index(int	*ar, int value, int len);
int		find_lower_ar(int *a, int len_a);
void	append_board_step(t_board *board, t_step step);
#endif
