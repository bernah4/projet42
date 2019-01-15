/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:16:03 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/16 14:07:10 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*ret;
	unsigned long	lim;

	lim = 9223372036854775807;
	if (size > lim)
		return (NULL);
	if (!(ret = (void *)malloc(sizeof(*ret) * (size + 1))))
		return (NULL);
	ft_memset(ret, 0, size);
	return (ret);
}
