/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

// --------------------PROTOTYPE--------------------
void		ft_julia(t_fract *fract, int x, int y);
void		ft_draw_julia(t_fract *fract);
void		ft_options_julia(t_fract *fract, char **argv);
// -------------------------------------------------

/*	Julia Part:
 *
 *	Z0 = 0
 *	Zn+1 = (Zn)² + C
 */
void	ft_julia(t_fract *fract, int x, int y)
{
	int			i;
	int			color;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.x = (ft_scale(x, -2, +2, 0, WIDTH) * fract->cam->zoom)
		+ fract->cam->offset_x;
	z.y = (ft_scale(y, -2, +2, 0, HEIGHT) * fract->cam->zoom)
		+ fract->cam->offset_y;
	c.x = fract->cam->real;
	c.y = fract->cam->i;
	while (i < fract->core->iteration)
	{
		z = ft_sum_cplx(ft_square_cplx(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = ft_scale(i, fract->core->first_color,
					fract->core->second_color, 0, fract->core->iteration);
			ft_pixel_put(fract->img, x, y, color);
			return ;
		}
		i++;
	}
	ft_pixel_put(fract->img, x, y, BLACK);
}

// Dessine les points de Julia.
void	ft_draw_julia(t_fract *fract)
{
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_julia(fract, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img->ptr, 0, 0);
}

void	ft_options_julia(t_fract *fract, char **argv)
{
	if (ft_strcmp(argv[2], "a") == 0)
	{
		fract->core->iteration = 500;
		fract->core->first_color = BLACK;
		fract->core->second_color = BLUE;
		fract->cam->real = 0.285;
		fract->cam->i = 0.013;
	}
	else if (ft_strcmp(argv[2], "b") == 0)
	{
		fract->core->iteration = 60;
		fract->core->first_color = WHITE;
		fract->core->second_color = BLACK;
		fract->cam->real = -0.4;
		fract->cam->i = 0.6;
	}
	else if (ft_strcmp(argv[2], "c") == 0)
	{
		fract->core->iteration = 85;
		fract->core->first_color = BLACK;
		fract->core->second_color = WHITE;
		fract->cam->real = -1.476;
		fract->cam->i = 0;
	}
}
