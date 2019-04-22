/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:51:23 by ijate-bl          #+#    #+#             */
/*   Updated: 2018/11/23 18:05:00 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int		i;

	i = 0;
	while (str1[i] && str1[i] == str2[i] && i < (int)n - 1)
		i++;
	if (n)
		return (((unsigned char)str1[i]) - ((unsigned char)str2[i]));
	return (0);
}
