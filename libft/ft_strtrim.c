/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:51:57 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/12 16:40:17 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	int				j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	if (j == -1)
		return (ft_strnew(0));
	while ((s[i] == '\n' || s[i] == '\t' || s[i] == ' ') && s[i] != '\0')
		i++;
	while ((s[j] == '\n' || s[j] == '\t' || s[j] == ' ') && j > 0)
		j--;
	if (j == 0)
		return (ft_strnew(0));
	return (ft_strsub(s, i, (unsigned int)j - i + 1));
}
