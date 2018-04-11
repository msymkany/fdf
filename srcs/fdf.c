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
			raw->cor[i][j].y = raw->cor[i][j].y - y + WINH / 2;// + MARG / 2;
			raw->cor[i][j].x = raw->cor[i][j].x - x + WINW / 2;// + MARG / 2;
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
	if (read_map(gen->raw, fd))
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
	{
		ft_printf("Error\n"); //test
		return (1);
	}
	printf("gen->raw->clr %X ", gen->raw->clr); //test
	printf("marg %d ", MARG); //test
	gen->ptr = mlx_init();
	gen->wnd = mlx_new_window(gen->ptr, WINW, WINH, "fdf");
	gen->img = mlx_new_image(gen->ptr, WINW, WINH);
	gen->img_str = mlx_get_data_addr(gen->img, &gen->bpp, &gen->len, &gen->en);
	mlx_string_put(gen->ptr, gen->wnd, 1, 1, 16777215, "Hello"); //test
	mlx_key_hook(gen->wnd, key_hook, gen);
	mlx_hook(gen->wnd, 17, 1L << 17, to_exit_x, gen);
//	printf("move_it");
	mlx_hook (gen->wnd, 2, 5, move_map, gen);
	mlx_loop(gen->ptr);
	return (0);
}
