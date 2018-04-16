/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:27:31 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/16 15:38:23 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *nxtlist;

	if (*alst == NULL || del == NULL)
		return ;
	list = *alst;
	while (list)
	{
		nxtlist = list->next;
		del((*list).content, (*list).content_size);
		list = nxtlist;
		free(list);
	}
	*alst = NULL;
}
