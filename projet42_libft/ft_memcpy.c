/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:58:27 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/14 14:11:38 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	size_t			i;
	void			*b;
	unsigned char	ch;

	i = 0;
	b = dst;
	while (i < n)
	{
		ch = *((unsigned char *)src);
		*((unsigned char *)dst) = ch;
		dst++;
		src++;
		i++;
	}
	return (b);
}
