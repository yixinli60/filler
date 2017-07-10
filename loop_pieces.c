/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_pieces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 11:20:35 by yli               #+#    #+#             */
/*   Updated: 2017/06/28 11:37:07 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int	plr_o(t_info *i_stu)
{
	int	row;
	int	col;

	row = 0;

	//dprintf(2, "enemy is %d\n", enemy_r);
	//dprintf(2, "her %d %d\n", i_stu->xy.p_x, i_stu->xy.p_y);
	while (row < (i_stu->map_row - (i_stu->xy.p_x - 1)))
	{
		col = 0;
		while (col < (i_stu->map_col - (i_stu->xy.p_y - 1)))
		{
			if (loop_piece(i_stu, row, col) == 1)
			{
				i_stu->final_row = row - i_stu->xy.up;
				i_stu->final_col = col - i_stu->xy.left;
				return (0);
			}

			//check_dist(i_stu, row, col);
			col++;
		}
		row++;
	}
	return (0);
}

/*
int	plr_x(t_info *i_stu)
{
	int	row;
	int	col;

	row = 0;
	while (row < (i_stu->map_row - (i_stu->xy.p_x - 1)))
	{
		col = 0;
		while (col < (i_stu->map_col - (i_stu->xy.p_y - 1)))
		{
			if (loop_opiece(i_stu, row, col) == 1)
			{
				i_stu->final_row = row - i_stu->xy.up;
				i_stu->final_col = col - i_stu->xy.left;
				return (0);
			}
			col++;
		}
		row++;
	}
	i_stu->final_row = 0;
	i_stu->final_col = 0;
	return (0);
}
*/

int	loop_piece(t_info *i_stu, int t_r, int t_c)
{
	int	r;
	int	c;
	int	overlap;
	int	tp_c;

	tp_c = t_c;
	overlap = 0;
	r = 0;
	//dprintf(2, "%d %d\n", i_stu->xy.p_x, i_stu->xy.p_y);
	while (r < i_stu->xy.p_x)
	{
		tp_c = t_c;
		c = 0;
		while (c < i_stu->xy.p_y)
		{
			if ((i_stu->piece[r][c] == '*') && (i_stu->map[t_r][tp_c] == 9))
				return (-1);
			if ((i_stu->piece[r][c] == '*') && (i_stu->map[t_r][tp_c] == i_stu->plr))
				overlap++;
			tp_c++;
			c++;
		}
		t_r++;
		r++;
	}
	return (overlap);
}

int	check_dist(t_info *i_stu, int row, int col)
{
	int dist = 0;
	if (loop_piece(i_stu, row, col) == 1 && i_stu->dist == -1)
	{
		i_stu->dist = ft_absval(i_stu->xy.enemy_x - row) + ft_absval(i_stu->xy.enemy_y - col);
		//dprintf(2, "enemy %d %d\n", i_stu->xy.enemy_x, i_stu->xy.enemy_y);
		//dprintf(2, "row col %d %d\n", row, col);
		//dprintf(2, "get first dist %d\n", i_stu->dist);
		i_stu->final_row = row - i_stu->xy.up;
		i_stu->final_col = col - i_stu->xy.left;
		//dprintf(2, "initial row %d\n", i_stu->final_row);
		//dprintf(2, "initial col %d\n\n", i_stu->final_col);
	}
	else if (loop_piece(i_stu, row, col) == 1 && i_stu->dist != -1)
	{
		dist = ft_absval(i_stu->xy.enemy_x - row) + ft_absval(i_stu->xy.enemy_y - col);
		//dprintf(2, "old i_stu dist %d\n", i_stu->dist);
		//dprintf(2, "new dist %d\n", dist);
		if (i_stu->dist > dist)
		{
			i_stu->dist = dist;
			i_stu->final_row = row - i_stu->xy.up;
			i_stu->final_col = col - i_stu->xy.left;
			//dprintf(2, "new dist %d\n", i_stu->dist);
			//dprintf(2, "new row %d\n", i_stu->final_row);
			//dprintf(2, "new col %d\n\n", i_stu->final_col);
		}
		else
		{
			i_stu->final_row = row - i_stu->xy.up;
			i_stu->final_col = col - i_stu->xy.left;
			//dprintf(2, "when i_stu->dist < dist row %d\n", i_stu->final_row);
			//dprintf(2, "when i_stu->dist < dist col %d\n\n", i_stu->final_col);
			i_stu->dist = -1;
		}
	}
	return (0);
}
