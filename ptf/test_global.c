/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:11:55 by hebernar          #+#    #+#             */
/*   Updated: 2019/10/05 17:45:02 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(int ac, char **av)
{
	char *str;
	char *str2;


	str = ft_strnew(40);
	str2 = ft_strnew(40);
	ft_strcat(str, "Printf dit:");
	ft_strcat(str2, "Ft_printf dit:");
	ft_strcat(str, av[1]);
	ft_strcat(str2, av[1]);
	if (ac)
	{}
	printf(str,atoi(av[2]));
	printf("\n");
	ft_printf(str2, atoi(av[2]));
	printf("\n");
	//printf("itoto: %s\n", itoa_sint(atoi(av[2]), stct));
		
	return (0);
}
