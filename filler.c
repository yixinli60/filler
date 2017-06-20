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
#include "src/libft/libft.h"

int	main()
{
	t_info info_stru;
	char	*buf;
	char	**string;
	int		row;
	int		col;
	int		p;

	ft_memset(&info_stru, 0, sizeof(info_stru));
	while (get_next_line(0, &buf) > 0)
	{
		if (ft_strnequ(buf, "$$$ exec ", 9))
		{
			p = ft_atoi(&buf[10]);
			info_stru.plr = p;
			dprintf(2, "|player is %d|\n", info_stru.plr);
		}
		if (ft_strnequ(buf, "Plateau ", 8))
		{
			string = ft_strsplit(buf, ' ');
			row = ft_atoi(string[1]);
			col = ft_atoi(string[2]);
			dprintf(2, "|row is %d|\n", row);
			dprintf(2, "|col is %d|\n", col);
		}
		//ft_putstr_fd(buf, 2);
		//dprintf(2, "\n");
		//return (0);
	}
	printf("8 2");
	return (0);
}
