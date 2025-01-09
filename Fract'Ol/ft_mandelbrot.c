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
void		ft_mandelbrot(t_fract *fract, t_complex *cplx, int x, int y);
t_complex	ft_sum_cplx(t_complex z, t_complex c);
t_complex	ft_square_cplx(t_complex z);
void		ft_pixel_put(t_img *img, int x, int y, int color);
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
void	ft_mandelbrot(t_fract *fract, t_complex *cplx, int x, int y)
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

// Additionne des nombres complexes.
t_complex	ft_sum_cplx(t_complex z, t_complex c)
{
	t_complex	res;

	res.x = z.x + c.x;
	res.y = z.y + c.y;
	return (res);
}

/*
 * real: (x^2 - y^2)
 * i: 2xy
 */
t_complex	ft_square_cplx(t_complex z)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}

// Fonction d'ajout de pixel pour mlx_new_image.
void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char		*pixel;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pixel = img->addr + (y * img->size + x * (img->bpp / 8));
	*(int *)pixel = color;
}
