/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:41:36 by ijate-bl          #+#    #+#             */
/*   Updated: 2018/11/26 21:07:00 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ind_len_str(int *arr, const char *s)
{
	int i;
	int len;

	len = ft_strlen(s) - 1;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
	}
	while (len > i && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		len--;
	arr[0] = i;
	arr[1] = len;
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		arr[2];
	int		len;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	ind_len_str(arr, s);
	i = arr[0];
	len = arr[1];
	if (!(str = (char*)malloc(sizeof(char) *
	(((len - i) > 0) ? len - i : len) + 2)))
		return (NULL);
	j = 0;
	while (i <= len)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
