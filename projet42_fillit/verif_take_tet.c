/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_tet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:17:43 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/19 16:04:55 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_tet1(char *s, int i)
{
	int c;

	c = 0;
	if (s[i] == '#')
	{
		if (i - 1 >= 0 && s[i - 1] == '#')
			c++;
		if (i + 1 < 21 && s[i + 1] == '#')
			c++;
		if (i - 5 >= 0 && s[i - 5] == '#')
			c++;
		if (i + 5 < 21 && s[i + 5] == '#')
			c++;
	}
	return (c);
}

int		check_tet(char *s)
{
	int i;
	int k;
	int c;

	i = 0;
	k = 0;
	c = 0;
	if (s[4] != '\n' || s[9] != '\n' || s[14] != '\n' || s[19] != '\n')
		return (-1);
	if (s[20] != '\n' && s[20] != '\0')
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] != '.' && s[i] != '#' && s[i] != '\n')
			return (-1);
		if (s[i] == '#')
		{
			c = c + check_tet1(s, i);
			k++;
		}
		i++;
	}
	if (k != 4 || c < 6)
		return (-1);
	return (0);
}

int		check_tet2(char *s)
{
	int i;
	int t;

	t = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			t++;
		i++;
	}
	return (t);
}

int		check_tet3(int sum, char *s, int *t, int *nb)
{
	int b;

	b = 0;
	if (sum > 545)
		b = -1;
	if (check_tet(s) == -1)
		b = -1;
	*t = *t + check_tet2(s);
	(*nb)++;
	return (b);
}

int		verif_take_tet(const int fd, t_tet **tet)
{
	int		ret;
	int		sum;
	char	s[22];
	int		nb;
	int		t;

	if ((ret = read(fd, NULL, 0)) == -1)
		return (-1);
	nb = 0;
	sum = 0;
	t = 0;
	while ((ret = read(fd, s, 21)) > 0)
	{
		if (ret < 1)
			return (-1);
		s[ret] = '\0';
		sum = sum + ret;
		if (check_tet3(sum, s, &t, &nb) == -1)
			return (-1);
		if (take_tet(s, tet, nb) == -1)
			return (-1);
	}
	if (t == nb)
		return (-1);
	return (nb);
}
