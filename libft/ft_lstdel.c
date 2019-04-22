/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 02:07:22 by ijate-bl          #+#    #+#             */
/*   Updated: 2018/12/17 02:08:24 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list1;
	t_list *list2;

	list1 = *alst;
	if (!alst || !del)
		return ;
	while (list1)
	{
		list2 = list1->next;
		(del)(list1->content, list1->content_size);
		free(list1);
		list1 = list2;
	}
	*alst = NULL;
}
