/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:13:11 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/04/18 13:37:29 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	count_asterix(t_player *me)
{
	int i;
	int j;

	me->asterix = 0;
	i = 0;
	while (i < me->piece_size[0])
	{
		j = 0;
		while (me->piece[i][j])
		{
			if (me->piece[i][j] == '*')
				me->asterix++;
			j++;
		}
		i++;
	}
}

char	**record_map_piece(int start, int len, int end)
{
	int		i;
	char	*s;
	char	**str;

	str = (char**)malloc(sizeof(char*) * len);
	i = 0;
	while (i < len)
	{
		get_next_line(0, &(s));
		str[i] = join_free(ft_strsub(s, start, end), ft_strdup("\0"));
		free(s);
		i++;
	}
	return (str);
}
