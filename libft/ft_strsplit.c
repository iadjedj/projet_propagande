/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:28:36 by iadjedj           #+#    #+#             */
/*   Updated: 2015/01/03 16:56:28 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (ft_strchr(s, c) == NULL)
		return (1);
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				i++;
				if (s[i] == '\0')
					return (count + 1);
			}
			count++;
		}
		i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**tab;
	char			*buf;
	unsigned int	i;
	int				k;
	int				nb_word;

	if (!s)
		return (NULL);
	buf = (char*)s;
	nb_word = ft_count_word(s, c);
	tab = malloc(sizeof(char *) * (nb_word + 1));
	k = -1;
	while (++k < nb_word && *buf != '\0' && tab != NULL)
	{
		while (*buf && *buf == c)
			buf++;
		i = 0;
		while (buf[i] && buf[i] != c)
			i++;
		tab[k] = ft_strndup(buf, i);
		while (*buf && *buf != c)
			buf++;
	}
	tab[k] = NULL;
	return (tab);
}
