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

void		put_pixel_to_image(t_gen *gen, int x, int y, int color)
{
	unsigned int	c;
	int 			j;

	c = mlx_get_color_value(gen->ptr, color);
	j = y * gen->len + x * gen->bpp / 8;
	gen->img_str[j] = (c & 0xFF0000) >> 16;
	gen->img_str[++j] = (c & 0xFF00) >> 8;
	gen->img_str[++j] = (c & 0xFF);
}

void	draw_image(t_gen *gen)
{
	int 	j;

	gen->bpp = 0;
	gen->len = 0;
	gen->endn = 0;
	j = 0;
	gen->img_str = mlx_get_data_addr(gen->img, &gen->bpp, &gen->len, &gen->endn);
	ft_printf("bpp: %d\n", gen->bpp); //test
	ft_printf("len: %d\n", gen->len); //test
	ft_printf("end: %d\n", gen->endn); //test
    draw_it_all(gen);
//	while (j < WINW)
//	{
//		put_pixel_to_image(gen, j, 3, 0XFFFFFF);
//		j++;
//	}
//	mlx_put_image_to_window(gen->ptr, gen->wnd, gen->img, 0, 4);
}

int 	key_hook(int key_code, t_gen *gen)
{
	ft_printf("key hook\n");
//	key_code = ft_atoi(read)
	if (key_code == 53) //|| key_code == 49)
	{
//		mlx_string_put(gen->ptr, gen->wnd, 10, 10, 0X00FFFFFF, "Fuck off");
//		sleep(10);
		exit(0);
	}
	else if (key_code == 36)
	{
		draw_image(gen);
	}
	return (0);
}