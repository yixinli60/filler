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

int	print_coor(t_info *i_stu)
{
	//char	*string;

	//dprintf(2, "%d %d\n", i_stu->final_row, i_stu->final_col);
	ft_printf("%d %d\n", i_stu->final_row, i_stu->final_col);
	/*
	string = ft_itoa(i_stu->final_row);
	write(1, string, ft_strlen(string));
	write(1, " ", 1);
	string = ft_itoa(i_stu->final_col);
	write(1, string, ft_strlen(string));
	write(1, "\n", 1);
	*/
	return (0);
}
