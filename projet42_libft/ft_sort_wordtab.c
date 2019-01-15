/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:10:51 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/22 12:55:19 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_wordtab(char **tab)
{
	int		i;
	int		j;
	int		k;
	char	*swap;

	i = 0;
	j = 0;
	k = 0;
	while (tab[i] != 0)
		i++;
	while (k < i - 1)
	{
		while (j < i - 1)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				swap = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = swap;
			}
			j++;
		}
		j = 0;
		k++;
	}
}
