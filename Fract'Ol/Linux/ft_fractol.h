/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Affiche des fractales.                                                 */
/*   • ./a.out [ 1/2 ] [ a/b/c/d ] [static]                                   */
/*      -> 1: julia, 2: mandelbrot                                            */
/*      -> For julia:          a: The Anchor, b: The Kiss, c: The Void        */
/*      -> For mandelbrot:    a: Killua,        b: Spaceship,                 */
/*                            c: Irruption,     d: Evergreen                  */
/*      -> Ajouter le flag `static` permet d'enlever le color shift.          */
/* ************************************************************************** */
#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

// Standard Libraries

# include <unistd.h>
# include <stdlib.h>

// strerror, errno
# include <string.h>
# include <errno.h>

# include <math.h>

// My libraries

// minilibX
# include "minilibx_linux/mlx.h"
# include <X11/X.h>

# include "Get_Next_Line/get_next_line.h"
# include "Printf_fd/ft_printf.h"

# include "ft_macros.h"

// Structures

typedef struct s_fract		t_fract;
typedef struct s_img		t_img;
typedef struct s_cam		t_cam;
typedef struct s_core		t_core;
typedef struct s_complex	t_complex;

typedef struct s_fract
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_cam		*cam;
	t_core		*core;
	t_complex	*cplx;
}	t_fract;

typedef struct s_img
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			size;
	int			endian;
}	t_img;

typedef struct s_cam
{
	double		zoom;
	double		offset_x;
	double		offset_y;
	double		real;
	double		i;
}	t_cam;

typedef struct s_core
{
	int			first_color;
	int			second_color;
	int			reset;
	int			iteration;
	int			statik;
	int			flg;
	char		flg_iter;
	char		set;
}	t_core;

typedef struct s_complex
{
	// real
	double		x;
	double		y;
	// imaginary
}	t_complex;

//	----------MY CODE----------

// ft_fractol.c

int			ft_loop_hook(t_fract *fract);
int			ft_close_window(t_fract *fract);
void		ft_error(t_fract *fract, int error);
void		ft_init(t_fract **fract);

// ft_fractol_next.c

void		ft_parse_arguments(t_fract *fract, int argc, char **argv);
void		ft_parse_arguments_next(t_fract *fract, int argc, char **argv);
void		ft_parse_arguments_3(t_fract *fract, int argc, char **argv);
void		ft_help(t_fract *fract);

// ft_fractol_2.c

void		ft_fractol(t_fract *fract);
void		ft_set_fractol(t_fract *fract);
void		ft_pixel_put(t_img *img, int x, int y, int color);
void		ft_free_fract(t_fract *fract);

// ft_mandelbrot.c

void		ft_mandelbrot(t_fract *fract, int x, int y);
void		ft_draw_mandelbrot(t_fract *fract);
void		ft_options_mandelbrot(t_fract *fract, char **argv);

// ft_julia.c

void		ft_julia(t_fract *fract, int x, int y);
void		ft_draw_julia(t_fract *fract);
void		ft_options_julia(t_fract *fract, char **argv);

// ft_math.c

double		ft_scale(double n, double new_min, double new_max, double old_max);
int			ft_gradient(t_fract *fract, int iteration);
int			ft_inverse(double x, int a, double n);
t_complex	ft_sum_cplx(t_complex z, t_complex c);
t_complex	ft_square_cplx(t_complex z);

// ft_macros.c

int			ft_key_hook(int keycode, t_fract *fract);
void		ft_key_zoom_and_precision(int keycode, t_fract *fract);
void		ft_key_translate(int keycode, t_fract *fract);

// ft_macros_next.c

int			ft_mouse_hook(int button, int x, int y, t_fract *fract);
int			ft_mouse_tracker(int x, int y, t_fract *fract);
int			ft_mouse_tracker_next(int x, int y, t_fract *fract);

// ft_lib.c

void		*ft_calloc(size_t count, size_t size);
char		*ft_strlowcase(char *str);
int			ft_strcmp(const char *s1, const char *s2);

#endif
