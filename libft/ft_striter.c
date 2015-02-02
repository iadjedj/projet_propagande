/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:14:35 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/11 18:24:59 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_striter(char *s, void (*f)(char *))
{
	unsigned int i;

	if (s && f)
	{
		i = ft_strlen(s);
		while (i--)
		{
			f(&s[i]);
		}
	}
}
