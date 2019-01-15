/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_tet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:17:43 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/19 15:54:00 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	transpo(char *s, t_tet *new, int i, int nb)
{
	new->coor[new->i] = nb;
	if (i + 1 < 21 && s[i + 1] == '#' && (nb % 100) < 10)
	{
		new->i = new->i + 1;
		transpo(s, new, i + 1, nb + 1);
	}
	if (i - 1 >= 0 && s[i - 1] == '#' && nb % 10 == 0)
	{
		new->i = new->i + 1;
		transpo(s, new, i - 1, nb + 10);
	}
	if (i + 5 < 21 && s[i + 5] == '#')
	{
		new->i = new->i + 1;
		transpo(s, new, i + 5, nb + 100);
	}
}

void	get_coor(char *s, t_tet *new)
{
	int i;

	i = 0;
	while (s[i] != '#')
		i++;
	new->i = 0;
	transpo(s, new, i, 0);
}

int		take_tet(char *s, t_tet **tet, int nb)
{
	t_tet	*new;
	t_tet	*last;

	if (!(new = (t_tet*)malloc(sizeof(t_tet))))
		return (-1);
	if (!(new->coor = (int*)malloc(sizeof(new->coor) * 4)))
		return (-1);
	new->p = nb;
	get_coor(s, new);
	new->next = NULL;
	if (*tet == NULL)
	{
		*tet = new;
		return (0);
	}
	last = *tet;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	return (0);
}
