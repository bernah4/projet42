/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_itoa_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:25:35 by hebernar          #+#    #+#             */
/*   Updated: 2019/09/29 16:31:49 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

static int		ft_size(unsigned int nb, int base)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb = nb / base;
	}
	return (i);
}

static char		*ft_end(unsigned int nb, char *ret, t_pf *stct, int i)
{
	int k;

	k = 0;
	if (nb == 0)
		ret[i] = '0';
	while (nb > 0)
	{
		ret[i + stct->size_ret - 1 - k] = nb % stct->base +
			(nb % stct->base < 10 ? '0' : 'a' - 10);
		nb = nb / stct->base;
		k++;
	}
	i += stct->size_ret;
	while (i < stct->max)
	{
		ret[i] = ' ';
		i++;
	}
	ret[stct->max] = '\0';
	return (ret);
}

static char		*ft_begin(unsigned int nb, char *ret, t_pf *stct)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if ((stct->indicator / 10) % 10 < 2)
	{
		while (i < stct->lenght - ft_max(stct->precis, stct->size_ret)
				- stct->size_indic)
		{
			if ((stct->indicator / 10) % 10 > 0 && stct->precis == -1)
				ret[i] = '0';
			else
				ret[i] = ' ';
			i++;
		}
	}
	if (stct->precis > stct->size_ret)
	{
		while (j < stct->precis - stct->size_ret)
		{
			ret[i + j] = '0';
			j++;
		}
	}
	return (ft_end(nb, ret, stct, i + j));
}

char			*itoa_uint(unsigned int nb, t_pf *stct)
{
	char	*ret;

	stct->size_ret = ft_size(nb, stct->base);
	if (nb == 0)
		stct->size_ret++;
	stct->max = ft_max(ft_max(stct->lenght - stct->size_indic, stct->precis),
			stct->size_ret);
	if (!(ret = (char *)malloc(sizeof(*ret) * (stct->max + stct->size_indic
						+ 1))))
		return (NULL);
	return (ft_begin(nb, ret, stct));
}
