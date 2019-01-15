/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:26:55 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/13 14:25:59 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		size;
	char	*ret;

	ret = NULL;
	if (s != NULL)
	{
		size = ft_strlen(s);
		if (!(ret = (char *)malloc(sizeof(*ret) * (size + 1))))
			return (NULL);
		size = 0;
		while (s[size] != '\0')
		{
			ret[size] = (f)(s[size]);
			size++;
		}
		ret[size] = '\0';
	}
	return (ret);
}
