/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:00:10 by hebernar          #+#    #+#             */
/*   Updated: 2019/01/15 15:13:54 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double		ft_val_tolongdouble(void *elem)
{
	long double c;

	c = *((long double *)elem);
	return (c);
}

double			ft_val_todouble(void *elem)
{
	double c;

	c = *((double *)elem);
	return (c);
}
