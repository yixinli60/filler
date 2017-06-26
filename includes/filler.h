/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 16:05:48 by yli               #+#    #+#             */
/*   Updated: 2017/06/22 15:04:03 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_info
{
	char	plr;
	int		row;
	int		col;
	int		piece_row;
	int		piece_col;
	char	**map;
	char	**piece;
	int		up;
	int		left;
	int		final_row;
	int		final_col;
}				t_info;

int				get_map_info(char *buf, t_info *info_stru);
int				save_map_to_struc(char *buf, t_info *info_stru);
int				get_piece_info(char *buf, t_info *info_stru);

int				shift_up(char **piece, t_info *info_stru);
int				shift_left(char **piece, t_info *info_stru, int up);
int				shift_get1st(char **piece, t_info *info_stru, int up);
char			**shift_all(char **piece, t_info *info_stru);

int				parse_map(t_info *info_stru);

#endif
