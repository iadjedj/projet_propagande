/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 13:36:29 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/11 19:12:49 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_size(int n)
{
	int		size;

	size = 0;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		len;

	str = ft_strnew(11);
	i = 0;
	len = ft_itoa_size(n);
	if (n == -2147483648)
		str = ft_strcpy(str, "-2147483648");
	if (n < 0 && n != -2147483648)
	{
		str[i] = '-';
		n = -n;
		len++;
	}
	while (n >= 10)
	{
		str[len - i - 1] = n % 10 + '0';
		n /= 10;
		i++;
	}
	if (n < 10 && n != -2147483648)
		(str[0] != '-') ? (str[0] = n + '0') :
		(str[1] = n + '0');
	return (str);
}
