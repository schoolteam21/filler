/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:25:35 by ijate-bl          #+#    #+#             */
/*   Updated: 2018/11/28 17:56:02 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	point_malloc(char const *s, char c)
{
	int		count;
	int		i;

	count = 1;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static int	*start_len_index(int *arr, const char *s, char c, int i)
{
	int start;
	int len;

	start = 0;
	len = 0;
	while (s[i] == c)
		i++;
	start = i;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	arr[0] = start;
	arr[1] = len;
	arr[2] = i;
	return (arr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		arr[3];
	int		k;

	if (!s || !c)
		return (NULL);
	if (!(str = (char**)malloc(sizeof(char*) * point_malloc(s, c))))
		return (NULL);
	i = 0;
	k = -1;
	while (s[i] && s[i + 1] != '\0')
	{
		start_len_index(arr, s, c, i);
		i = arr[2];
		if (s[arr[0]] != '\0')
		{
			k++;
			str[k] = ft_strsub(s, arr[0], arr[1]);
		}
	}
	k++;
	str[k] = NULL;
	return (str);
}
