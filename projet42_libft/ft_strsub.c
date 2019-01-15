/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:50:55 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/14 13:06:29 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(*ret) * (len + 1))))
		return (NULL);
	if (s != NULL)
	{
		while (i < len)
		{
			ret[i] = s[(size_t)start + i];
			i++;
		}
	}
	ret[i] = '\0';
	return (ret);
}
