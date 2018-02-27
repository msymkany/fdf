/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:18:26 by msymkany          #+#    #+#             */
/*   Updated: 2018/02/26 20:18:31 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/libftprintf.h"
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/**
open, read, write, close
malloc, free
perror, strerror
exit
All the functions defined in the math library (-lm and man 3 math)
All the functions defined in the miniLibX library. **/

typedef struct 			s_coord
{
	double				x;
	double				y;
	double				z;
	int 				col;
}						t_coord;

typedef struct 			s_gen
{
	t_coord				**cor;

}						t_gen;


void	ft_usage(char *name);
