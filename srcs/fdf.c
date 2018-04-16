/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:09:33 by msymkany          #+#    #+#             */
/*   Updated: 2018/02/26 20:12:26 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	center_it(t_raw *raw)
{
	size_t		i;
	size_t		j;
	double		x;
	double		y;

	i = 0;
	x = raw->cor[raw->hight - 1][raw->width - 1].x / 2;
	y = raw->cor[raw->hight - 1][raw->width - 1].y / 2;
	while (i < raw->hight)
	{
		j = 0;
		while (j < raw->width)
		{
			raw->cor[i][j].y = raw->cor[i][j].y - y;
			raw->cor[i][j].x = raw->cor[i][j].x - x;
			j++;
		}
		i++;
	}
}

t_gen	*validate_map(int ar, char **av, t_gen *gen)
{
	int		fd;

	if (ar < 2)
	{
		ft_usage(av[0]);
		return (gen);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		ft_printf("Error: invalid file\n");
		return (gen);
	}
	gen = ft_memalloc(sizeof(t_gen));
	gen->raw = ft_memalloc(sizeof(t_raw));
	gen->raw->clr = (ar > 3 && ft_strequ(av[2], "-c")) ? get_col(av[3]) : DCOL;
	if (read_map(gen->raw, fd, gen->step))
	{
		free(gen);
		gen = NULL;
		ft_printf("Error: invalid map\n");
		return (gen);
	}
	(gen->raw->hight)++;
	center_it(gen->raw);
	return (gen);
}

int		main(int ar, char **av)
{
	t_gen	*gen;

	gen = NULL;
	gen = validate_map(ar, av, gen);
	if (gen == NULL)
		return (1);
	gen->ptr = mlx_init();
	gen->wnd = mlx_new_window(gen->ptr, WINW, WINH, "fdf");
	gen->img = mlx_new_image(gen->ptr, WINW, WINH);
	gen->img_str = mlx_get_data_addr(gen->img, &gen->bpp, &gen->len, &gen->en);
	mlx_string_put(gen->ptr, gen->wnd, 30, 30, 0xED2323, "Control keys");
	mlx_string_put(gen->ptr, gen->wnd, 30, 50, 0xFFFFFF,
				"Move (up, down, left, right): use arrows");
	mlx_string_put(gen->ptr, gen->wnd, 30, 70, 0xFFFFFF, "Rotate:");
	mlx_string_put(gen->ptr, gen->wnd, 30, 90, 0xFFFFFF, "Z       keys z, x");
	mlx_string_put(gen->ptr, gen->wnd, 30, 110, 0xFFFFFF, "X       keys a, s");
	mlx_string_put(gen->ptr, gen->wnd, 30, 130, 0xFFFFFF, "Y       keys q, w");
	mlx_string_put(gen->ptr, gen->wnd, 30, 150, 0xFFFFFF,
				"Press Enter to start");
	mlx_string_put(gen->ptr, gen->wnd, 30, 170, 0xFFFFFF, "Press Esc to exit");
	mlx_hook(gen->wnd, 17, 1L << 17, to_exit_x, gen);
	mlx_hook(gen->wnd, 2, 5, move_map, gen);
	mlx_loop(gen->ptr);
	return (0);
}
