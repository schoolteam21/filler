/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:13:17 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/04/18 13:49:11 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int			ft_lenatoi(const char *str, int *n)
{
	long long	num;
	int			i;
	int			is_negative;

	i = 0;
	num = 0;
	is_negative = 1;
	if (!str)
		return (0);
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\f' ||
	str[i] == '\r' || str[i] == '\t' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_negative = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	*n = (int)(num * is_negative);
	return (intlen(*n));
}
