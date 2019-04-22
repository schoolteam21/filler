/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:35:45 by ijate-bl          #+#    #+#             */
/*   Updated: 2018/11/23 17:30:06 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;
	size_t p;
	size_t littlen;

	littlen = ft_strlen(little);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		p = i;
		j = 0;
		while (big[i] == little[j] && big[i] != '\0' && i < len)
		{
			i++;
			j++;
		}
		if (j == littlen)
			return ((char*)(big + p));
		i = p + 1;
	}
	return (NULL);
}
