/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:34:37 by iadjedj           #+#    #+#             */
/*   Updated: 2014/12/29 19:27:09 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *str)
{
	int i;
	int is_neg;

	i = 0;
	is_neg = 0;
	while (ft_isspace((int)*str) != 0)
		str++;
	if (str[0] == '-')
	{
		is_neg = 1;
		str++;
	}
	else if (str[0] == '+')
		str++;
	while (*str && ft_isdigit((int)*str) == 1)
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	if (is_neg == 1)
		i = -i;
	return (i);
}
