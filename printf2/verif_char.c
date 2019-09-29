/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 12:13:03 by hebernar          #+#    #+#             */
/*   Updated: 2019/09/28 12:27:34 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		token_letter(char *str, int pos)
{
	if (str[pos] == 'h')
		return (1);
	else if (str[pos] == 'l')
		return (1);
	else if (str[pos] == 'L')
		return (1);
	else
		return (0);
}

int		token_sign(char *str, int pos)
{
	if (str[pos] == ' ')
		return (1);
	else if (str[pos] == '.')
		return (1);
	else if (str[pos] == '+')
		return (1);
	else if (str[pos] == '-')
		return (1);
	else if (str[pos] == '#')
		return (1);
	else
		return (0);
}

int		is_number(char *str, int pos)
{
	if (str[pos] >= '0' && str[pos] <= '9')
		return (1);
	return (0);
}
