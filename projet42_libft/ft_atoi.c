/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:42:21 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/14 15:29:42 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char const *str)
{
	int i;
	int s;
	int nb;

	i = 0;
	nb = 0;
	s = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	if ((str[i] >= '0') && (str[i] <= '9'))
	{
		while ((str[i] >= '0') && (str[i] <= '9'))
		{
			nb = nb * 10 + (str[i] - '0');
			i++;
		}
	}
	return (nb * s);
}
