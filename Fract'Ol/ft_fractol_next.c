/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

// --------------------PROTOTYPE--------------------
void		ft_fractol(t_fract *fract, t_img *img);
void		ft_fractol_next(t_fract *fract);
void		ft_help(t_fract *fract);
// -------------------------------------------------

void	ft_fractol(t_fract *fract, t_img *img)
{
	img->ptr = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->ptr,
			&img->bpp, &img->size, &img->endian);
	ft_fractol_next(fract);
	// mlx_hook(fdf->win, 2, 0, ft_key_hook, fdf);
	return ;
}

void	ft_fractol_next(t_fract *fract)
{
	return ;
}

void	ft_help(t_fract *fract)
{
	ft_printf(1, "\033[92m./fractol [sets] [version]\033[0m\n\n");
	ft_printf(1, "sets:\t\t[1] julia\t[2] mandelbrot\n");
	ft_printf(1, "version:\t[a] classic\t[b] colored\t[c] fade\n");
	ft_printf(1, "\n=>   do `make help` for more.   <=\n");
}
