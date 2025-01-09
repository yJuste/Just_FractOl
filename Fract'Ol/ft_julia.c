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
	c.x = -0.8;
	c.y = +0.156;
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
