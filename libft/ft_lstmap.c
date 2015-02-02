/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 21:50:57 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/11 17:54:23 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *retour;

	retour = (t_list*)malloc(sizeof(t_list));
	new = f(lst);
	retour->content = new->content;
	retour->content_size = new->content_size;
	retour->next = NULL;
	if (lst->next)
		lst = lst->next;
	while (lst)
	{
		new = f(lst);
		ft_lstadd_end(retour, new->content, new->content_size);
		lst = lst->next;
	}
	return (retour);
}
