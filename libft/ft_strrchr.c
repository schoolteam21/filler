/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:12:05 by ijate-bl          #+#    #+#             */
/*   Updated: 2018/11/22 19:38:33 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int symbol)
{
	int i;

	i = ft_strlen((char*)string) + 1;
	while (i--)
	{
		if (string[i] == (char)symbol)
			return ((char*)(string + i));
	}
	return (NULL);
}
