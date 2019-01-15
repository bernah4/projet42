/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:36:34 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/14 12:09:19 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_size(long nb)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

static char	*ft_transpo(long nb, int size, int sign, char *ret)
{
	int i;

	i = 0;
	if (nb == 0)
		ret[0] = '0';
	while (nb > 0)
	{
		ret[size - 1 - i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	if (sign < 0)
		ret[0] = '-';
	ret[size] = '\0';
	return (ret);
}

char		*ft_itoa(int n)
{
	int		size;
	int		sign;
	long	z;
	char	*ret;

	size = 0;
	sign = 1;
	z = n;
	if (n < 0)
	{
		z = -z;
		sign = -1;
	}
	size = ft_size(z);
	if (z == 0)
		size++;
	if (sign < 0)
		size++;
	if (!(ret = (char *)malloc(sizeof(*ret) * (size + 1))))
		return (NULL);
	return (ft_transpo(z, size, sign, ret));
}
