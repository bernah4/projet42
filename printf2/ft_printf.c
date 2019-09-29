/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 10:18:33 by hebernar          #+#    #+#             */
/*   Updated: 2019/09/28 16:36:00 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(char *str, ...)
{
	char	buf[BUFF_SIZE];
	t_pf	*stct;
	int		pos;
	va_list ap;

	pos = 0;
	if (!(stct = (t_pf*)malloc(sizeof(t_pf))))
		return ;
	va_start(ap, str);
	while (str[pos] != '\0')
	{
		if (str[pos] == '%')
		{
			copy_buf(buf, ft_strsub(str, stct->last_pos, pos - stct->last_pos));
			if (ft_valid_token(str, ++pos, stct, buf))
				copy_buf(buf, ft_create_output(stct, va_arg(ap, void *)));
			pos = stct->last_pos;
		}
		if (str[pos] != '\0')
			pos++;
	}
	copy_buf(buf, ft_strsub(str, stct->last_pos, pos - stct->last_pos));
	va_end(ap);
	ft_flush_buf(buf);
	ft_free_stct(stct);
}
