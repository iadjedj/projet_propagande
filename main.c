/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:06:11 by iadjedj           #+#    #+#             */
/*   Updated: 2015/02/04 02:55:49 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "dico.h"
#include "freq.h"
#include "sms.h"

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
			j++;
		if (word[j] == '\0')
			return (DICO[i]);
		i++;
	}
	return (NULL);
}

double	get_freq(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (FREQ[i] != NULL)
	{
		j = 0;
		while (str[j] && FREQ[i][j] != '\t' && FREQ[i][j] == str[j])
			j++;
		if (str[j] == '\0')
			break;
		i++;
	}
	if (FREQ[i] == NULL)
		return (0);
	else
		return (strtod(ft_strchr(FREQ[i], '\t'), NULL));
}

char	*find_syn(char *word)
{
	char			*tmp;
	char			**syn;
	int				i;
	size_t			len;

	word[0] = ft_tolower(word[0]);
	if (!(tmp = get_word(word)))
		return (NULL);
	syn = ft_strsplit(tmp, ' ');
	i = 0;
	len = strlen(word);
	while (syn && syn[i])
	{
		if (get_freq(syn[i]) > get_freq(word) && strlen(syn[i]) <= len)
			return (syn[i]);
		free(syn[i]);
		i++;
	}
	free(syn);
	return (word);
}

char	*find_sms(char *word)
{
	char	**tmp;
	int		size;
	int		i;

	size = strlen(word);
	i = 0;
	if (word[size - 1] == 's' || word[size - 1] == '.' || word[size - 1] == ',')
	{
		word[size - 1] = '\0';
		size--;
	}
	while (SMS[i] != NULL)
	{
		tmp = ft_strsplit(SMS[i], '=');
		if (ft_strequ(tmp[0], word))
		{
			return (tmp[1]);	
		}
		free(tmp[0]);
		free(tmp[1]);
		free(tmp);
		i++;
	}
	return (NULL);
}

void	remplacement(char *line, int level)
{
	int		i;
	char	*tmp;
	char	**tab;

	tab = ft_strsplit(line, ' ');
	i = 0;
	while (tab[i])
	{
		if ((int)strlen(tab[i]) >= 15 - level)
			censure(tab[i]);
		else if (level == 3 && (tmp = find_sms(tab[i])))
		{
			ft_putstr(tmp);
			ft_putchar(' ');
		}
		else if ((tmp = find_syn(tab[i])) != NULL)
		{
			if ((int)strlen(tmp) < 12 - (2 * level))
			{
				ft_putstr(tmp);
				ft_putchar(' ');
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
		usleep(30000);
	}
	ft_putchar('\n');
	free(tab);
}

int 	main(int ac, char const **av)
{
	int		fd;
	int		level;
	char	*line;

	if (ac < 2 || ac > 3)
	{
		ft_putendl("Erreur :\nSyntaxe : ./propagande filename (level[0 - 3])");
		return (-1);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putendl("Erreur :\nFichier inexistant ou probleme d'acces");
		return (-1);
	}
	level = (ac == 3) ? ft_atoi(av[2]) : 0;
	if (level < 0 || level > 3)
	{
		ft_putendl("Erreur :\nLe niveau de débilité doit être compris entre 0 et 3");
		return (-1);
	}
	while (get_next_line(fd, &line))
	{
		remplacement(line, level);
		free(line);
	}
	return (0);
}