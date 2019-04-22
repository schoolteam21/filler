/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 05:46:22 by ijate-bl          #+#    #+#             */
/*   Updated: 2018/12/17 06:14:53 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	rev;

	i = 0;
	size = 0;
	while (i < size - 1)
	{
		rev = str[i];
		str[i] = str[size - 1];
		str[size - 1] = rev;
		size--;
		i++;
	}
	return (str);
}
