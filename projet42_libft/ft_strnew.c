/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:08:24 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/09 16:13:12 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(*ret) * (size + 1))))
		return (NULL);
	while (i <= size)
	{
		ret[i] = '\0';
		i++;
	}
	return (ret);
}
