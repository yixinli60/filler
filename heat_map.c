/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 20:31:49 by yli               #+#    #+#             */
/*   Updated: 2017/06/28 20:31:50 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int heat_omap(t_info *i_stu)
{
  int r;
	int c;
	int overlap;

	overlap = 0;
	r = 0;
	while (r < i_stu->map_row)
	{
		c = 0;
		while (c < i_stu->map_col)
		{
      if (i_stu->map[r][c] == '.')
      {
        find_enemy(i_stu, 'X', r, c);
        if ((ft_absval(i_stu->xy.enemy_x - r) + ft_absval(i_stu->xy.enemy_y - c)) >= 2)
          i_stu->map[r][c] = '-';
      }
      c++;
		}
		r++;
	}
  int i = 0;
  while (i < i_stu->map_row) //prints row by row
  {
    dprintf(2, "||%s||\n", i_stu->map[i]);
    i++;
  }
  dprintf(2, "\n");
	return (0);
}

int find_enemy(t_info *i_stu, char enemy, int x, int y)
{
  int r;
  int c;
  int dist;

  r = 0;
  x = 0;
  y = 0;
	while (r < i_stu->map_row)
  {
    c = 0;
    dist = 10000;
    while (c < i_stu->map_col)
    {
      if (i_stu->map[r][c] == enemy)
      {
        //if (dist >= (ft_absval(r - x) + ft_absval(c - y)))
        //{
          i_stu->xy.enemy_x = r;
          i_stu->xy.enemy_y = c;
        //}
        return (r);
      }
      c++;
    }
  	r++;
  }
  return (0);
}

int free_stuff(t_info *i_stu)
{
  int row;

  row = 0;
  while (row < i_stu->map_row)
  {
    free(i_stu->map[row]);
    row++;
  }
  free(i_stu->map);
  row = 0;
  while (row < i_stu->xy.p_row)
  {
    free(i_stu->piece[row]);
    row++;
  }
  free(i_stu->piece);
  return (0);
}
