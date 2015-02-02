/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:33:01 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/10 17:54:34 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*buff;
	char			*dest;
	unsigned int	i;

	buff = (char *)malloc(len);
	dest = (char *)dst;
	if (buff == NULL)
		return (NULL);
	ft_memcpy(buff, src, len);
	i = 0;
	while (i < len)
	{
		dest[i] = buff[i];
		i++;
	}
	free(buff);
	return (dst);
}
