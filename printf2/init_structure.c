/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 10:43:59 by hebernar          #+#    #+#             */
/*   Updated: 2019/09/29 16:26:24 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_stct(t_pf *stct)
{
	stct->type = 'z';
	stct->size = 0;
	stct->indicator = 0;
	stct->lenght = 0;
	stct->precis = -1;
	stct->base = 10;
	stct->max = 0;
	stct->size_ret = 0;
	stct->size_indic = 0;
	stct->last_pos = 0;
}
