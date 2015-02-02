/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:29:45 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/11 18:27:29 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*map;

	if (s && f)
	{
		i = ft_strlen(s);
		map = ft_strnew(i);
		while (i-- && map != NULL)
			map[i] = f(i, s[i]);
		return (map);
	}
	return (NULL);
}
