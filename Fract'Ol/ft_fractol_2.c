/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

// --------------------PROTOTYPE--------------------
void		ft_fractol(t_fract *fract);
void		ft_draw_fractol(t_fract *fract);
void		ft_free_fract(t_fract *fract);
// -------------------------------------------------

void	ft_fractol(t_fract *fract)
{
	fract->core->iteration = 50;
	fract->cam->zoom = 1.0;
	fract->cam->offset_x = 0;
	fract->cam->offset_y = 0;
	ft_draw_fractol(fract);
}

void	ft_draw_fractol(t_fract *fract)
{
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_mandelbrot(fract, fract->cplx, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img->ptr, 0, 0);
}

// Libére toutes les variables dans fractol.
/* Ne pas ajouter cette ligne si mlx_destroy_display() n'existe pas.
 *	if (fract->mlx)
 *		free(fract->mlx);
 */
void	ft_free_fract(t_fract *fract)
{
	if (fract->img->ptr)
		mlx_destroy_image(fract->mlx, fract->img->ptr);
	if (fract->win)
		mlx_destroy_window(fract->mlx, fract->win);
	free(fract->img);
	free(fract->cam);
	free(fract->core);
	free(fract->cplx);
}
