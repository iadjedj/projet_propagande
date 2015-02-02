/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:05:23 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/10 17:35:39 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*found;
	int		i;
	int		j;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 != '\0')
	{
		if (*s1 == *s2)
		{
			j = 0;
			found = (char *)s1;
			while (*(s1 + j++) == *(s2 + i++))
			{
				if (*(s2 + i) == '\0')
					return (found);
			}
			i = 0;
		}
		s1++;
	}
	return (NULL);
}
