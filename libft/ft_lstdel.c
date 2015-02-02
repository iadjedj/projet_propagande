/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 21:14:17 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/12 13:29:08 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *pos;
	t_list *next;

	if (!alst || !del)
		return ;
	pos = *alst;
	while (pos)
	{
		next = pos->next;
		del(pos->content, pos->content_size);
		free(pos);
		pos = next;
	}
	*alst = NULL;
}
