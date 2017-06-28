/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_coor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:13:35 by yli               #+#    #+#             */
/*   Updated: 2017/06/26 16:13:36 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int	print_coor(t_info *info_stru)
{
	char	*string;

	string = ft_itoa(info_stru->final_row);
	//dprintf(2, "%d %d\n", info_stru->final_row, info_stru->final_col);
	write(1, string, ft_strlen(string));
	write(1, " ", 1);
	string = ft_itoa(info_stru->final_col);
	write(1, string, ft_strlen(string));
	write(1, "\n", 1);
	//dprintf(1, "%d %d\n", info_stru.final_row, info_stru.final_col);
	return (0);
}
