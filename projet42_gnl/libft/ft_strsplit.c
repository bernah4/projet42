/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:33:33 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/16 13:01:53 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_size(char const *s, int pos, char c)
{
	int size;

	size = 0;
	while (s[pos + size] != c)
		size++;
	return (size - 1);
}

static int	ft_find_nextpos(char const *s, int pos, char c)
{
	while (s[pos] != c && s[pos] != '\0')
		pos++;
	while (s[pos] == c && s[pos] != '\0')
		pos++;
	return (pos);
}

static char	*ft_putwords_intab(int pos, char const *s, char c)
{
	int		size;
	char	*word;

	size = ft_word_size(s, pos, c);
	if (!(word = (char *)malloc(sizeof(*word) * (size + 1))))
		return (NULL);
	size = 0;
	while (s[pos + size] != c)
	{
		word[size] = (char)s[pos + size];
		size++;
	}
	word[size] = '\0';
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	int		nbr;
	int		pos;
	int		i;
	char	**tab;

	nbr = ft_count_words(s, c);
	pos = 0;
	i = 0;
	if (!(tab = (char **)malloc(sizeof(*tab) * (nbr + 1))))
		return (NULL);
	if (s != NULL)
	{
		while (s[pos] == c && s[pos] != '\0')
			pos++;
		while (i < nbr)
		{
			tab[i] = ft_putwords_intab(pos, s, c);
			pos = ft_find_nextpos(s, pos, c);
			i++;
		}
	}
	tab[i] = 0;
	return (tab);
}
