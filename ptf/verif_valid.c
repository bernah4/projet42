/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verfi_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:18:36 by hebernar          #+#    #+#             */
/*   Updated: 2019/10/05 17:54:30 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Verify if the char at current pos is a type char that mean
** end of printf token
*/

int		ft_end_token(char *str, int pos)
{
	if (str[pos] == 'c')
		return (1);
	else if (str[pos] == 's')
		return (1);
	else if (str[pos] == 'p')
		return (1);
	else if (str[pos] == 'd')
		return (1);
	else if (str[pos] == 'i')
		return (1);
	else if (str[pos] == 'o')
		return (1);
	else if (str[pos] == 'u')
		return (1);
	else if (str[pos] == 'x')
		return (1);
	else if (str[pos] == 'X')
		return (1);
	else if (str[pos] == 'f')
		return (1);
	else
		return (0);
}

/*
** Check if the char at current pos is a valid char for the printf func
*/

int		ft_valid_char(char *str, int pos)
{
	if (token_letter(str, pos) || token_sign(str, pos) || is_number(str, pos))
		return (1);
	else
		return (0);
}

void	ft_percent(int pos, t_pf *stct, char *buf)
{
	stct->pos = pos + 1;
	copy_buf(buf, "%");
}

/*
** Check if the token is valid and parse token args into the structure
*/

int		ft_valid_token(char *str, int pos, t_pf *stct, char *buf)
{
	ft_init_stct(stct);
	stct->pos = pos;
	if (str[pos] == '%')
		ft_percent(pos, stct, buf);
	while (!ft_end_token(str, pos) && str[pos] != '\0')
	{
		if (!ft_valid_char(str, pos))
			return (0);
		if (token_letter(str, pos))
			pos = parse_size(str, pos, stct);
		else if ((token_sign(str, pos) && str[pos] != '.') || str[pos] == '0')
			pos = parse_indicator(str, pos, stct);
		else if (str[pos] == '.')
			pos = parse_precision(str, ++pos, stct);
		else if (is_number(str, pos))
			pos = parse_length(str, pos, stct);
	}
	if (ft_end_token(str, pos))
	{
		parse_type(str, pos, stct);
		stct->pos = pos + 1;
		return (1);
	}
	return (0);
}
