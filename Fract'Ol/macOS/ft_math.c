/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Regroupe les fonctions mathématiques.                                  */
/* ************************************************************************** */
#include "ft_fractol.h"

// ----------------------------------PROTOTYPE---------------------------------
double		ft_scale(double n, double new_min, double new_max, double old_max);
int			ft_gradient(t_fract *fract, int iteration);
int			ft_inverse(double x, int a, double n);
t_complex	ft_sum_cplx(t_complex z, t_complex c);
t_complex	ft_square_cplx(t_complex z);
// ----------------------------------------------------------------------------

// Fonction pour changer d'échelle de mesure.
// 	ex: [0;500] -> [-2;+2]
double	ft_scale(double n, double new_min, double new_max, double old_max)
{
	if (old_max == 0 && new_min == 0)
		return (new_min);
	return ((new_max - new_min) * (n - 0) / (old_max - 0) + new_min);
}

// Ajoute un gradient.
int	ft_gradient(t_fract *fract, int iteration)
{
	int		intensity;

	intensity = ft_scale(iteration, 50, 255, fract->core->iteration);
	return (intensity << 16 | intensity << 8 | intensity);
}

int	ft_inverse(double x, int a, double n)
{
	return (a / pow(x, n));
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
