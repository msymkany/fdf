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
//	void	*pt;
//	void	*wnd;
	t_gen	*gen;

	gen = NULL;
	gen = validate_map(ar, av, gen);
	if (gen == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
//	ft_printf("%d\n", gen->raw->hight);//test
//	ft_printf("%d\n", gen->raw->width);//test


//	pt = mlx_init();
//	wnd = mlx_new_window(pt, 500, 500, "fdf");
//	mlx_loop(pt);
	return (0);

}
