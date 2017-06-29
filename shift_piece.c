/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 13:58:02 by yli               #+#    #+#             */
/*   Updated: 2017/06/22 14:08:29 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		shift_get1st(char **piece, t_info *i_stu, int up)
{
	int	i;
	int	j;
	int	first;

	i = up;
	j = 0;
	first = 0;
	while (j < i_stu->xy.p_col)
	{
		if (piece[i][j] == '*')
		{
			first = j;
			i_stu->xy.f_row = i;
			i_stu->xy.f_col = j;
			break ;
		}
		j++;
	}
	return (first);
}

int		shift_left(char **piece, t_info *i_stu, int up)
{
	int	i;
	int	j;

	i = up + 1;
	i_stu->xy.left = shift_get1st(piece, i_stu, up);
	while (i < i_stu->xy.p_row)
	{
		j = 0;
		while (j < i_stu->xy.p_col)
		{
			if (piece[i][j] == '*')
			{
				if (i_stu->xy.left > j)
					i_stu->xy.left = j;
			}
			j++;
		}
		i++;
	}
	return (i_stu->xy.left);
}

int		shift_up(char **piece, t_info *i_stu)
{
	int	i;
	int	j;

	i = 0;
	while (i < i_stu->xy.p_row)
	{
		j = 0;
		while (j < i_stu->xy.p_col)
		{
			if (piece[i][j] == '*')
				return (i_stu->xy.up = i);
			j++;
		}
		i++;
	}
	return (i_stu->xy.up = i);
}

char	**shift_all(char **piece, t_info *i_stu)
{
	int	up;
	int	left;
	int row;
	int col;

	row = 0;
	up = shift_up(piece, i_stu);
	left = shift_left(piece, i_stu, up);
	if (up == 0 && left == 0)
		return (get_piece_size(piece, i_stu));
	while (row < i_stu->xy.p_row)
	{
		col = 0;
		while (col < i_stu->xy.p_col)
		{
			if (piece[row][col] == '*')
			{
				piece[row - up][col - left] = '*';
				piece[row][col] = '.';
			}
			col++;
		}
		row++;
	}
	return (get_piece_size(piece, i_stu));
}

char	**get_piece_size(char **piece, t_info *i_stu)
{
	int	row;
	int	col;

	i_stu->xy.p_x = 0;
	i_stu->xy.p_y = 0;
	row = i_stu->xy.p_row - 1;
	while (row >= 0)
	{
		col = 0;
		while (col < i_stu->xy.p_col)
		{
			if (piece[row][col] == '*')
			{
				if (row > i_stu->xy.p_x)
					i_stu->xy.p_x = row;
				if (col > i_stu->xy.p_y)
					i_stu->xy.p_y = col;
			}
			col++;
		}
		row--;
	}
	i_stu->xy.p_x = i_stu->xy.p_x + 1;
	i_stu->xy.p_y = i_stu->xy.p_y + 1;
	//dprintf(2, "\nactual piece size %d %d\n\n", i_stu->xy.p_x, i_stu->xy.p_y);
	return (piece);
}
