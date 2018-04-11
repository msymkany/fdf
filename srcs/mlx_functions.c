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

int     to_exit_x(t_gen *gen)
{
    ft_strdel(&gen->img_str);
    system("leaks fdf");
    exit(1);
    return (0);
}

void		put_pixel_to_image(t_gen *gen, int x, int y, int color)
{
	unsigned int	c;
	int 			j;

	c = mlx_get_color_value(gen->ptr, color);
	j = y * gen->len + x * gen->bpp / 8;
	gen->img_str[j] = (c & 0xFF);
	gen->img_str[++j] = (c & 0xFF00) >> 8;
	gen->img_str[++j] = (c & 0xFF0000) >> 16;
}

void	draw_image(t_gen *gen)
{

//	gen->bpp = 0;
//	gen->len = 0;
//	gen->en = 0;
//	ft_printf("bpp: %d\n", gen->bpp); //test
//	ft_printf("len: %d\n", gen->len); //test
//	ft_printf("end: %d\n", gen->en); //test
//	mlx_clear_window(gen->ptr, gen->wnd);
//	ft_bzero(gen->img_str, sizeof(gen->img_str));
	mlx_destroy_image(gen->ptr, gen->img);
	gen->img = mlx_new_image(gen->ptr, WINW, WINH);
	gen->img_str = mlx_get_data_addr(gen->img, &gen->bpp, &gen->len, &gen->en);
	draw_it_all(gen);
	mlx_put_image_to_window(gen->ptr, gen->wnd, gen->img, 0, 0);
}

int 	key_hook(int key_code, t_gen *gen)
{
	ft_printf("key hook\n"); //test
	if (key_code == 53)
	{
//		mlx_string_put(gen->ptr, gen->wnd, 10, 10, 0X00FFFFFF, "Fuck off");
//		sleep(10);
        ft_strdel(&gen->img_str);
        system("leaks fdf");
		exit(0);
	}
	else if (key_code == 36)
	{
		draw_image(gen);
	}
	return (0);
}

int 	move_map(int key, t_gen *gen)
{
//	printf("move_it");
	if (key == 124)
	{
		move_it(gen, 3, 0);
	}
	else if (key == 123)
		move_it(gen, -3, 0);
	else if (key == 126)
		move_it(gen, 0, -3);
	else if (key == 125)
		move_it(gen, 0, 3);
	else if (key == 50)
		rotate_z(gen, 10);
//		mlx_clear_window(gen->ptr, gen->wnd);
	draw_image(gen);
//		mlx_string_put(gen->ptr, gen->wnd, 20, j++, 0XFFFFFF, "<-");
	return (0);
}