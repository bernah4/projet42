/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 09:39:44 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/09 15:26:18 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *haystack, char const *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		if (needle[j] == haystack[i + j])
		{
			while ((needle[j] != '\0') && (haystack[i + j] == needle[j]))
			{
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
