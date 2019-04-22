/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 04:49:24 by ijate-bl          #+#    #+#             */
/*   Updated: 2018/12/17 04:49:30 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*listik;
	t_list	*nextlist;

	if (!lst || !f)
		return (NULL);
	listik = f(lst);
	nextlist = listik;
	while (lst->next)
	{
		lst = lst->next;
		if (!(listik->next = f(lst)))
		{
			while (nextlist)
			{
				listik = nextlist->next;
				free(nextlist);
				nextlist = listik;
			}
		}
		listik = listik->next;
	}
	return (nextlist);
}
