/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:37:03 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/04/18 13:28:13 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	plateau(t_map *field, char **s)
{
	ft_lenatoi((*s + 8 + ft_lenatoi((*s + 7),
	&(field->map_size[0]))), &(field->map_size[1]));
	ft_strdel(s);
	get_next_line(0, s);
	field->map = record_map_piece(4, field->map_size[0], field->map_size[1]);
}

void	piece(t_map *field, t_player *me, char **s)
{
	ft_lenatoi((*s + 6 + ft_lenatoi((*s + 5),
	&(me->piece_size[0]))), &(me->piece_size[1]));
	ft_strdel(s);
	me->piece = record_map_piece(0, me->piece_size[0], me->piece_size[1]);
	create_heat_map(field, me);
}

int		fill_map(t_map *field, t_player *me)
{
	char	*s;

	while (get_next_line(0, &s) > 0)
	{
		if (ft_strstr(s, "$$$ exec"))
		{
			me->id = (ft_strstr(s, "p1")) ? 'O' : 'X';
			me->enemy_id = (me->id == 'X') ? 'O' : 'X';
		}
		else if (ft_strstr(s, "Plateau"))
			plateau(field, &s);
		if (ft_strstr(s, "Piece"))
		{
			piece(field, me, &s);
			filler(field, me);
			return (1);
		}
		else
			ft_strdel(&s);
	}
	return (0);
}

int		main(void)
{
	t_player	me;
	t_player	enemy;
	t_map		field;

	me.id = 'z';
	fill_map(&field, &me);
	return (0);
}
