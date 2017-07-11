/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 20:31:49 by yli               #+#    #+#             */
/*   Updated: 2017/07/10 17:09:48 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int	clean_map(t_info *i_stu)
{
	int	r;
	int	c;

	r = 0;
	while (r < i_stu->map_row)
	{
		c = 0;
		while (c < i_stu->map_col)
		{
			if (i_stu->map[r][c] == '.')
				i_stu->map[r][c] = 0;
			else if (i_stu->map[r][c] == i_stu->emy)
			{
				i_stu->map[r][c] = 9;
				i_stu->big = 9;
			}
			c++;
		}
		r++;
	}
	return (0);
}

int	heat_map(t_info *i_stu)
{
	int	r;
	int	c;

	while (i_stu->big >= 2)
	{
		r = 0;
		while (r < i_stu->map_row)
		{
			c = 0;
			while (c < i_stu->map_col)
			{
				if (i_stu->map[r][c] == i_stu->big)
					label_nbr(i_stu, r, c);
				c++;
			}
			r++;
		}
		i_stu->big = i_stu->big / 1.5;
	}
	i_stu->big = 9;
	return (0);
}

int	label_nbr(t_info *i_stu, int r, int c)
{
	if (((r - 1) >= 0) && i_stu->map[r - 1][c] < i_stu->big)
		i_stu->map[r - 1][c] = i_stu->map[r][c] / 1.5;
	if (((r + 1) < i_stu->map_row) && i_stu->map[r + 1][c] < i_stu->big)
		i_stu->map[r + 1][c] = i_stu->map[r][c] / 1.5;
	if (((c - 1) >= 0) && i_stu->map[r][c - 1] < i_stu->big)
		i_stu->map[r][c - 1] = i_stu->map[r][c] / 1.5;
	if (((c + 1) < i_stu->map_col) && i_stu->map[r][c + 1] < i_stu->big)
		i_stu->map[r][c + 1] = i_stu->map[r][c] / 1.5;
	return (0);
}

int	free_stuff(t_info *i_stu)
{
	int	row;

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
