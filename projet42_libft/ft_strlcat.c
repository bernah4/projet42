/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 11:46:45 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/13 16:15:48 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (size > 0)
	{
		while ((dst[i] != '\0') && (i < size))
			i++;
		while ((src[j] != '\0') && (i + j < size - 1))
		{
			dst[i + j] = (char)src[j];
			j++;
		}
		if (i + j < size)
			dst[i + j] = '\0';
	}
	return (i + (size_t)ft_strlen(src));
}
