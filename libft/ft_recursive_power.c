/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 05:57:35 by ijate-bl          #+#    #+#             */
/*   Updated: 2018/12/17 05:57:55 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
	{
		return (1);
	}
	else
	{
		if (power < 0)
		{
			return (0);
		}
	}
	return (nb * ft_recursive_power(nb, power - 1));
}
