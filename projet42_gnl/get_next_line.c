/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 10:42:25 by hebernar          #+#    #+#             */
/*   Updated: 2018/12/13 15:40:03 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *str, char *buf)
{
	char	*ret;
	int		ns;

	ns = 0;
	if (str)
		ns = ft_strlen(str);
	ret = (char *)ft_memalloc(ns + ft_strlen(buf) + 1);
	if (str)
	{
		ft_strcpy(ret, str);
		free(str);
	}
	ft_strcat(ret, buf);
	return (ret);
}

char	*ft_return_line(char *str, char **line)
{
	size_t i;
	size_t j;
	size_t ok;

	i = 0;
	j = 0;
	ok = 0;
	if (str[0] == '\0')
		i = -1;
	while (str[j] != '\0')
	{
		if (str[j] == '\n' && ok == 0)
		{
			i = j;
			ok = 1;
		}
		j++;
	}
	if (i == 0 && str[i] != '\n')
		i = ft_strlen(str);
	*line = ft_strsub(str, 0, i);
	if (i == ft_strlen(str))
		i--;
	ft_memmove(str, str + i + 1, ft_strlen(str) - i);
	return (str);
}

t_gnl	*ft_new_elem(t_gnl **list, const int fd)
{
	t_gnl *elem;
	t_gnl *tmp;

	tmp = NULL;
	if (!(elem = (t_gnl*)malloc(sizeof(*elem))))
		return (NULL);
	elem->fd = fd;
	if (!(elem->str = (char*)malloc(sizeof(char*) * 1)))
		return (NULL);
	elem->str[0] = '\0';
	elem->next = NULL;
	if (*list != NULL)
	{
		tmp = *list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = elem;
	}
	else
		*list = elem;
	return (elem);
}

t_gnl	*ft_find_list(t_gnl **list, const int fd)
{
	t_gnl	*tmp;

	tmp = NULL;
	if (list != NULL)
	{
		if (*list != NULL)
		{
			tmp = *list;
			while (tmp->next != NULL)
			{
				if (tmp->fd == fd)
					return (tmp);
				tmp = tmp->next;
			}
			if (tmp->fd == fd)
				return (tmp);
		}
	}
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	char			*buf;
	int				ret;
	t_gnl			*elem;
	static t_gnl	*list;

	if (!(elem = ft_find_list(&list, fd)))
		elem = ft_new_elem(&list, fd);
	buf = ft_memalloc(BUFF_SIZE + 1);
	if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	while (ret)
	{
		buf[ret] = '\0';
		elem->str = ft_realloc(elem->str, buf);
		if (ft_strlen(buf) < 5000)
			buf = ft_realloc(buf, buf);
		ret = read(fd, buf, BUFF_SIZE * (ft_strlen(buf) / BUFF_SIZE));
	}
	free(buf);
	if (elem->str[0] == '\0')
		return (0);
	elem->str = ft_return_line(elem->str, line);
	return (1);
}
