/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:06:11 by iadjedj           #+#    #+#             */
/*   Updated: 2015/02/03 20:55:42 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "dico.h"
#include "freq.h"

#define MAX_WORD_LEN 12

char	*get_word(char *word)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = strlen(word);
	if (word[size - 1] == 's' || word[size - 1] == '.' || word[size - 1] == ',')
	{
		word[size - 1] = '\0';
		size--;
	}
	while (DICO[i] != NULL)
	{
		j = 0;
		while (word[j] && DICO[i][j] != '=' && DICO[i][j] == word[j])
		{
			j++;
		}
		if (word[j] == '\0')
			return (DICO[i]);
		i++;
	}
	return (NULL);
}

float		get_freq(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (FREQ[i] != NULL)
	{
		j = 0;
		while (str[j] && FREQ[i][j] != '\t' && FREQ[i][j] == str[j])
		{
			j++;
		}
		if (str[j] == '\0')
			break;
		i++;
	}
	if (FREQ[i] == NULL)
		return (0);
	else
		return (atof(ft_strchr(FREQ[i], '\t')));
}

char		*find_syn(char *word)
{
	char			*tmp;
	char			**syn;
	int				i;
	size_t			len;

	if (!(tmp = get_word(word)))
		return (NULL);
	syn = ft_strsplit(tmp, ' ');
	i = 0;
	len = strlen(word);
	while (syn && syn[i])
	{
		if (get_freq(syn[i]) > get_freq(word) && strlen(syn[i]) <= len)
		{
			return (syn[i]);
		}
		free(syn[i]);
		i++;
	}
	free(syn);
	return (word);
}

void	censure(char *mot)
{
	int		len;

	len = (strlen(mot) % 12) + 2;
	// ft_putstr("\033[31m");
	while (len--)
		ft_putstr("█");
	ft_putstr("\033[0m ");
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
			if (strlen(tab[i]) >= MAX_WORD_LEN)
				censure(tab[i]);
			else if ((tmp = find_syn(tab[i])) != NULL)
			{
				if ((int)strlen(tmp) < (rand() % 10) + 5)
				{
					ft_putstr("\033[32m");
					ft_putstr(tmp);
					ft_putstr("\033[0m ");
				}
				else
					censure(tab[i]);
			}
			else if (strlen(tab[i]) > 0 || ft_isdigit(tab[i][0]))
			{
				ft_putstr(tab[i]);
				ft_putchar(' ');
			}
			else
				censure(tab[i]);
			free(tab[i]);
			i++;
		}
		ft_putchar('\n');
		free(tab);
		free(line);
	}
	return (0);
}