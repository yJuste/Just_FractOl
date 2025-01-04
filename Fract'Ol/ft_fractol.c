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
#include "ft_fractol.h"

// --------------------PROTOTYPE--------------------
void		ft_init(t_fract **fract);
void		ft_error(t_fract *fract, int error);
// -------------------------------------------------

int	main(int argc, char **argv)
{
	t_fract		*fract;

	fract = NULL;
	if (argc == 2 || argc == 3)
	{
		ft_init(&fract);
		/*
		fdf->mlx = mlx_init();
		fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "Just'Fdf");
		ft_fractol(fract, fract->img);
		mlx_hook(fdf->win, 17, 0, ft_close_window, fdf);
		mlx_loop(fdf->mlx);
		*/
	}
	else
		return (ft_help(fract), 2);
	return (0);
}

// 1. Alloue de la mémoire pour chaque structure.
// 2. Met toutes les variables à 0.
void	ft_init(t_fract **fract)
{
	*fract = ft_calloc(1, sizeof(t_fract));
	(*fract)->img = ft_calloc(1, sizeof(t_img));
}

// Fonction d'erreur.
void	ft_error(t_fract *fract, int error)
{
	ft_printf(2, "%s\n", strerror(error));
	exit(error);
}
