/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:11:10 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/04/18 13:30:46 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	helper_check_piece_pos(t_map *field, t_player *me,
int *check_id, int *check_asterix)
{
	if (field->map[field->x + me->x][field->y + me->y] &&
	field->map[field->x + me->x][field->y + me->y] == me->id &&
	me->piece[me->x][me->y] == '*')
		(*check_id)++;
	if (field->map[field->x + me->x][field->y + me->y] &&
	me->piece[me->x][me->y] == '*' &&
	(field->map[field->x + me->x][field->y + me->y] == '.' ||
	field->map[field->x + me->x][field->y + me->y] == me->id))
	{
		field->crd.tem_min += (field->map[field->x + me->x][field->y + me->y] ==
		me->id) ? 0 : field->heat_map[field->x + me->x][field->y + me->y];
		(*check_asterix)++;
	}
}

int		check_piece_pos(t_map *field, t_player *me)
{
	int check_id;
	int check_asterix;
	int min;

	check_id = 0;
	check_asterix = 0;
	me->x = 0;
	field->crd.tem_min = 0;
	while (me->x < me->piece_size[0])
	{
		me->y = 0;
		while (me->piece[me->x][me->y])
		{
			if ((field->x + me->x) >= field->map_size[0]
			|| (field->y + me->y) >= field->map_size[1])
				return (0);
			helper_check_piece_pos(field, me, &check_id, &check_asterix);
			me->y++;
		}
		if (check_asterix == me->asterix && check_id == 1)
			return (1);
		me->x++;
	}
	return (0);
}

int		check_position(t_map *field, t_player *me)
{
	if (field->map[field->x][field->y] &&
	(field->map[field->x][field->y] == '.' ||
	field->map[field->x][field->y] == me->id ||
	field->map[field->x][field->y] == ft_tolower(me->id)))
	{
		if (check_piece_pos(field, me))
		{
			return (1);
		}
	}
	return (0);
}

int		right_move(t_map *field, t_player *me)
{
	int min;

	min = 0;
	field->crd.min = 1000000;
	field->crd.min_crds[0] = 0;
	field->crd.min_crds[1] = 0;
	while (field->x < field->map_size[0])
	{
		field->y = 0;
		while (field->map[field->x][field->y])
		{
			if (check_position(field, me))
				if (field->crd.min > field->crd.tem_min)
				{
					field->crd.min = field->crd.tem_min;
					field->crd.min_crds[0] = field->x;
					field->crd.min_crds[1] = field->y;
				}
			field->y++;
		}
		field->x++;
	}
	return (0);
}

int		filler(t_map *field, t_player *me)
{
	int dir;

	count_asterix(me);
	field->x = 0;
	right_move(field, me);
	ft_putnbr_fd(field->crd.min_crds[0], 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(field->crd.min_crds[1], 1);
	ft_putchar_fd('\n', 1);
	free_list(field, me);
	fill_map(field, me);
	return (1);
}
