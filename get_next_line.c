/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 13:55:35 by iadjedj           #+#    #+#             */
/*   Updated: 2015/02/02 16:14:43 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	int		get_pos(char const *str)
{
	int				pos;

	pos = 0;
	while (str[pos] != '\n' && str[pos] != '\0')
		pos++;
	return (pos);
}

static	int		get_start_of_line(char **buff, char **line)
{
	int			pos;
	int			len;

	pos = get_pos(*buff);
	len = ft_strlen(*buff);
	if (pos != len)
	{
		if (pos == 0)
		{
			*line = ft_strdup("");
			ft_memmove(*buff, (*buff) + 1, BUFF_SIZE - 1);
			return (1);
		}
		if ((*line = ft_strnew(pos)) == NULL)
			return (-1);
		ft_strncpy(*line, *buff, pos);
		ft_memmove(*buff, (*buff) + pos + 1, BUFF_SIZE - pos - 1);
		return (1);
	}
	if ((*line = ft_strdup(*buff)) == NULL)
		return (-1);
	ft_bzero(*buff, BUFF_SIZE + 1);
	return (0);
}

static int		get_init(int const fd, char **buff, char **line)
{
	int				i;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	if (*buff == NULL)
	{
		if ((*buff = ft_strnew(BUFF_SIZE + 1)) == NULL)
			return (-1);
	}
	else if ((i = get_start_of_line(buff, line)) == 1)
		return (1);
	else if (i == -1)
		return (-1);
	return (0);
}

static int		free_and_join(char **buff, char **line, int const i)
{
	char	*tmp;
	char	*tmp2;
	int		pos;

	(*buff)[i] = '\0';
	pos = get_pos(*buff);
	if ((tmp = ft_strsub(*buff, 0, pos)) == NULL)
		return (-42);
	if ((tmp2 = ft_strdup(*line)) == NULL)
		return (-42);
	free(*line);
	if ((*line = ft_strjoin(tmp2, tmp)) == NULL)
		return (-42);
	free(tmp);
	free(tmp2);
	return (pos);
}

int				get_next_line(int const fd, char **line)
{
	int				i;
	int				pos;
	char			*tmp;
	static char		*buff = NULL;

	if ((i = get_init(fd, &buff, line)) == -1)
		return (-1);
	else if (i == 1)
		return (1);
	while ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if ((pos = free_and_join(&buff, line, i)) == -42)
			return (-1);
		if (buff[pos] == '\n')
		{
			tmp = ft_strdup(buff + pos + 1);
			ft_strcpy(buff, tmp);
			free(tmp);
			buff[BUFF_SIZE - pos - 1] = '\0';
			return (1);
		}
	}
	if (i == 0)
		*buff = '\0';
	return ((i == 0) ? 0 : -1);
}
