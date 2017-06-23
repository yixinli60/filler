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

int	shift_get1st(char **piece, t_info *info_stru, int up)
{
	int	i;
	int	j;
	int	first;

	i = up;
	j = 0;
	first = 0;
	while (j < info_stru->piece_col)
	{
		if (piece[i][j] == '*')
		{
			first = j;
			break ;
		}
		j++;
	}
	return (first);
}

int	shift_left(char **piece, t_info *info_stru, int up)
{
	int	i;
	int	j;
	int	first;

	i = up + 1;
	first = shift_get1st(piece, info_stru, up);
	while (i < info_stru->piece_row)
	{
		j = 0;
		while (j < info_stru->piece_col)
		{
			if (piece[i][j] == '*')
			{
				if (first > j)
					first = j;
			}
			j++;
		}
		i++;
	}
	return (first);
}

int	shift_up(char **piece, t_info *info_stru)
{
	int	i;
	int	j;

	i = 0;
	while (i < info_stru->piece_row)
	{
		j = 0;
		while (j < info_stru->piece_col)
		{
			if (piece[i][j] == '*')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

char	**shift_all(char **piece, t_info *info_stru)
{
	int		up;
	int		left;

	up = shift_up(piece, info_stru);
	left = shift_left(piece, info_stru, up);
	dprintf(2, "[[need to shift up %d]]\n", up);
	dprintf(2, "[[need to shift left %d]]\n", left);
	return (0);
}
