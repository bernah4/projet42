/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:20:13 by hebernar          #+#    #+#             */
/*   Updated: 2019/01/11 15:18:43 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag(char *str, t_pf *stct, int pos)
{
	while (str[pos] == '#' || str[pos] == '0' || str[pos] == ' '
			|| str[pos] == '+' || str[pos] == '-')
	{
		if (str[pos] == '#' && stct->flag - 1111 <= 0)
			stct->flag = stct->flag + 10000;
		if (str[pos] == '0' && stct->flag - 10111 <= 0)
			stct->flag = stct->flag + 1000;
		if (str[pos] == ' ' && stct->flag - 11011 <= 0)
			stct->flag = stct->flag + 100;
		if (str[pos] == '+' && stct->flag - 11101 <= 0)
			stct->flag = stct->flag + 10;
		if (str[pos] == '-' && stct->flag - 11110 <= 0)
			stct->flag = stct->flag + 1;
		pos++;
	}
	return (pos);
}

int		ft_width(char *str, t_pf *stct, int pos)
{
	if (str[pos] >= '1' && str[pos] <= '9')
	{
		stct->width = ft_atoi(str + pos);
		while (str[pos] >= '0' && str[pos] <= '9')
			pos++;
	}
	return (pos);
}

int		ft_precision(char *str, t_pf *stct, int pos)
{
	if (str[pos] == '.')
	{
		pos++;
		stct->precision = ft_atoi(str + pos);
		while (str[pos] >= '0' && str[pos] <= '9')
			pos++;
	}
	return (pos);
}

int		ft_length(char *str, t_pf *stct, int pos)
{
	if (str[pos] == 'h' || str[pos] == 'l' || str[pos] == 'L')
	{
		if (str[pos] == 'L' && stct->length % 5 == 0)
			stct->length = stct->length + 1;
		if (str[pos] == 'h' && stct->lengh < 15)
			stct->length = 15;
		if (str[pos] == 'l' && stct->lengh < 35)
			stct->length = 35;
		if (str[pos + 1] == 'h' && str[pos] == 'h' && stct->lengh < 10)
			stct->length = 10;
		if (str[pos + 1] == 'l' && str[pos] == 'l' && stct->lengh < 40)
			stct->length = 40;
		if (stct->length % 2 == 0)
			pos++;
	}
	pos++;
	return (pos);
}

void	ft_base(char *str, t_pf *stct, int pos)
{
	if (str[pos] == 'd' || str[pos] == 'i'
			|| str[pos] == 'u' || str[pos] == 'f')
		stct->base = 10;
	if (str[pos] == 'o')
		stct->base = 8;
	if (str[pos] == 'x' || str[pos] == 'X' || str[pos] == 'p')
		stct->base = 16;
	if (str[pos] == 'b')
		stct->base = 2;
	stct->spec = str[pos];
}
