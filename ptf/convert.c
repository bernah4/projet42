/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:14:21 by hebernar          #+#    #+#             */
/*   Updated: 2019/10/05 17:39:57 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h> 

void	ft_convert_unsigned(t_pf *stct, void *input, char *buf)
{
	if (stct->size > 0 && stct->size < 10)
		copy_buf(buf, itoa_uchar((unsigned char)input, stct));
	if (stct->size >= 10 && stct->size < 100)
		copy_buf(buf, itoa_ushort((unsigned short)input, stct));
	if (stct->size >= 100 && stct->size < 1000)
		copy_buf(buf, itoa_ulong((unsigned long)input, stct));
	if (stct->size >= 1000 && stct->size < 10000)
		copy_buf(buf, itoa_ulonglong((unsigned long long)input, stct));
	else	
		copy_buf(buf, itoa_uint((unsigned int)input, stct));
}

void	ft_convert_signed(t_pf *stct, void *input, char *buf)
{
	if (stct->size > 0 && stct->size < 10)
		copy_buf(buf, itoa_schar((char)input, stct));
	if (stct->size >= 10 && stct->size < 100)
		copy_buf(buf, itoa_sshort((short)input, stct));
	if (stct->size >= 100 && stct->size < 1000)
		copy_buf(buf, itoa_slong((long)input, stct));
	if (stct->size >= 1000 && stct->size < 10000)
		copy_buf(buf, itoa_slonglong((long long)input, stct));
	else
		copy_buf(buf, itoa_sint((int)input, stct));

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
/*	if (stct->type == 'f')
		//ft_convert_double(stct, input, buf);
	if (stct->type == 'c' || stct->type == 's')
		//copy_buf(buf, ft_transform((char*)input, stct));*/
	if (stct->type == 'p')
		copy_buf(buf, itoa_ulong((unsigned long)(&input), stct));
}
