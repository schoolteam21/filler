/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:11:38 by ijate-bl          #+#    #+#             */
/*   Updated: 2018/12/16 23:11:57 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*listik;

	if (!(listik = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		listik->content = NULL;
		listik->content_size = 0;
	}
	else
	{
		if (!(listik->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(listik->content, content, content_size);
		listik->content_size = content_size;
	}
	listik->next = NULL;
	return (listik);
}
