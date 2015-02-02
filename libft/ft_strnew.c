/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 21:59:46 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/27 13:26:13 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*new;
	unsigned int	i;

	i = 0;
	if ((new = (char *)malloc(size + 1 * sizeof(new))) == NULL)
		return (NULL);
	while (i <= size + 1)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}
