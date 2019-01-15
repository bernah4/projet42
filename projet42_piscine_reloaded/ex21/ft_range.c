/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:40:42 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/07 16:12:55 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int i;

	i = 0;
	if (max - min <= 0)
		return (NULL);
	tab = (int *)malloc(sizeof(*tab) * (max - min));
	if (!tab)
		return (NULL);
	while (i < max - min)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
