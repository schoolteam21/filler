/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 05:43:51 by ijate-bl          #+#    #+#             */
/*   Updated: 2018/12/17 05:44:57 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int min, int max)
{
	int *massiv;
	int i;

	i = 0;
	massiv = NULL;
	if (min < max)
	{
		massiv = (int*)malloc(sizeof(*massiv) * (max - min));
		while (min < max)
		{
			massiv[i] = min;
			min++;
			i++;
		}
	}
	return (massiv);
}
