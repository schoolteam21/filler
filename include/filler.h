/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:44:17 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/04/18 13:34:20 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef	struct	s_min_crd
{
	int			min;
	int			min_crds[2];
	int			tem_min;
}				t_min_crd;

typedef	struct	s_map
{
	t_min_crd	crd;
	char		**map;
	int			**heat_map;
	int			map_size[2];
	int			insert_dir[8][2];
	int			x;
	int			y;
}				t_map;

typedef	struct	s_player
{
	char		id;
	char		enemy_id;
	int			enemy_x_y[2];
	int			last_pos;
	char		**piece;
	int			x;
	int			y;
	int			asterix;
	int			piece_size[2];
}				t_player;

void			count_asterix(t_player *me);
int				fill_map(t_map *field, t_player *me);
char			**record_map_piece(int start, int len, int end);
int				filler(t_map *field, t_player *me);
int				check_position(t_map *field, t_player *me);
void			free_list(t_map *field, t_player *me);
void			create_heat_map(t_map *field, t_player *me);
int				right_move(t_map *field, t_player *me);

#endif
