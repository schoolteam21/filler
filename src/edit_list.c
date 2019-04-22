/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 20:57:45 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/04/18 10:36:02 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_heat_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->map_size[0])
		free(map->heat_map[i++]);
	free(map->heat_map);
}

void	free_list(t_map *field, t_player *me)
{
	int i;

	i = 0;
	while (i < field->map_size[0])
		free(field->map[i++]);
	free(field->map);
	i = 0;
	while (i < me->piece_size[0])
		free(me->piece[i++]);
	free(me->piece);
	free_heat_map(field);
}
