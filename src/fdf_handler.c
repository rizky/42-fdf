/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:01:09 by rnugroho          #+#    #+#             */
/*   Updated: 2018/05/17 14:01:51 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int
	fdf_handle_mouse(int button, int x, int y)
{
	ft_printf("Mouse event - new win x:%d y:%d button:%d\n", x, y, button);
	return (0);
}

int
	fdf_handle_keydown(int key, t_mlx *mlx)
{
	fdf_free(mlx);
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
