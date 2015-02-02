/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:07:52 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/06 22:35:13 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	pos;
	unsigned int	len;
	unsigned int	i;
	int				max_cpy;

	pos = ft_strlen(dst);
	len = ft_strlen(src);
	max_cpy = size - ft_strlen(dst) - 1;
	i = 0;
	if (max_cpy < 0)
		return (size + len);
	while (i < (unsigned int)max_cpy && i < len)
	{
		dst[pos + i] = src[i];
		i++;
	}
	dst[pos + i] = '\0';
	return (len + pos);
}
