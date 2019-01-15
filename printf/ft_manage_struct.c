/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:08:23 by hebernar          #+#    #+#             */
/*   Updated: 2019/01/15 15:12:16 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_valid_token(char *str, int pos, char *buf)
{
	if (str[pos] == '-' || str[pos] == '+' || str[pos] == ' '
			|| str[pos] == '#' || str[pos] == '0')
		return (1);
	if (str[pos] == '.')
		return (3);
	if (str[pos] == 'h' || str[pos] == 'l' || str[pos] == 'L')
		return (2);
	if (str[pos] >= '1' && str[pos] <= '9')
		return (4);
	if (!ft_not_spec(str[pos], buf))
		return (5);
	return (0);
}

char	*ft_percent(t_pf *stct, int pos)
{
	char *ret;

	stct->valid = 0;
	if (!(ret = (char*)malloc(sizeof(*ret) * 2)))
		return (NULL);
	ret[0] = '%';
	ret[1] = '\0';
	stct->r_pos = pos;
	return (ret);
}

int		ft_check_percent(char *str, int pos)
{
	while (str[pos] == ' ')
		pos++;
	if (str[pos] == '%')
		return (++pos);
	return (0);
}

char	*ft_invalid_fill(char *str, int pos, t_pf *stct)
{
	int		i;
	char	*ret;

	stct->valid = 0;
	i = 0;
	while (str[pos + i] != '%' && str[i + pos] != '\0')
		i++;
	ret = ft_strnew(i);
	ret = ft_strsub(str, pos, i);
	return (ret);
}

char	*ft_fill_stct(char *str, int pos, t_pf *stct, void *tmp)
{
	int		curs;
	int		ret;

	curs = ++pos;
	ret = 1;
	if ((curs = ft_check_percent(str, curs)))
		return (ft_percent(stct, curs));
	curs = ++pos;
	while (ret < 5)
	{
		if (!(ret = ft_valid_token(str, curs, stct->s_spec)))
			return (ft_invalid_fill(str, pos, stct));
		if (ret == 1)
			curs = ft_flag(str, stct, curs);
		if (ret == 2)
			curs = ft_length(str, stct, curs);
		if (ret == 3)
			curs = ft_precision(str, stct, curs);
		if (ret == 4)
			curs = ft_width(str, stct, curs);
	}
	ft_base(str, stct, curs);
	stct->r_pos = ++curs;
	return (ft_transposition(stct, tmp));
}
