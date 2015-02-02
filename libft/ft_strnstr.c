/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:16:55 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/20 16:14:15 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	char			*found;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 != '\0' && j < size && !(size < ft_strlen(s2)))
	{
		if (*s1 == *s2)
		{
			found = (char *)s1;
			while (*s1 == *(s2 + i) && i + j < size)
			{
				s1++;
				i++;
				if (*(s2 + i) == '\0')
					return (found);
			}
			i = 0;
		}
		j++;
		s1++;
	}
	return (NULL);
}
