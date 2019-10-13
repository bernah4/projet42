/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:36:55 by hebernar          #+#    #+#             */
/*   Updated: 2019/10/04 16:16:52 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_imax(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

void	ft_flush_buf(char *buf)
{
	ft_putstr(buf);
	ft_strclr(buf);
}

void	copy_buf(char *buf, char *str)
{
	if (BUFF_SIZE - ft_strlen(buf) < ft_strlen(str))
		ft_flush_buf(buf);
	ft_strcat(buf, str);
}

void	copy_buf_last(char *buf, char *str, t_pf *stct)
{
	if (BUFF_SIZE - ft_strlen(buf) < ft_strlen(str))
		ft_flush_buf(buf);
	ft_strcat(buf, str);
	ft_flush_buf(buf);
	free(stct);
}
