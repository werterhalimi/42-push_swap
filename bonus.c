/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 05:27:20 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/25 05:45:42 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#ifdef BONUS

int	main(int argc, char **argv)
{
	t_step step;
	t_board board;
	char	*buff;
	int		len;

	if (argc != 2)
		ft_putendl_fd("Error", 2);
	board = parse(argv[1]);
	if (!is_uniq(board))
	{
		free(board.a);
		free(board.b);
		exit(1);
	}
	while (true)
	{
		len = read(0, buff, 3);
		if (len == 0)
			break;
		if (ft_strncmp(buff))
	}
}
#endif
