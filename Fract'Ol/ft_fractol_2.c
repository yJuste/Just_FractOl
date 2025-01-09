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
void		ft_set_fractol(t_fract *fract);
void		ft_pixel_put(t_img *img, int x, int y, int color);
void		ft_free_fract(t_fract *fract);
// -------------------------------------------------

void	ft_fractol(t_fract *fract)
{
	fract->core->iteration = 50;
	fract->cam->zoom = 1.0;
	fract->cam->offset_x = 0;
	fract->cam->offset_y = 0;
	ft_set_fractol(fract);
}

void	ft_set_fractol(t_fract *fract)
{
	if (fract->core->set == 'm')
		ft_draw_mandelbrot(fract);
	else if (fract->core->set == 'j')
		ft_draw_julia(fract);
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

//	----------GOTO FREE----------

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
