/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

// --------------------PROTOTYPE--------------------
void		ft_mandelbrot(t_fract *fract, int x, int y);
void		ft_draw_mandelbrot(t_fract *fract);
// -------------------------------------------------

/*	Mandelbrot Part:
 *
 *	Z0 = 0
 *	Zn+1 = (Zn)² + C
 *
 *	Good Spot:
 *
 *	BLK->WHITE: 240: The Spectrum ; 252: Killua ; 254: Spaceship
 *	BLK->RED: 80: Evergreen ; 85: Irruption
 *	WHITE->BLK: 85: Deus ; 80: Vulvix ; 145: Fireball ; 240: Mastermind
 */
void	ft_mandelbrot(t_fract *fract, int x, int y)
{
	int			i;
	int			color;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = (ft_scale(x, -2, +2, 0, WIDTH) * fract->cam->zoom)
		+ fract->cam->offset_x;
	c.y = (ft_scale(y, -2, +2, 0, HEIGHT) * fract->cam->zoom)
		+ fract->cam->offset_y;
	while (i < fract->core->iteration)
	{
		z = ft_sum_cplx(ft_square_cplx(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = ft_scale(i, WHITE, BLACK, 0, fract->core->iteration);
			ft_pixel_put(fract->img, x, y, color);
			return ;
		}
		i++;
	}
	ft_pixel_put(fract->img, x, y, BLACK);
}

void	ft_draw_mandelbrot(t_fract *fract)
{
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_mandelbrot(fract, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img->ptr, 0, 0);
}
