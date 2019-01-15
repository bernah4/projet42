/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:57:02 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/13 15:51:43 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	while (i < n)
	{
		a = (unsigned char *)s;
		if ((unsigned char)*a == (unsigned char)c)
			return ((void *)s);
		i++;
		s++;
	}
	return (NULL);
}
