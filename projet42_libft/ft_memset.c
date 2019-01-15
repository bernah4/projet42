/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:49:33 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/14 13:58:02 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	ch;
	void			*tmp;

	i = 0;
	tmp = b;
	ch = (unsigned char)c;
	while (i < len)
	{
		*((unsigned char *)b) = ch;
		i++;
		b++;
	}
	return (tmp);
}
