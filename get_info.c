/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 19:51:12 by yli               #+#    #+#             */
/*   Updated: 2017/06/21 19:51:17 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int get_map_info(char *buf, t_info *info_stru)
{
	char	**string;

	string = ft_strsplit(buf, ' ');
	info_stru->row = ft_atoi(string[1]);
	info_stru->col = ft_atoi(string[2]);
	free(string);
	return (0);
}

int get_map(char *buf, t_info *info_stru)
{
	char	**map;
	int		i;

	i = 0;
	//dprintf(2, "%d\n", info_stru->row);
	//dprintf(2, "%d\n", info_stru->col);
	map = malloc(info_stru->row * sizeof(char*));
	while (i < info_stru->row)
	{
		get_next_line(0, &buf);
		map[i] = malloc(info_stru->col * sizeof(char));
		ft_strcpy(map[i], buf + 4);
		//dprintf(2, "||%s||\n", map[i]);
		i++;
	}
	return (0);
}

int	get_piece_info(char *buf, t_info *info_stru)
{
	char	**info;
	char	**piece;
	int		i;
  int   up;
  int   left;

  i = 0;
	info = ft_strsplit(buf, ' ');
	info_stru->piece_row = ft_atoi(info[1]);
	info_stru->piece_col = ft_atoi(info[2]);
	//dprintf(2, "|r is %d|\n", info_stru->piece_row);
	//dprintf(2, "|c is %d|\n", info_stru->piece_col);
	free(info);
	piece = malloc(info_stru->piece_row * sizeof(char*));
	while (i < info_stru->piece_row)
	{
		get_next_line(0, &buf);
		piece[i] = malloc(info_stru->piece_col * sizeof(char));
		piece[i] = ft_strdup(buf);
		i++;
	}
	i = 0;
	while (i < info_stru->piece_row) //prints piece row by row
	{
		dprintf(2, "[[%s]]\n", piece[i]);
		i++;
	}
  up = shift_up(piece, info_stru);
  left = shift_left(piece, info_stru, up);
  dprintf(2, "[[need to shift up %d]]\n", up);
  dprintf(2, "[[need to shift left %d]]\n", left);
	return (0);
}
int shift_left(char **piece, t_info *info_stru, int up)
{
  int i;
  int j;
//  int left;

  i = up;
  j = 0;
//  left = 0;
  while (i < info_stru->piece_row)
  {
    while (j < info_stru->piece_col)
    {
      if (piece[i][j] == '*')
      {
        return(j);
      //  left = j;
        i++;
      }
      j++;
    }
    j = 0;
  }
  return (j);
}

int shift_up(char **piece, t_info *info_stru)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while (i < info_stru->piece_row)
  {
    while (j < info_stru->piece_col)
    {
      if (piece[i][j] == '*')
        return(i);
      j++;
    }
    i++;
    j = 0;
  }
  return (0);
}
