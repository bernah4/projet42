/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:33:21 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/14 13:01:55 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t') && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (0);
	i--;
	while (str[j] != '\0')
		j++;
	j--;
	while (str[j] == ' ' || str[j] == '\n'
			|| str[j] == '\t')
		j--;
	return (j - i);
}

static char	*ft_transpo(int size, char *ret, char const *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while ((str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t') && str[i] != '\0')
		i++;
	while (nb < size)
	{
		ret[nb] = str[i + nb];
		nb++;
	}
	ret[nb] = '\0';
	return (ret);
}

char		*ft_strtrim(char const *s)
{
	int		size;
	char	*ret;

	size = 0;
	if (s == NULL)
		return (NULL);
	size = ft_count(s);
	if (*s == '\0')
		size = 0;
	if (size < 0)
		return (NULL);
	if (!(ret = (char*)malloc(sizeof(*ret) * (size + 1))))
		return (NULL);
	return (ft_transpo(size, ret, s));
}
