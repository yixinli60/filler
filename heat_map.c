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
			if (i_stu->map[r][c] == 'X')
      {
        if (i_stu->map[r][c - 1] == '.')
          i_stu->map[r][c - 1] = '1';
        if (i_stu->map[r][c + 1] == '.')
          i_stu->map[r][c + 1] = '1';
        if (i_stu->map[r + 1][c] == '.')
          i_stu->map[r + 1][c] = '1';
        if (i_stu->map[r - 1][c] == '.')
          i_stu->map[r - 1][c] = '1';
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

int find_x(t_info *i_stu)
{
  int row;
  int col;

  row = 0;
	while (row < i_stu->map_row)
  {
    col = 0;
    while (col < i_stu->map_col)
    {
      if (i_stu->map[row][col] == 'X')
        return (row);
        col++;
    }
  	row++;
  }
  return (0);
}

int find_o(t_info *i_stu)
{
  int row;
  int col;

  row = 0;
	while (row < i_stu->map_row)
  {
    col = 0;
    while (col < i_stu->map_col)
    {
      if (i_stu->map[row][col] == 'O')
        return (row);
        col++;
    }
  	row++;
  }
  return (0);
}
