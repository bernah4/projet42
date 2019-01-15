/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:06:52 by hebernar          #+#    #+#             */
/*   Updated: 2018/12/13 15:36:12 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 5001
# include "libft/libft.h"

typedef struct		s_gnl
{
	int				fd;
	char			*str;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);
#endif
