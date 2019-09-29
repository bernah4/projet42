/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:55:40 by hebernar          #+#    #+#             */
/*   Updated: 2019/09/28 15:35:30 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(int ac, char **av)
{
	t_pf	*stct;
	char *buf;

	if (ac)
	{}
	buf=malloc(sizeof(char)*(30));
	stct=malloc(sizeof(t_pf));
	ft_init_stct(stct);
	int ret = ft_valid_token(av[1], 0, stct, buf);
	if (!ret)
		printf("Invalid token : %d\n", ret);
	if (ret)
		printf("token valid: %d\n", ret);
	
	printf("type: %c\n", stct->type);
	printf("size: %d\n", stct->size);
	printf("indicator: %d\n", stct->indicator);
	printf("lenght: %d\n", stct->lenght);
	printf("precis: %d\n", stct->precis);
	printf("base: %d\n", stct->base);
	printf("test : %c", (4%2 == 0 ? 'p': 'i'));
	free(stct);
	return (0);
}
