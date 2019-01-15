/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_signed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:26:51 by hebernar          #+#    #+#             */
/*   Updated: 2019/01/15 15:09:31 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			ft_val_tochar(void *elem)
{
	char c;

	c = *((char *)elem);
	return (c);
}

short int		ft_val_toshortint(void *elem)
{
	short int c;

	c = *((short int *)elem);
	return (c);
}

long int		ft_val_tolongint(void *elem)
{
	long int c;

	c = *((long int *)elem);
	return (c);
}

long long int	ft_val_tolonglongint(void *elem)
{
	long long int c;

	c = *((long long int *)elem);
	return (c);
}

int				ft_val_toint(void *elem)
{
	int c;

	c = *((int *)elem);
	return (c);
}
