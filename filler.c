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
	t_info	info_stru;
	char	*buf;

	ft_memset(&info_stru, 0, sizeof(info_stru));
	while (get_next_line(0, &buf) > 0)
	{
		if (ft_strnequ(buf, "$", 1))
			info_stru.plr = buf[10];
		else if (ft_strnequ(buf, "Pl", 2))
			get_map_info(buf, &info_stru);
		else if (ft_strnequ(buf, "    ", 4))
			save_map_to_struc(buf, &info_stru);
		else if (ft_strnequ(buf, "Pi", 2))
		{
			get_piece_info(buf, &info_stru);
			//dprintf(2, "//%d %d//\n", info_stru.final_row, info_stru.final_col);
			//printf("%d %d\n", info_stru.final_row, info_stru.final_col);
			printf("8 2\n");

		}
		else
			return (0);
	}
	return (0);
}
