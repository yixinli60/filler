/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 19:26:44 by yli               #+#    #+#             */
/*   Updated: 2017/06/15 19:26:53 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int	main(void)
{
	t_info	i_stu;
	char	*buf;

	ft_memset(&i_stu, -1, sizeof(i_stu));
	while (get_next_line(0, &buf) > 0)
	{
		if (ft_strnequ(buf, "$", 1))
			get_plr(buf, &i_stu);
		else if (ft_strnequ(buf, "Pl", 2))
			get_map_info(buf, &i_stu);
		else if (ft_strnequ(buf, "    ", 4))
			save_map_to_struc(buf, &i_stu);
		else if (ft_strnequ(buf, "Pi", 2))
		{
			clean_map(&i_stu);
			heat_map(&i_stu);
			get_piece_info(buf, &i_stu);
			print_coor(&i_stu);
			free_stuff(&i_stu);
		}
		else
			return (0);
	}
	return (0);
}
