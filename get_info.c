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

int	get_map(char *buf, t_info *info_stru)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(info_stru->row * sizeof(char*));
	while (i < info_stru->row)
	{
		get_next_line(0, &buf);
		map[i] = malloc(info_stru->col * sizeof(char));
		ft_strcpy(map[i], buf + 4);
		dprintf(2, "||%s||\n", map[i]);
		i++;
	}
	return (0);
}

int	get_piece_info(char *buf, t_info *info_stru)
{
	char	**info;
	char	**piece;
	int		i;

	i = 0;
	info = ft_strsplit(buf, ' ');
	info_stru->piece_row = ft_atoi(info[1]);
	info_stru->piece_col = ft_atoi(info[2]);
	free(info);
	piece = malloc(info_stru->piece_row * sizeof(char*));
	while (i < info_stru->piece_row)
	{
		get_next_line(0, &buf);
		piece[i] = malloc(info_stru->piece_col * sizeof(char));
		piece[i] = ft_strdup(buf);
		i++;
	}
	i = 0;
	while (i < info_stru->piece_row) //prints piece row by row
	{
		dprintf(2, "[[%s]]\n", piece[i]);
		i++;
	}
	shift_all(piece, info_stru);
	return (0);
}
