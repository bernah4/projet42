/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:09:41 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/07 16:14:26 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#define BUFF_SIZE 42

void	ft_err(char c)
{
	write(2, &c, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str, int nb)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (nb == 2)
			ft_err(str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
}

void	ft_read(char *str)
{
	int		fd;
	int		lec;
	char	buf[BUFF_SIZE + 1];

	lec = 0;
	fd = open(str, O_RDONLY);
	while ((lec = read(fd, buf, BUFF_SIZE)))
	{
		buf[lec] = '\0';
		ft_putstr(buf, 1);
	}
	if (close(fd) == -1)
		ft_putstr("close failed !", 2);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_read(av[1]);
		return (0);
	}
	if (ac > 2)
		ft_putstr("Too many arguments.\n", 2);
	else
		ft_putstr("File name missing.\n", 2);
	return (0);
}
