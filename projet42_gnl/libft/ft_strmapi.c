/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:30:04 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/14 12:56:47 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	char			*ret;

	ret = NULL;
	if (s != NULL)
	{
		size = (unsigned int)ft_strlen(s);
		if (!(ret = (char *)malloc(sizeof(*ret) * (size + 1))))
			return (NULL);
		size = 0;
		while (s[size] != '\0')
		{
			ret[size] = (f)(size, s[size]);
			size++;
		}
		ret[size] = '\0';
	}
	return (ret);
}
