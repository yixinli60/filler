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
	info_stru->row = ft_atoi(string[1]);
	info_stru->col = ft_atoi(string[2]);
	free(string);
	return (0);
}

int	save_map_to_struc(char *buf, t_info *info_stru)
{
	int		i;

	i = 0;
	info_stru->map = malloc(info_stru->row * sizeof(char*));
	while (i < info_stru->row)
	{
		get_next_line(0, &buf);
		info_stru->map[i] = malloc(info_stru->col * sizeof(char));
		ft_strcpy(info_stru->map[i], buf + 4);
		i++;
	}
	i = 0;
	while (i < info_stru->row) //prints piece row by row
	{
		dprintf(2, "//%s//\n", info_stru->map[i]);
		i++;
	}
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
		info_stru->piece[i] = malloc(info_stru->piece_col * sizeof(char));
		info_stru->piece[i] = ft_strdup(buf);
		i++;
	}
	i = 0;
	while (i < info_stru->piece_row) //prints piece row by row
	{
		dprintf(2, "//%s//\n", info_stru->piece[i]);
		i++;
	}
	shift_all(info_stru->piece, info_stru);
	parse_map(info_stru);
	/*i = 0;
	while (i < info_stru->row) //prints piece row by row
	{
		dprintf(2, "//%s//\n", info_stru->map[i]);
		i++;
	}
	dprintf(2, "\n");
	*/
	return (0);
}

int	parse_map(t_info *info_stru)
{
	int		row;
	int		col;

	row = 0;
	if (info_stru->plr == '1')
	{
		while (row < info_stru->row)
		{
			col = 0;
			while (col < info_stru->col)
			{
				if (info_stru->map[row][col] == 'O')
				{
					info_stru->final_row = row - info_stru->up;
					info_stru->final_col = col - info_stru->left;
					return (0);
				}
				col++;
			}
			row++;
		}
	}
	return (0);
}
