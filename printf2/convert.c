/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:14:21 by hebernar          #+#    #+#             */
/*   Updated: 2019/09/29 16:32:16 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_unsigned(t_pf *stct, void *input, char *buf)
{
	if (stct->size == 0 || stct->size > 1000)
		copy_buf(buf, itoa_uint(*((unsigned int*)input), stct->base));
	if (stct->size > 0 || stct->size < 10)
		copy_buf(buf, itoa_uchar(*((unsigned char*)input)));
	if (stct->size >= 10 || stct->size < 100)
		copy_buf(buf, itoa_ushort(*((unsigned short*)input)));
	if (stct->size >= 100 || stct->size < 1000)
		copy_buf(buf, itoa_ulong(*((unsigned long*)input)));
	if (stct->size >= 1000 || stct->size < 10000)
		copy_buf(buf, itoa_ulonglong(*((unsigned long long*)input)));
}

void	ft_convert_signed(t_pf *stct, void *input, char *buf)
{
	if (stct->size == 0 || stct->size > 1000)
		copy_buf(buf, itoa_int(*((int*)input)));
	if (stct->size > 0 || stct->size < 10)
		copy_buf(buf, itoa_char(*((char*)input)));
	if (stct->size >= 10 || stct->size < 100)
		copy_buf(buf, itoa_short(*((short*)input)));
	if (stct->size >= 100 || stct->size < 1000)
		copy_buf(buf, itoa_long(*((long*)input)));
	if (stct->size >= 1000 || stct->size < 10000)
		copy_buf(buf, itoa_longlong(*((long long*)input)));
}

/*
** This fucnction dispatch the input from variadic in a conversion function
** depanding of the conversion type from the printf token
*/

void	ft_type(t_pf *stct, void *input, char *buf)
{
	if (stct->type == 'o' || stct->type == 'u' || stct->type == 'x'
			|| stct->type == 'X')
		ft_convert_unsigned(stct, input, buf);
	if (stct->type == 'd' || stct->type == 'i')
		ft_convert_signed(stct, input, buf);
	if (stct->type == 'f')
		ft_convert_double(stct, input, buf);
	if (stct->type == 'c' || stct->type == 's')
		copy_buf(buf, ft_transform((char*)input, stct));
	if (stct->type == 'p')
		copy_buf(buf, itoa_ulong((unsigned long)input));
}
