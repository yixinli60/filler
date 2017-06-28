/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 19:51:12 by yli               #+#    #+#             */
/*   Updated: 2017/06/22 14:09:34 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int	get_map_info(char *buf, t_info *info_stru)
{
	char	**string;

	string = ft_strsplit(buf, ' ');
	info_stru->map_row = ft_atoi(string[1]);
	info_stru->map_col = ft_atoi(string[2]);
	free(string);
	return (0);
}

int	save_map_to_struc(char *buf, t_info *info_stru)
{
	int	i;

	i = 0;
	info_stru->map = malloc(info_stru->map_row * sizeof(char*));
	while (i < info_stru->map_row)
	{
		get_next_line(0, &buf);
		info_stru->map[i] = malloc(info_stru->map_col * sizeof(char) + 1);
		ft_strcpy(info_stru->map[i], buf + 4);
		info_stru->map[i][info_stru->map_col] = '\0';
		ft_strtoupper(info_stru->map[i]);
		i++;
	}
/*
	i = 0;
	while (i < info_stru->map_row)
	{
		dprintf(2, "%02d %s\n", i, info_stru->map[i]);
		i++;
	}
	dprintf(2, "\n");
*/
	return (0);
}

int	get_piece_info(char *buf, t_info *info_stru)
{
	char	**info;
	int		i;

	i = 0;
	info = ft_strsplit(buf, ' ');
	info_stru->piece_row = ft_atoi(info[1]);
	info_stru->piece_col = ft_atoi(info[2]);
	free(info);
	info_stru->piece = malloc(info_stru->piece_row * sizeof(char*));
	while (i < info_stru->piece_row)
	{
		get_next_line(0, &buf);
		info_stru->piece[i] = malloc(info_stru->piece_col * sizeof(char) + 1);
		ft_strcpy(info_stru->piece[i], buf);
		info_stru->piece[i][info_stru->piece_col] = '\0';
		i++;
	}
	//shift_all(info_stru->piece, info_stru);
/*
	i = 0;
	while (i < info_stru->piece_row) //prints piece row by row
	{
		dprintf(2, "||%s||\n", info_stru->piece[i]);
		i++;
	}
*/
	parse_map(info_stru);
	return (0);
}

int	parse_map(t_info *info_stru)
{
	if (info_stru->plr == '1')
		plr_O(info_stru);
	else
		plr_X(info_stru);
	return (0);
}

int	plr_O(t_info *info_stru)
{
	int	row;
	int	col;

	row = 0;
	//dprintf(2, "prow %d\n", info_stru->piece_row);
	//dprintf(2, "pcol %d\n", info_stru->piece_col);
	while (row < (info_stru->map_row - (info_stru->piece_row - 1)))
	{
		col = 0;
		while (col < (info_stru->map_col - (info_stru->piece_col - 1)))
		{
			//dprintf(2, "row before loop %d\n", row);
			//dprintf(2, "col before loop %d\n", col);
			if (loop_piece(info_stru, row, col) == 1)
			{
				info_stru->final_row = row;
				info_stru->final_col = col;
				return (0);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	plr_X(t_info *info_stru)
{
	int	row;
	int	col;

	row = 0;
	while (row < info_stru->map_row)
	{
		col = 0;
		while (col < info_stru->map_col)
		{
			if (info_stru->map[row][col] == 'X') //find first X
			{
				info_stru->final_row = row - info_stru->first_row;
				info_stru->final_col = col - info_stru->first_col;
				return (0);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int loop_piece(t_info *info_stru, int t_row, int t_col)
{
	int	row;
	int	col;
	int	overlap;
	int tmp_col;

	tmp_col = t_col;
	overlap = 0;
	row = 0;
	while (row < info_stru->piece_row)
	{
		tmp_col = t_col;
		col = 0;
		while (col < info_stru->piece_col)
		{
			//dprintf(2, "row %d\n", row);
			//dprintf(2, "col %d\n", col);
			//dprintf(2, "map row %d\n", t_row);
			//dprintf(2, "map col %d\n", t_col);
			if ((info_stru->piece[row][col] == '*') && (info_stru->map[t_row][tmp_col] == 'X'))
				return (-1);
			if ((info_stru->piece[row][col] == '*') && (info_stru->map[t_row][tmp_col] == 'O'))
			{
				//dprintf(2, "at map row %d\n", t_row);
				//dprintf(2, "at map col %d\n", t_col);
				//dprintf(2, "row %d\n", row);
				//dprintf(2, "col %d\n", col);
				overlap++;
			}
			tmp_col++;
			col++;
		}
		t_row++;
		row++;
	}
	//dprintf(2, "overlap %d\n\n", overlap);
	return (overlap);
}
