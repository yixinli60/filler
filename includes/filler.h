/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 16:05:48 by yli               #+#    #+#             */
/*   Updated: 2017/06/19 16:05:49 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"
# include <unistd.h>
# include <stdlib.h>



# include <stdio.h>


typedef struct s_info
{
  char  plr;
  int   row;
  int   col;
  int   piece_row;
  int   piece_col;
}       t_info;

int get_map_info(char *buf, t_info *info_stru);
int get_map(char *buf, t_info *info_stru);
int get_piece_info(char *buf, t_info *info_stru);

int shift_up(char **piece, t_info *info_stru);
int shift_left(char **piece, t_info *info_stru, int up);

#endif
