/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:21:44 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/11 18:26:09 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*map;

	if (s && f)
	{
		i = ft_strlen(s);
		map = ft_strnew(i);
		while (i-- && map != NULL)
			map[i] = f(s[i]);
		return (map);
	}
	return (NULL);
}
