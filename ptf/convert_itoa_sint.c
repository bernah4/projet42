/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_itoa_sint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:50:09 by hebernar          #+#    #+#             */
/*   Updated: 2019/10/04 15:34:01 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	while (i < stct->max + stct->size_indic)
	{
		ret[i] = ' ';
		i++;
	}
	ret[stct->max + stct->size_indic] = '\0';
	return (ret);
}

static char		*ft_middle(unsigned int nb, char *ret, t_pf *stct, int i)
{
	int j;

	j = 0;
	if (stct->indicator % 10 > 0)
	{
		if (stct->type == 'u' || stct->type == 'd')
		{
			if (stct->sign == 0 && stct->indicator % 10 == 1)
				ret[i] = ' ';
			if (stct->sign == 0 && stct->indicator % 10 > 1)
				ret[i] = '+';
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

static char		*ft_begin(unsigned int nb, char *ret, t_pf *stct, int i)
{
	if ((stct->indicator / 10) % 10 < 2)
	{
		while (i < stct->lenght - ft_imax(stct->precis, stct->size_ret)
				- stct->size_indic)
		{
			if ((stct->indicator / 10) % 10 > 0 && stct->precis == -1)
				ret[i] = '0';
			else
				ret[i] = ' ';
			i++;
		}
	}
	if (stct->sign < 0)
	{
		ret[i] = '-';
		i++;
	}
	return (ft_middle(nb, ret, stct, i));
}

char			*itoa_sint(int nb, t_pf *stct)
{
	char			*ret;
	int				i;
	unsigned int	u;

	i = 0;
	if (nb >= 0)
		u = nb;
	if (nb < 0)
	{
		u = -nb;
		stct->sign = -1;
	}
	stct->size_ret = ft_size(u, stct->base);
	if (nb == 0)
		stct->size_ret++;
	if (stct->sign < 0 || stct->indicator % 10 > 0)
		stct->size_indic++;
	stct->max = ft_imax(ft_imax(stct->lenght - stct->size_indic, stct->precis),
			stct->size_ret);
	if (!(ret = (char *)malloc(sizeof(*ret) * (stct->max + stct->size_indic
						+ 1))))
		return (NULL);
	return (ft_begin(u, ret, stct, i));
}
