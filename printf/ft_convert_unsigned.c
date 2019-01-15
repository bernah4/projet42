/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:31:33 by hebernar          #+#    #+#             */
/*   Updated: 2019/01/15 15:27:01 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char			ft_val_touchar(void *elem)
{
	unsigned char c;

	c = *((unsigned char *)elem);
	return (c);
}

unsigned short int		ft_val_toushortint(void *elem)
{
	unsigned short int c;

	c = *((unsigned short int *)elem);
	return (c);
}

unsigned long int		ft_val_toulongint(void *elem)
{
	unsigned long int c;

	c = *((unsigned long int *)elem);
	return (c);
}

unsigned long long int	ft_val_toulonglongint(void *elem)
{
	unsigned long long int c;

	c = *((unsigned long long int *)elem);
	return (c);
}

unsigned int			ft_val_touint(void *elem)
{
	unsigned int c;

	c = *((unsigned int *)elem);
	return (c);
}
