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
#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

/*
 * NOTE:
 * - La minilibx sur MacOS n'a pas été entièrement développé et c'est pour cette
 *	raison qu'il y a 1 leak de 32 bytes non atteignable dû au comportement
 *	de la lib.
 */

// Standard Libraries

# include <unistd.h>
# include <stdlib.h>

// strerror, errno
# include <string.h>
# include <errno.h>

# include <math.h>

// My libraries

// minilibX
# include "minilibx_macos/mlx.h"
// # include <X11/X.h>

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
}	t_cam;

typedef struct s_core
{
	int			reset;
	int			iteration;
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

void		ft_parse_arguments(t_fract *fract, char **argv);
void		ft_help(t_fract *fract);

// ft_fractol_2.c
void		ft_fractol(t_fract *fract);
void		ft_draw_fractol(t_fract *fract);
void		ft_free_fract(t_fract *fract);

// ft_mandelbrot.c

void		ft_mandelbrot(t_fract *fract, t_complex *cplx, int x, int y);
t_complex	ft_sum_cplx(t_complex z, t_complex c);
t_complex	ft_square_cplx(t_complex z);
void		ft_pixel_put(t_img *img, int x, int y, int color);

// ft_math.c

double		ft_scale(double n, double new_min, double new_max,
				double old_min, double old_max);
int			ft_gradient(t_fract *fract, int iteration);

// ft_macros.c

int			ft_key_hook(int keycode, t_fract *fract);
int			ft_mouse_hook(int button, int x, int y, t_fract *fract);
void		ft_key_zoom_and_precision(int keycode, t_fract *fract);
void		ft_key_translate(int keycode, t_fract *fract);

// ft_lib.c

void		*ft_calloc(size_t count, size_t size);
char		*ft_strlowcase(char *str);
int			ft_strcmp(const char *s1, const char *s2);

#endif
