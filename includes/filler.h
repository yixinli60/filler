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
# include "include/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>


typedef struct s_coor
{
	int	f_row;
	int	f_col;
	int	p_row;
	int	p_col;
	int	up;
	int	left;
	int	p_x;
	int	p_y;
}				t_coor;

typedef struct	s_info
{
	char	plr;
	int		map_row;
	int		map_col;
	char	**map;
	int		final_row;
	int		final_col;
	char	**piece;
	t_coor xy;
}				t_info;

int				get_map_info(char *buf, t_info *i_stu);
int				save_map_to_struc(char *buf, t_info *i_stu);
int				get_piece_info(char *buf, t_info *i_stu);
char			**get_piece_size(char **piece, t_info *i_stu);

int				shift_up(char **piece, t_info *i_stu);
int				shift_left(char **piece, t_info *i_stu, int up);
int				shift_get1st(char **piece, t_info *i_stu, int up);
char			**shift_all(char **piece, t_info *i_stu);

int				parse_map(t_info *i_stu);
int				plr_o(t_info *i_stu);
int				plr_x(t_info *i_stu);
int				loop_opiece(t_info *i_stu, int t_row, int t_col);
int				loop_xpiece(t_info *i_stu, int t_row, int t_col);

int				heat_omap(t_info *i_stu);
int				print_coor(t_info *i_stu);

#endif
