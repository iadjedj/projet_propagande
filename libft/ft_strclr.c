/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 22:31:23 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/11 18:21:14 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	unsigned int i;
	unsigned int len;

	i = 0;
	if (s)
	{
		len = ft_strlen (s);
		while (i < len)
		{
			s[i] = '\0';
			i++;
		}
	}
}
