/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:49:01 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/14 14:21:32 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	size_t			i;
	void			*tmp;

	i = 0;
	tmp = dst;
	while (i < n)
	{
		*((unsigned char *)dst) = *((unsigned char *)src);
		i++;
		dst++;
		if (*((unsigned char *)src) == (unsigned char)c)
			return (dst);
		src++;
	}
	return (NULL);
}
