/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <shalimi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:31:08 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/24 19:01:18 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb, size_t len)
{
	void	*ret;
	int		i;

	i = 0;
	ret = malloc(len * nb);
	if (!ret)
		return (0);
	while (i < (int)(len * nb))
		((unsigned char *)ret)[i++] = 0;
	if (!ret)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	return (ret);
}
