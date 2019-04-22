/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:19:31 by ijate-bl          #+#    #+#             */
/*   Updated: 2018/11/28 19:34:30 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*is_negative(int n, int *arr)
{
	if (n < 0)
	{
		arr[0] = -1;
		arr[1] = 3;
	}
	else
	{
		arr[0] = 1;
		arr[1] = 2;
	}
	return (arr);
}

static char	*set_val(int n, char *str, int i)
{
	int j;

	j = n;
	while (n > 0)
	{
		if (n < 10)
		{
			str[i] = n + '0';
			return (str);
		}
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	if (j == 0)
		str[0] = '0';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		count;
	int		isneg[2];

	if (n == -2147483648)
		return (str = ft_strsub("-2147483648", 0, 11));
	is_negative(n, isneg);
	n *= isneg[0];
	count = n;
	i = 0;
	while (count >= 10)
	{
		count /= 10;
		i++;
	}
	i += isneg[1];
	if (!(str = (char*)malloc(sizeof(char) * (i--))))
		return (NULL);
	if (isneg[1] == 3)
		str[0] = '-';
	str[i--] = '\0';
	return (set_val(n, str, i));
}
