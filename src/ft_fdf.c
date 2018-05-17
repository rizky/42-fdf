/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 02:23:58 by rnugroho          #+#    #+#             */
/*   Updated: 2018/05/17 12:51:21 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void *mlx;
void *win;

int
	fdf_handle_mouse(int x, int y, int button)
{
	ft_printf("Mouse event - new win x:%d y:%d button:%d\n", x, y, button);
	mlx_mouse_hook(win, fdf_handle_mouse, 0);
	return (0);
}

int
	main(void)
{
	srandom(time(0));
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "win");
	mlx_mouse_hook(win, fdf_handle_mouse, 0);
	mlx_loop(mlx);
	return (0);
}
