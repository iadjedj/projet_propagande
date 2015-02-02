/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:42:31 by iadjedj           #+#    #+#             */
/*   Updated: 2014/11/11 17:54:59 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	ft_lstadd_end(t_list *alst, void *content, size_t size)
{
	t_list *new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return ;
	new->content = content;
	new->content_size = size;
	new->next = NULL;
	if (alst)
	{
		while (alst->next)
			alst = alst->next;
		alst->next = new;
	}
	else
		alst = new;
}
