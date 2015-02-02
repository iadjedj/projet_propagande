/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:19:40 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/05 19:19:45 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int pos;
	unsigned int len;
	unsigned int i;

	pos = ft_strlen(s1);
	len = ft_strlen(s2);
	i = 0;
	while (i < len && i < n)
	{
		s1[pos + i] = s2[i];
		i++;
	}
	s1[pos + i] = '\0';
	return (s1);
}
