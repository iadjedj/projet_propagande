/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:51:11 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/05 18:51:12 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strcat(char *s1, const char *s2)
{
	unsigned int pos;
	unsigned int len;
	unsigned int i;

	pos = ft_strlen(s1);
	len = ft_strlen(s2);
	i = 0;
	while (i < len)
	{
		s1[pos + i] = s2[i];
		i++;
	}
	s1[pos + i] = '\0';
	return (s1);
}
