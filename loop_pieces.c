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

int	loop_map(t_info *i_stu)
{
	int	row;
	int	col;
	int	sum;

	sum = 0;
	row = 0;
	while (row < (i_stu->map_row - (i_stu->xy.p_x - 1)))
	{
		col = 0;
		while (col < (i_stu->map_col - (i_stu->xy.p_y - 1)))
		{
			sum = loop_piece(i_stu, row, col);
			if (sum >= i_stu->sum)
			{
				i_stu->final_row = row - i_stu->xy.up;
				i_stu->final_col = col - i_stu->xy.left;
				i_stu->sum = sum;
			}
			col++;
		}
		row++;
	}
	i_stu->sum = 0;
	return (0);
}

int	loop_piece(t_info *i_stu, int x, int y)
{
	int	r;
	int	c;
	int	overlap;
	int sum;

	overlap = 0;
	r = 0;
	sum = 0;
	while (r < i_stu->xy.p_x)
	{
		c = -1;
		while (++c < i_stu->xy.p_y)
		{
			if ((i_stu->piece[r][c] == '*') && (i_stu->map[x][c + y] == 9))
				return (-1);
			if ((i_stu->piece[r][c] == '*') &&
				(i_stu->map[x][c + y] == i_stu->plr))
				overlap++;
			else if (i_stu->piece[r][c] == '*')
				sum = sum + i_stu->map[x][c + y];
		}
		x++;
		r++;
	}
	return (overlap == 1 ? sum : -1);
}
