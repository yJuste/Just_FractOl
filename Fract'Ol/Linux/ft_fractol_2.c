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
/*   • Initialise la fractale choisie.                                        */
/* ************************************************************************** */
#include "ft_fractol.h"

// ---------------------------PROTOTYPE---------------------------
void		ft_fractol(t_fract *fract);
void		ft_set_fractol(t_fract *fract);
void		ft_pixel_put(t_img *img, int x, int y, int color);
void		ft_free_fract(t_fract *fract);
// ---------------------------------------------------------------

// Fonction principale de fractol.
void	ft_fractol(t_fract *fract)
{
	if (fract->core->flg_iter == '0')
	{
		fract->core->iteration = 50;
		fract->core->first_color = WHITE;
		fract->core->second_color = BLACK;
		fract->cam->real = -0.8;
		fract->cam->i = 0.156;
	}
	fract->cam->zoom = 1.0;
	fract->cam->offset_x = 0;
	fract->cam->offset_y = 0;
	ft_set_fractol(fract);
}

// Met le type de fractol par rapport au parsing.
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
void	ft_free_fract(t_fract *fract)
{
	if (fract->img->ptr)
		mlx_destroy_image(fract->mlx, fract->img->ptr);
	if (fract->win)
		mlx_destroy_window(fract->mlx, fract->win);
	if (fract->mlx)
		mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	free(fract->img);
	free(fract->cam);
	free(fract->core);
	free(fract->cplx);
	free(fract);
}
