/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:13:17 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/03/29 16:04:03 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	num;
	int			i;
	int			is_negative;

	i = 0;
	num = 0;
	is_negative = 1;
	while (str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == '\t'
	|| str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_negative = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
		if (num != num * 10 / 10)
			return (is_negative < 0 ? 0 : -1);
	}
	return (num * is_negative);
}
