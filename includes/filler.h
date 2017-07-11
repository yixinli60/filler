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
	char	emy;
	int		map_row;
	int		map_col;
	char	**map;
	char	**piece;
	int		final_row;
	int		final_col;
	int		sum;
	int		big;
	t_coor xy;
}				t_info;

int				get_plr(char *buf, t_info *i_stu);
int				get_map_info(char *buf, t_info *i_stu);
int				save_map_to_struc(char *buf, t_info *i_stu);
int				get_piece_info(char *buf, t_info *i_stu);

int				shift_get1st(char **piece, t_info *i_stu, int up);
int				shift_left(char **piece, t_info *i_stu, int up);
int				shift_up(char **piece, t_info *i_stu);
char			**shift_all(char **piece, t_info *i_stu);
char			**get_piece_size(char **piece, t_info *i_stu);

int				loop_map(t_info *i_stu);
int				loop_piece(t_info *i_stu, int t_row, int t_col);

int				clean_map(t_info *i_stu);
int				heat_map(t_info *i_stu);
int				label_nbr(t_info *i_stu, int r, int c);

int				print_coor(t_info *i_stu);
int				free_stuff(t_info *i_stu);

#endif
