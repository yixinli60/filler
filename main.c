/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:09:13 by yli               #+#    #+#             */
/*   Updated: 2017/03/14 19:59:47 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include "libft.h"

int	main(int ac, char **av)
{
	int		fd;
	int		num;
	char	*res;

	num = 0;
	fd = 0;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putnbr(fd);
			ft_putstr("\nfile does not exist\n");
		}
		else
		{
			while ((num = get_next_line(fd, &res)))
			{
				printf("\e[31mwhile loop av:\n\e[0m%s\n", res);
				printf("%d\n\n", num);
				if (num < 0)
					break ;
			}
			num = get_next_line(fd, &res);
			printf("\e[31mav:\n\e[0m%s\n", res);
			printf("%d\n\n", num);
			num = get_next_line(fd, &res);
			printf("\e[31mav:\n\e[0m%s\n", res);
			printf("%d\n\n", num);
		}
		close(fd);
	}
	else
	{
		ft_putnbr(fd);
		ft_putstr("\nno input file\n");
	}
}
