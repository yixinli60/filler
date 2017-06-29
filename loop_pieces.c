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
	return (0);
}

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
			if (loop_xpiece(i_stu, row, col) == 1)
			{
				i_stu->final_row = row - i_stu->xy.up;
				i_stu->final_col = col - i_stu->xy.left;
				return (0);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	loop_opiece(t_info *i_stu, int t_r, int t_c)
{
	int	r;
	int	c;
	int	overlap;
	int	tp_c;

	tp_c = t_c;
	overlap = 0;
	r = 0;
	while (r < i_stu->xy.p_x)
	{
		tp_c = t_c;
		c = 0;
		while (c < i_stu->xy.p_y)
		{
			if ((i_stu->piece[r][c] == '*') && (i_stu->map[t_r][tp_c] == 'X'))
				return (-1);
			if ((i_stu->piece[r][c] == '*') && (i_stu->map[t_r][tp_c] == 'O'))
				overlap++;
			tp_c++;
			c++;
		}
		t_r++;
		r++;
	}
	return (overlap);
}

int	loop_xpiece(t_info *i_stu, int t_r, int t_c)
{
	int	r;
	int	c;
	int	overlap;
	int	tp_c;

	tp_c = t_c;
	overlap = 0;
	r = 0;
	while (r < i_stu->xy.p_x)
	{
		tp_c = t_c;
		c = 0;
		while (c < i_stu->xy.p_y)
		{
			if ((i_stu->piece[r][c] == '*') && (i_stu->map[t_r][tp_c] == 'O'))
				return (-1);
			if ((i_stu->piece[r][c] == '*') && (i_stu->map[t_r][tp_c] == 'X'))
				overlap++;
			tp_c++;
			c++;
		}
		t_r++;
		r++;
	}
	return (overlap);
}
