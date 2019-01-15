/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:22:43 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/14 13:21:21 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putinto(char *ret, char const *src, int indice)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		ret[i + indice] = src[i];
		i++;
	}
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (s1 != NULL)
		i = ft_strlen(s1);
	if (s2 != NULL)
		j = ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(*ret) * (i + j + 1))))
		return (NULL);
	if (s1 != NULL)
		ft_putinto(ret, s1, 0);
	if (s2 != NULL)
		ft_putinto(ret, s2, i);
	ret[i + j] = '\0';
	return (ret);
}
