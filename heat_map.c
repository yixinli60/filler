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

int clean_map(t_info *i_stu)
{
  int r;
	int c;

	r = 0;
	while (r < i_stu->map_row)
	{
		c = 0;
		while (c < i_stu->map_col)
		{
      if (i_stu->map[r][c] == '.')
      {
        i_stu->map[r][c] = 1;
        //find_enemy(i_stu, 'X', r, c);
        //if ((ft_absval(i_stu->xy.enemy_x - r) + ft_absval(i_stu->xy.enemy_y - c)) >= 2)
      }
      else if (i_stu->map[r][c] == i_stu->emy)
      {
        i_stu->map[r][c] = 9;
        i_stu->big = 9;
      }
      c++;
		}
		r++;
	}
/*
  int i = 0;
  while (i < i_stu->map_row) //prints row by row
  {
    int j = 0;
    while (j < i_stu->map_col)
    {
      if (i_stu->map[i][j] <= 9)
        dprintf(2, "%d", i_stu->map[i][j]);
      else
        dprintf(2, "%c", i_stu->map[i][j]);
      j++;
    }
    dprintf(2, "\n");
    i++;
  }
  dprintf(2, "\n");
*/
	return (0);
}

int heat_map(t_info *i_stu)
{
  int r;
  int c;

  while (i_stu->big >= 2)
  {
    r = 0;
    while (r < i_stu->map_row)
    {
      c = 0;
      while (c < i_stu->map_col)
      {
        if (i_stu->map[r][c] == i_stu->big)
        {
          if (((r - 1) >= 0) && i_stu->map[r - 1][c] < i_stu->big)
            i_stu->map[r - 1][c] = i_stu->map[r][c] / 1.5;
          if (((r + 1) < i_stu->map_row) && i_stu->map[r + 1][c] < i_stu->big)
            i_stu->map[r + 1][c] = i_stu->map[r][c] / 1.5;
          if (((c - 1) >= 0) && i_stu->map[r][c - 1] < i_stu->big)
            i_stu->map[r][c - 1] = i_stu->map[r][c] / 1.5;
          if (((c + 1) < i_stu->map_col) && i_stu->map[r][c + 1] < i_stu->big)
            i_stu->map[r][c + 1] = i_stu->map[r][c] / 1.5;
        }
        c++;
      }
      r++;
    }
    i_stu->big = i_stu->big / 1.5;
  }
  i_stu->big = 9;

  int i = 0;
  while (i < i_stu->map_row) //prints row by row
  {
    int j = 0;
    while (j < i_stu->map_col)
    {
      if (i_stu->map[i][j] <= 9)
        dprintf(2, "%d", i_stu->map[i][j]);
      else
          dprintf(2, "%c", i_stu->map[i][j]);
      j++;
    }
    dprintf(2, "\n");
    i++;
  }
  dprintf(2, "\n");

  return (0);
}

int heat_map2(t_info *i_stu)
{
  int r;
  int c;

  r = 0;
  while (r < i_stu->map_row)
  {
    c = 0;
    while (c < i_stu->map_col)
    {
      if (i_stu->map[r][c] == 6)
      {
        if (((r - 1) >= 0) && i_stu->map[r - 1][c] < 6)
          i_stu->map[r - 1][c] = i_stu->map[r][c] / 1.5;
        if (((r + 1) < i_stu->map_row) && i_stu->map[r + 1][c] < 6)
          i_stu->map[r + 1][c] = i_stu->map[r][c] / 1.5;
        if (((c - 1) >= 0) && i_stu->map[r][c - 1] < 6)
          i_stu->map[r][c - 1] = i_stu->map[r][c] / 1.5;
        if (((c + 1) < i_stu->map_col) && i_stu->map[r][c + 1] < 6)
          i_stu->map[r][c + 1] = i_stu->map[r][c] / 1.5;
      }
      c++;
    }
    r++;
  }
  return (0);
}

int heat_map3(t_info *i_stu)
{
  int r;
  int c;

  r = 0;
  while (r < i_stu->map_row)
  {
    c = 0;
    while (c < i_stu->map_col)
    {
      if (i_stu->map[r][c] == 4)
      {
        if (((r - 1) >= 0) && i_stu->map[r - 1][c] < 4)
          i_stu->map[r - 1][c] = i_stu->map[r][c] / 1.5;
        if (((r + 1) < i_stu->map_row) && i_stu->map[r + 1][c] < 4)
          i_stu->map[r + 1][c] = i_stu->map[r][c] / 1.5;
        if (((c - 1) >= 0) && i_stu->map[r][c - 1] < 4)
          i_stu->map[r][c - 1] = i_stu->map[r][c] / 1.5;
        if (((c + 1) < i_stu->map_col) && i_stu->map[r][c + 1] < 4)
          i_stu->map[r][c + 1] = i_stu->map[r][c] / 1.5;
      }
      c++;
    }
    r++;
  }

  int i = 0;
  while (i < i_stu->map_row) //prints row by row
  {
    int j = 0;
    while (j < i_stu->map_col)
    {
      if (i_stu->map[i][j] <= 9)
        dprintf(2, "%d", i_stu->map[i][j]);
      else
          dprintf(2, "%c", i_stu->map[i][j]);
      j++;
    }
    dprintf(2, "\n");
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
