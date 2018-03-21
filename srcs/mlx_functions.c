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

int 	key_hook(int key_code, t_gen *gen)
{
	ft_printf("key hook\n");
//	key_code = ft_atoi(read)
	if (key_code == 53 || key_code == 49)
	{
		mlx_string_put(gen->ptr, gen->wnd, 10, 10, 0X00FFFFFF, "Fuck off");
		sleep(10);
		exit(0);
	}
	return (0);
}