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

int		main(int ar, char **av)
{
//	void	*pt;
//	void	*wnd;
//
	t_gen	*gen;

	gen = NULL;
	if (ar < 2)
	{
		ft_usage(av[0]);
		return (0);
	}
	gen = ft_memalloc(sizeof(t_gen));
//	gen = (t_gen *)malloc(sizeof(t_gen)); //test
	read_map(av[1], gen);
	ft_printf("%d\n", gen->raw->hight);//test
	ft_printf("%d\n", gen->raw->width);//test


//	pt = mlx_init();
//	wnd = mlx_new_window(pt, 500, 500, "fdf");
//	mlx_loop(pt);
	return (0);
}
