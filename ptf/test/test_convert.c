/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:00:59 by hebernar          #+#    #+#             */
/*   Updated: 2019/09/29 16:28:51 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main()
{
	char a = 'a';
	void	*ret;

	ret = &a;

	printf("%%c :%c \n", *((char*)ret));
	printf("%%p :%p \n", ret);
	printf("%%x :%#-.20lx tutut \n", (unsigned long)ret);
	printf("%%s :%s \n", ret);
	printf("%%x :%#.3xtutut \n", 23);
	return (0);
}
