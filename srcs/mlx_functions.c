/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:34:58 by msymkany          #+#    #+#             */
/*   Updated: 2018/03/21 19:35:00 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		to_exit_x(t_gen *gen)
{
	ft_strdel(&gen->img_str);
	exit(1);
	return (0);
}

void	put_pixel_to_image(t_gen *gen, int x, int y, int color)
{
	unsigned int	c;
	int				j;

	c = mlx_get_color_value(gen->ptr, color);
	j = y * gen->len + x * gen->bpp / 8;
	gen->img_str[j] = (c & 0xFF);
	gen->img_str[++j] = (c & 0xFF00) >> 8;
	gen->img_str[++j] = (c & 0xFF0000) >> 16;
}

void	draw_image(t_gen *gen)
{
	mlx_destroy_image(gen->ptr, gen->img);
	gen->img = mlx_new_image(gen->ptr, WINW, WINH);
	gen->img_str = mlx_get_data_addr(gen->img, &gen->bpp, &gen->len, &gen->en);
	draw_it_all(gen);
	mlx_put_image_to_window(gen->ptr, gen->wnd, gen->img, 0, 0);
}

void	draw_frst_image(t_gen *gen)
{
	gen->img_str = mlx_get_data_addr(gen->img, &gen->bpp, &gen->len, &gen->en);
	rotate_x(gen, -0.7);
	rotate_y(gen, -0.4);
}

int		move_map(int key, t_gen *gen)
{
	if (key == 53)
		exit(0);
	else if (key == 36)
		draw_frst_image(gen);
	else if (key == 124)
		move_it(gen, 3, 0);
	else if (key == 123)
		move_it(gen, -3, 0);
	else if (key == 126)
		move_it(gen, 0, -3);
	else if (key == 125)
		move_it(gen, 0, 3);
	else if (key == 6)
		rotate_z(gen, 0.02);
	else if (key == 7)
		rotate_z(gen, -0.02);
	else if (key == 0)
		rotate_x(gen, 0.02);
	else if (key == 1)
		rotate_x(gen, -0.02);
	else if (key == 12)
		rotate_y(gen, 0.02);
	else if (key == 13)
		rotate_y(gen, -0.02);
	return (0);
}
