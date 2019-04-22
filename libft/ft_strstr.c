/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:55:10 by ijate-bl          #+#    #+#             */
/*   Updated: 2018/11/23 17:31:36 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int p;
	int len;

	len = ft_strlen(needle);
	i = 0;
	if (((char*)needle)[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		p = i;
		j = 0;
		while (haystack[i] == needle[j] && haystack[i] != '\0')
		{
			i++;
			j++;
		}
		if (j == len)
			return ((char*)(haystack + p));
		i = p + 1;
	}
	return (NULL);
}
