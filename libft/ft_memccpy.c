/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:45:21 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/27 14:14:47 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*src_char;
	unsigned char	*dst_char;

	i = 0;
	src_char = (unsigned char *)src;
	dst_char = (unsigned char *)dst;
	while (src_char[i] != (unsigned char)c && i < n)
	{
		dst_char[i] = src_char[i];
		i++;
	}
	if ((unsigned char)src_char[i] == (unsigned char)c && i != n)
	{
		dst_char[i] = (unsigned char)c;
		return (dst + i + 1);
	}
	return (NULL);
}
