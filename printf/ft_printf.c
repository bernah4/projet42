/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:15:00 by hebernar          #+#    #+#             */
/*   Updated: 2019/01/15 15:17:25 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** La chaine buf_spec contient tout les specifier
** afin de pouvoir ensuite tester l'apparition
** du specifier dans un token. Next_arg contient
** le prochain indice de l'arg a convertir.
** ret_pos contient l'indice de fin d'un token
** dans la chaine a analyser.
*/

void	ft_init_stct(t_pf *stct)
{
	stct->r_pos = 0;
	stct->valid = 1;
	stct->flag = 0;
	stct->width = 0;
	stct->precision = 0;
	stct->length = 0;
	stct->base = 0;
	stct->spec = '\0';
	stct->s_spec = ft_strnew(11);
	stct->s_spec = ft_strcpy(stct->s_spec, "diouxXcspfb");
}

/*
** Un token de conversion se termine toujours
** par un specifier -> check son apparition
** permet ainsi de determiner la fin du token
*/

int		ft_not_spec(char c, char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == c)
			return (0);
	}
	return (1);
}

void	ft_free_struct(t_pf *stct, char *ret)
{
	free(stct->s_spec);
	free(ret);
	free(stct);
}

void	ft_printf(char *str, ...)
{
	char	*ret;
	int		i;
	t_pf	*stct;
	va_list	ap;
	void	*tmp;

	i = 0;
	ft_init_stct(stct);
	va_start(ap, str);
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
			i++;
		ret = ft_realloc(ret, ft_strsub(str, stct->r_pos, i - stct->r_pos));
		if (str[i] == '%')
		{
			if (stct->valid == 1)
				tmp = va_arg(ap, void *);
			ret = ft_realloc(ret, ft_fill_stct(str, i, stct, tmp));
			i = stct->r_pos;
		}
	}
	va_end(ap);
	ft_putstr(ret);
	ft_free_struct(stct, ret);
}
