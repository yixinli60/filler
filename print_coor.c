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
	ft_printf("%d %d\n", i_stu->final_row, i_stu->final_col);
	i_stu->final_row = -10;
	i_stu->final_col = -10;
	free_stuff(i_stu);
	return (0);
}
