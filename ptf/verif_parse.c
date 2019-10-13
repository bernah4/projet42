/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:19:02 by hebernar          #+#    #+#             */
/*   Updated: 2019/10/05 16:43:48 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_size(char *str, int pos, t_pf *stct)
{
	if (str[pos] == 'h' && str[pos + 1] == 'h' && stct->size % 10 == 0)
	{
		stct->size += 1;
		return (pos + 2);
	}
	if (str[pos] == 'h' && (stct->size / 10) % 10 == 0)
		stct->size += 10;
	if (str[pos] == 'l' && (stct->size / 100) % 10 == 0)
		stct->size += 100;
	if (str[pos] == 'l' && str[pos + 1] == 'l' && (stct->size / 1000) % 10 == 0)
	{
		stct->size += 1000;
		return (pos + 2);
	}
	if (str[pos] == 'L' && (stct->size / 10000) % 10 == 0)
		stct->size += 10000;
	return (pos + 1);
}

int		parse_indicator(char *str, int pos, t_pf *stct)
{
	if (str[pos] == ' ' && stct->indicator % 10 == 0)
		stct->indicator += 1;
	if (str[pos] == '+' && stct->indicator % 10 <= 1)
		stct->indicator += 2;
	if (str[pos] == '0' && (stct->indicator / 10) % 10 == 0)
		stct->indicator += 10;
	if (str[pos] == '-' && (stct->indicator / 10) % 10 <= 1)
		stct->indicator += 20;
	if (str[pos] == '#' && (stct->indicator / 100) % 10 == 0)
		stct->indicator += 100;
	return (pos + 1);
}

int		parse_precision(char *str, int pos, t_pf *stct)
{
	stct->precis = atoi(&str[pos]);
	while (is_number(str, pos))
		pos++;
	return (pos);
}

int		parse_length(char *str, int pos, t_pf *stct)
{
	stct->lenght = atoi(&str[pos]);
	while (is_number(str, pos))
		pos++;
	return (pos);
}

int		parse_type(char *str, int pos, t_pf *stct)
{
	stct->type = str[pos];
	if (stct->type == 'o')
	{
		stct->base = 8;
		if ((stct->indicator / 100) % 10 > 0)
			stct->size_indic = 1;
	}
	if (stct->type == 'x' || stct->type == 'X')
	{
		stct->base = 16;
		if ((stct->indicator / 100) % 10 > 0)
			stct->size_indic = 2;
	}
	return (pos + 1);
}
