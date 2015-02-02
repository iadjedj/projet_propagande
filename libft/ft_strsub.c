/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:45:34 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/27 13:21:01 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*sub;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	j = 0;
	if (i < len + start)
		return (NULL);
	if ((sub = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (j < len)
	{
		sub[j] = s[start];
		j++;
		start++;
	}
	sub[j] = '\0';
	return (sub);
}
