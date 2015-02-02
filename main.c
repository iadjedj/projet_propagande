/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:06:11 by iadjedj           #+#    #+#             */
/*   Updated: 2015/02/02 17:24:13 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "dico.c"

#define MAX_WORD_LEN 15

char	*get_word(char *word)
{
	int		i;

	i = 0;
	while (DICO[i] != NULL &&
			ft_strncmp(DICO[i], word, ft_strlen(word)) != 0)
		i++;
	if (DICO[i] == NULL)
		return (NULL);
	else
		return (DICO[i] + ft_strlen(word) + 1);
}

char		*find_syn(char *word)
{
	char			*tmp;
	char			**syn;
	int				i;

	if (!(tmp = get_word(word)))
		return (NULL);
	syn = ft_strsplit(tmp, ' ');
	i = 0;
	while (syn && syn[i])
	{
		if (ft_strlen(syn[i]) < ft_strlen(word))
			return (syn[i]);
		i++;
	}
	return (word);
}

int main(int ac, char const **av)
{
	int fd;
	int i;
	char *line;
	char *tmp;
	char **tab;

	if (ac != 2)
		return (-1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &line))
	{
		tab = ft_strsplit(line, ' ');
		i = 0;
		while (tab[i])
		{
			if (ft_strlen(tab[i]) >= MAX_WORD_LEN)
				ft_putstr("\033[31mCENSURE\033[0m");
			else if ((tmp = find_syn(tab[i])) != NULL)
				ft_putstr(tmp);
			else
				ft_putstr(tab[i]);
			ft_putchar(' ');
			free(tab[i]);
			i++;
		}
		ft_putchar('\n');
		free(tab);
	}
	return (0);
}