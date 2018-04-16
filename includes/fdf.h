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
# include <math.h>

# define MAXMAP 1000
# define WINH 1000
# define WINW 1000
# define MARG (WINW / 5)
# define IMGW (WINW - MARG)
# define DCOL 0XE3BEF7
# define DCOL2 0X7bb1f7

/*
** open, read, write, close
** malloc, free
** perror, strerror
** exit
** All the functions defined in the math library (-lm and man 3 math)
** All the functions defined in the miniLibX library.
*/

typedef struct s_coord	t_coord;
typedef struct s_cor	t_cor;
typedef struct s_raw	t_raw;
typedef struct s_gen	t_gen;
typedef struct s_bres	t_bres;

typedef struct 		s_bres
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				d;
	int				d1;
	int				d2;
}					t_bres;

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
	int 			clr;
}					t_raw;

/*
** move
** 1 - right
** 2 - left
** 4 - up
** 8 - down
** 16 - rot z
** 32 - rot y
*/

typedef struct 		s_gen
{
	t_raw			*raw;
    t_cor           c0;
    t_cor           c1;
	void			*ptr;
	void			*wnd;
	void			*img;
	char			*img_str;
	int 			bpp;
	int 			len;
	int 			en;
	int				j;
	int				step;
}					t_gen;


void		ft_usage(char *name);
int 		get_col(char *str);
int			read_map(t_raw *raw, int fd, int step);
int         to_exit_x(t_gen *gen);
void	    draw_it_all(t_gen *gen);
void		put_pixel_to_image(t_gen *gen, int x, int y, int color);
int 		move_map(int key, t_gen *gen);
void		move_it(t_gen *gen, int x, int y);
void		rotate_z(t_gen *gen, float an);
void		rotate_x(t_gen *gen, float an);
void		rotate_y(t_gen *gen, float an);
void		draw_image(t_gen *gen);

#endif