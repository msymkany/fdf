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

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/libftprintf.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h> //test
#include <math.h>

#define MAXMAP 100
#define WINH 1000
#define WINW 1000

/*
** open, read, write, close
** malloc, free
** perror, strerror
** exit
** All the functions defined in the math library (-lm and man 3 math)
** All the functions defined in the miniLibX library.
*/

typedef double	t_vector __attribute__((vector_size(sizeof(double)*3)));
typedef struct s_coord	t_coord;
typedef struct s_cor	t_cor;
typedef struct s_raw	t_raw;
typedef struct s_gen	t_gen;

typedef struct 		s_cor
{
	double			x;
	double			y;
	int 			col;
}					t_cor;

typedef struct 		s_coord
{
	double			x;
	double			y;
	double			z;
	int 			col;
}					t_coord;

typedef struct 		s_raw
{
	t_coord			cor[MAXMAP][MAXMAP];
	size_t			hight;
	size_t			width;
}					t_raw;

typedef struct 		s_gen
{
	t_raw			*raw;
	void			*ptr;
	void			*wnd;
	void			*img;
	int 			bpp;
	int 			len;
	int 			endn;
	char			*img_str;
	int 			not_over;
}					t_gen;


void		ft_usage(char *name);
int			read_map(t_raw *raw, int fd);
int 		key_hook(int key_code, t_gen *gen);

#endif