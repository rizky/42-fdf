/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 02:23:58 by rnugroho          #+#    #+#             */
/*   Updated: 2018/05/11 04:10:25 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		line(t_mlx *mlx, t_vector p1, t_vector p2)
{
	t_line	line;

	p1.x = (int)p1.x;
	p2.x = (int)p2.x;
	p1.y = (int)p1.y;
	p2.y = (int)p2.y;
	line.start = p1;
	line.stop = p2;
	if (!lineclip(&p1, &p2))
		return ;
	line.dx = (int)ft_abs((int)p2.x - (int)p1.x);
	line.sx = (int)p1.x < (int)p2.x ? 1 : -1;
	line.dy = (int)ft_abs((int)p2.y - (int)p1.y);
	line.sy = (int)p1.y < (int)p2.y ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while (((int)p1.x != (int)p2.x || (int)p1.y != (int)p2.y))
		if (line_process_point(mlx, &line, &p1, &p2))
			break ;
}

int
	main(int argc, char **argv)
{
	int c;

	while ((c = ft_getopt(argc, argv, "ab:c:")) != -1)
		ft_printf("option %c %s\n", c, g_optarg ? g_optarg : "(none)");
	c = g_optind;
	while (c < argc)
	{
		ft_printf("non-opt: %s\n", argv[c]);
		c++;
	}
	return (0);
}
