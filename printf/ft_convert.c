/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:29:04 by hebernar          #+#    #+#             */
/*   Updated: 2019/01/15 15:11:13 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int			ft_convert_signed(t_pf *stct, void *elem)
{
	if (stct->length % 5 == 1)
		stct->length--;
	if (stct->length == 10)
		return (ft_val_tochar(elem));
	if (stct->length == 15)
		return (ft_val_toshortint(elem));
	if (stct->length == 35)
		return (ft_val_tolongint(elem));
	if (stct->length == 40)
		return (ft_val_tolonglongint(elem));
	if (stct->length == 0)
		return (ft_val_toint(elem));
}

unsigned long long int	ft_convert_unsigned(t_pf *stct, void *elem)
{
	if (stct->length % 5 == 1)
		stct->length--;
	if (stct->length == 10)
		return (ft_val_touchar(elem));
	if (stct->length == 15)
		return (ft_val_toushortint(elem));
	if (stct->length == 35)
		return (ft_val_toulongint(elem));
	if (stct->length == 40)
		return (ft_val_toulonglongint(elem));
	if (stct->length == 0)
		return (ft_val_touint(elem));
}

long double				ft_convert_double(t_pf *stct, void *elem)
{
	if (stct->length % 5 == 1)
		return (ft_val_tolongdouble(elem));
	if (stct->length == 35)
		return (ft_val_tolongdouble(elem));
	else
		return (ft_val_todouble(elem));
}
