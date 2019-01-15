/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:33:26 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/22 12:55:42 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		n;
	int		temp;

	n = ft_strlen(str);
	i = 0;
	while (i < (n / 2))
	{
		temp = str[i];
		str[i] = str[n - 1 - i];
		str[n - 1 - i] = temp;
		i++;
	}
	return (str);
}
