/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:14:27 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/04 12:15:58 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*pos;

	i = 0;
	pos = (char *)b;
	while (i < len)
	{
		*pos = (unsigned char)c;
		i++;
		pos++;
	}
	return (b);
}
