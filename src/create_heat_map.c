/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heat_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:14:09 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/04/18 10:53:49 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	create_direction(t_map *field, int *fin_zer_ch)
{
	fin_zer_ch[1] = 1;
	fin_zer_ch[0] = -2;
	field->insert_dir[0][0] = -1;
	field->insert_dir[0][1] = 0;
	field->insert_dir[1][0] = -1;
	field->insert_dir[1][1] = 1;
	field->insert_dir[2][0] = 0;
	field->insert_dir[2][1] = 1;
	field->insert_dir[3][0] = 1;
	field->insert_dir[3][1] = 1;
	field->insert_dir[4][0] = 1;
	field->insert_dir[4][1] = 0;
	field->insert_dir[5][0] = 1;
	field->insert_dir[5][1] = -1;
	field->insert_dir[6][0] = 0;
	field->insert_dir[6][1] = -1;
	field->insert_dir[7][0] = -1;
	field->insert_dir[7][1] = -1;
}

int		check_insert_hot(t_map *field, int i)
{
	if (((field->x + field->insert_dir[i][0]) < field->map_size[0] &&
	(field->y + field->insert_dir[i][1]) < field->map_size[1]) &&
	((field->x + field->insert_dir[i][0]) >= 0 &&
	(field->y + field->insert_dir[i][1]) >= 0) &&
	field->heat_map[field->x + field->insert_dir[i][0]][field->y
	+ field->insert_dir[i][1]] == 0)
		return (1);
	return (0);
}

int		insert_hot(t_map *field, int find)
{
	int i;
	int check;

	check = 0;
	i = 0;
	if (find == 0)
		field->heat_map[field->x][field->y] = 999;
	while (i < 8)
	{
		if (check_insert_hot(field, i))
		{
			if (find == 0)
				field->heat_map[field->x + field->insert_dir[i][0]][field->y
				+ field->insert_dir[i][1]] = 999;
			else
				field->heat_map[field->x + field->insert_dir[i][0]][field->y
				+ field->insert_dir[i][1]] = (find == -2) ? 1 : find + 1;
			check++;
		}
		i++;
	}
	return (check);
}

void	fill_heat(t_map *field)
{
	int			fin_zer_ch[3];

	create_direction(field, fin_zer_ch);
	while (fin_zer_ch[1])
	{
		fin_zer_ch[2] = 0;
		fin_zer_ch[1] = 0;
		field->x = 0;
		while (field->x < field->map_size[0])
		{
			field->y = 0;
			while (field->y < field->map_size[1])
			{
				if (field->heat_map[field->x][field->y] == 0)
					fin_zer_ch[1] = 1;
				if (field->heat_map[field->x][field->y] == fin_zer_ch[0])
					fin_zer_ch[2] += insert_hot(field, fin_zer_ch[0]);
				field->y++;
			}
			field->x++;
		}
		fin_zer_ch[0]++;
		fin_zer_ch[0] = (fin_zer_ch[2] == 0) ? 0 : fin_zer_ch[0];
		fin_zer_ch[0] = (fin_zer_ch[0] == -1) ? 1 : fin_zer_ch[0];
	}
}

void	create_heat_map(t_map *field, t_player *me)
{
	dprintf(3, "huy");
	field->x = 0;
	field->heat_map = (int**)malloc(sizeof(int*) *
	(field->map_size[0] * field->map_size[1]));
	while (field->x < field->map_size[0])
	{
		field->heat_map[field->x] = (int*)malloc(sizeof(int) *
		field->map_size[1]);
		field->y = 0;
		while (field->y < field->map_size[1])
		{
			if (field->map[field->x][field->y] == me->id)
				field->heat_map[field->x][field->y] = -1;
			else if (field->map[field->x][field->y] == me->enemy_id)
				field->heat_map[field->x][field->y] = -2;
			else if (field->map[field->x][field->y] == '.')
				field->heat_map[field->x][field->y] = 0;
			field->y++;
		}
		field->x++;
	}
	fill_heat(field);
}
