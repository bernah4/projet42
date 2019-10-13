/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 10:18:33 by hebernar          #+#    #+#             */
/*   Updated: 2019/10/05 17:54:05 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> 

void	ft_printf(char const *format, ...)
{
	char	*buf;
	t_pf	*stct;
	int		pos;
	va_list ap;
	char *str;

	pos = 0;
	str = (char *)format;
	if (!(stct = (t_pf*)malloc(sizeof(t_pf))))
		exit(1);
	if (!(buf = ft_strnew(BUFF_SIZE)))
		exit(1);
	va_start(ap, format);
	while (str[pos] != '\0')
	{
		if (str[pos] == '%')
		{
			copy_buf(buf, ft_strsub(str, stct->pos, pos - stct->pos));
			if (ft_valid_token(str, ++pos, stct, buf))
				ft_type(stct, (void*)va_arg(ap, void *), buf);
			pos = stct->pos;
		}
		if (str[pos] != '\0')
			pos++;
	}
	copy_buf_last(buf, ft_strsub(str, stct->pos, pos - stct->pos), stct);
	va_end(ap);
}
