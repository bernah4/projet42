/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:26:11 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/19 15:25:46 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_size(int nb)
{
	int i;

	i = 2;
	while (i * i < nb * 4)
		i++;
	return (i);
}
