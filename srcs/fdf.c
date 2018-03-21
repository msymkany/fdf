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

t_gen		*validate_map(int ar, char **av, t_gen *gen)
{
	int 	fd;

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
	if (read_map(gen->raw, fd))
	{
		free(gen);
		gen = NULL;
		ft_printf("Error: invalid map\n");
		return (gen);
	}
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
	gen->not_over = 1;
	gen->ptr = mlx_init();
	gen->wnd = mlx_new_window(gen->ptr, WINLEN, WINHIGHT, "fdf");
	mlx_string_put(gen->ptr, gen->wnd, 1, 1, 16777215, "Hello");
	mlx_key_hook(gen->wnd, key_hook, gen);
	mlx_loop(gen->ptr);
	//test
//	while (gen->not_over)
//	{
//		mlx_string_put(gen->ptr, gen->wnd, 1, 1, 16777215, "Hello");
//		mlx_loop(gen->ptr);
//		mlx_pixel_put(gen->ptr, gen->wnd, 1, 1, 16711935);
//		mlx_key_hook(gen->wnd, key_hook, gen);
//	}
	return (0);
}
