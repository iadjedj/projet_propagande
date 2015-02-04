/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 00:45:14 by iadjedj           #+#    #+#             */
/*   Updated: 2015/02/04 02:03:13 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_wstrlen(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*str)
	{
		if (*str > 0)
		{
			i++;
		}
		else if (*str < 0 && j == 0)
			j = 1;
		else
		{
			j = 0;
			i++;
		}
		str++;
	}
	return (i);
}

void	censure(char *mot)
{
	int		len;

	len = ft_wstrlen(mot);
	ft_putstr(mot);
	ft_putnchar('\b', len);
	ft_putstr("\033[37;40m");
	usleep(60000);
	while (len--)
	{
		usleep(30000);
		ft_putchar(' ');
	}
	ft_putnchar(' ', len);
	ft_putstr("\033[0m");
	ft_putchar(' ');
}
