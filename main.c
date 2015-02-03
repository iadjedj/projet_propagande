/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:06:11 by iadjedj           #+#    #+#             */
/*   Updated: 2015/02/03 16:06:34 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "dico.c"

#define MAX_WORD_LEN 10

char	*get_word(char *word)
{
	int		i;
	// int		size;
	// int		plur;
	char **tab;

	i = 0;
	// plur = 0;
	// size = strlen(word) + 1;
	while (DICO[i] != NULL)
	{
		tab = ft_strsplit(DICO[i], '=');
		if (ft_strequ(tab[0], word))
		{
			free(tab[0]);
			return (ft_strdup(tab[1]));
		}
		else
		{
			free(tab[0]);
			free(tab[1]);
			free(tab);
		}
		// if (word[size - 2] == 's' && (word[size - 1] == '.' || word[size - 1] == ','))
		// 	plur = 2;
		// else if (word[size - 1] == 's' || word[size - 1] == '.' || word[size - 1] == ',')
		// 	plur = 1;
		// else	
		// 	plur = 0;
		i++;
	}
	// if (DICO[i] == NULL)
		return (NULL);
	// else if (plur == 2)
	// 	return (DICO[i] + strlen(word) - 1);
	// else if (plur == 1)
	// 	return (DICO[i] + strlen(word)/* + 1*/);
	// else
	// 	return (DICO[i] + strlen(word) + 1);
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
		if (strlen(syn[i]) < strlen(word))
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
			if (strlen(tab[i]) >= MAX_WORD_LEN)
				// tab[i] = "";
				ft_putstr("\033[31mCENSURE\033[0m ");
			else if ((tmp = find_syn(tab[i])) != NULL && (int)strlen(tmp) < (rand() % 10) + 5)
			{
				// tab[i] = tmp;
				ft_putstr("\033[32m");
				ft_putstr(tmp);
				ft_putstr("\033[0m");
				ft_putchar(' ');
			}
			else if (strlen(tab[i]) <= 5)
			{
				// tab[i] = "";
				ft_putstr(tab[i]);
				ft_putchar(' ');
			}
			free(tab[i]);
			i++;
		}
		// i = 0;
		// compt = 0;
		// while (tab[i])
		// {
		// 	if (strlen(tab[i]) > MAX_WORD_LEN)
		// 		compt++;
		// 	i++;
		// }
		// i = 0;
		// if (compt < 3)
		// {
		// 	while (tab[i])
		// 	{
		// 		ft_putstr(tab[i]);
		// 		ft_putchar(' ');
		// 		i++;
		// 	}
		// }
		ft_putchar('\n');
		free(tab);
	}
	return (0);
}