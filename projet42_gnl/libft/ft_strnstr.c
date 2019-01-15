/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:33:40 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/15 12:12:05 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str, char const *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		if (needle[j] == str[i + j])
		{
			while ((needle[j] != '\0') && (str[i + j] == needle[j]) &&
					i + j < len)
			{
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)&str[i]);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
