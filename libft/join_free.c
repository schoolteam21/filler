/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_check_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:26:22 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/03/20 22:23:57 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_free(char *str1, char *str2)
{
	char *tmp;

	tmp = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (tmp);
}
