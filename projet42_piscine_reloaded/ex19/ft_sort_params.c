/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:22:47 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/07 16:05:18 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort(int nbr, char **tab)
{
	char	*swap;
	int		i;

	i = 1;
	while (i < nbr - 1)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (i < ac)
	{
		ft_sort(ac, av);
		while (i < ac)
		{
			ft_putstr(av[i]);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
