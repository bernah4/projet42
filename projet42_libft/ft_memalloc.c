/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:16:03 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/22 14:37:39 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*ret;

	if (!(ret = (void *)malloc(sizeof(*ret) * (size))))
		return (NULL);
	ft_memset(ret, 0, size);
	return (ret);
}
