/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:54:38 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/16 12:59:06 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	size_t			i;
	unsigned char	*dstn;
	unsigned char	*srcn;

	i = 0;
	dstn = (unsigned char *)dst;
	srcn = (unsigned char *)src;
	if (dstn < srcn)
	{
		while (i < len)
		{
			dstn[i] = srcn[i];
			i++;
		}
	}
	else if (srcn < dstn)
	{
		while (i < len)
		{
			dstn[len - 1 - i] = srcn[len - 1 - i];
			i++;
		}
	}
	return (dst);
}
