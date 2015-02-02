/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:54:16 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/12 17:46:10 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*n_elem;

	if ((n_elem = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		n_elem->content = NULL;
		n_elem->content_size = 0;
	}
	else
	{
		n_elem->content = ft_memalloc(content_size + 1);
		ft_memcpy(n_elem->content, content, content_size);
		n_elem->content_size = content_size;
	}
	n_elem->next = NULL;
	return (n_elem);
}
