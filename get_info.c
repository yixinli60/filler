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

int	get_plr(char *buf, t_info *i_stu)
{
	if (buf[10] == '1')
	{
		i_stu->plr = 'O';
		i_stu->emy = 'X';
	}
	else
	{
		i_stu->plr = 'X';
		i_stu->emy = 'O';
	}
	return (0);
}

int	get_map_info(char *buf, t_info *i_stu)
{
	char	**string;

	string = ft_strsplit(buf, ' ');
	i_stu->map_row = ft_atoi(string[1]);
	i_stu->map_col = ft_atoi(string[2]);
	free(string);
	return (0);
}

int	save_map_to_struc(char *buf, t_info *i_stu)
{
	int	i;

	i = 0;
	if (!(i_stu->map = malloc(i_stu->map_row * sizeof(char*))))
		return (0);
	while (i < i_stu->map_row)
	{
		get_next_line(0, &buf);
		if (!(i_stu->map[i] = malloc(i_stu->map_col * sizeof(char) + 1)))
			return (0);
		ft_strcpy(i_stu->map[i], buf + 4);
		i_stu->map[i][i_stu->map_col] = '\0';
		ft_strtoupper(i_stu->map[i]);
		i++;
	}
	return (0);
}

int	get_piece_info(char *buf, t_info *i_stu)
{
	char	**info;
	int		i;

	i = 0;
	info = ft_strsplit(buf, ' ');
	i_stu->xy.p_row = ft_atoi(info[1]);
	i_stu->xy.p_col = ft_atoi(info[2]);
	free(info);
	if (!(i_stu->piece = malloc(i_stu->xy.p_row * sizeof(char*))))
		return (0);
	while (i < i_stu->xy.p_row)
	{
		get_next_line(0, &buf);
		if (!(i_stu->piece[i] = malloc(i_stu->xy.p_col * sizeof(char) + 1)))
			return (0);
		ft_strcpy(i_stu->piece[i], buf);
		i_stu->piece[i][i_stu->xy.p_col] = '\0';
		i++;
	}
	shift_all(i_stu->piece, i_stu);
	loop_map(i_stu);
	return (0);
}
