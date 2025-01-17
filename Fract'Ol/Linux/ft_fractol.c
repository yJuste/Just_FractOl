/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
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
#include "ft_fractol.h"

// ----------------------PROTOTYPE----------------------
int			ft_loop_hook(t_fract *fract);
int			ft_close_window(t_fract *fract);
void		ft_error(t_fract *fract, int error);
void		ft_init(t_fract **fract);
// -----------------------------------------------------

int	main(int argc, char **argv)
{
	t_fract		*fract;

	fract = NULL;
	if (argc >= 2 && argc <= 4)
	{
		ft_init(&fract);
		ft_parse_arguments(fract, argc, argv);
		fract->mlx = mlx_init();
		fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT,
				"Just'FractOl");
		fract->img->ptr = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
		fract->img->addr = mlx_get_data_addr(fract->img->ptr, &fract->img->bpp,
				&fract->img->size, &fract->img->endian);
		ft_fractol(fract);
		mlx_hook(fract->win, 2, 1L << 0, ft_key_hook, fract);
		mlx_hook(fract->win, 17, 1L << 17, ft_close_window, fract);
		mlx_hook(fract->win, 6, 1L << 6, ft_mouse_tracker, fract);
		mlx_mouse_hook(fract->win, ft_mouse_hook, fract);
		mlx_loop_hook(fract->mlx, ft_loop_hook, fract);
		mlx_loop(fract->mlx);
	}
	else
		return (ft_help(fract), 2);
	return (0);
}

// Applique les modifs de mlx_hook.
int	ft_loop_hook(t_fract *fract)
{
	if (fract->core->flg_iter == '0')
		fract->core->iteration += 2;
	ft_set_fractol(fract);
	return (0);
}

// Ferme la fenêtre.
int	ft_close_window(t_fract *fract)
{
	if (fract)
		ft_free_fract(fract);
	ft_printf(1, "Window closed\n");
	exit(2);
	return (0);
}

// Fonction d'erreur.
void	ft_error(t_fract *fract, int error)
{
	if (fract)
		ft_free_fract(fract);
	ft_printf(2, "%s\n", strerror(error));
	exit(error);
}

// 1. Alloue de la mémoire pour chaque structure.
// 2. Met toutes les variables à 0.
void	ft_init(t_fract **fract)
{
	*fract = ft_calloc(1, sizeof(t_fract));
	(*fract)->img = ft_calloc(1, sizeof(t_img));
	(*fract)->cam = ft_calloc(1, sizeof(t_cam));
	(*fract)->core = ft_calloc(1, sizeof(t_core));
	(*fract)->cplx = ft_calloc(1, sizeof(t_complex));
}
