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
void		ft_parse_arguments(t_fract *fract, char **argv);
void		ft_help(t_fract *fract);
// -------------------------------------------------

void	ft_parse_arguments(t_fract *fract, char **argv)
{
	fract->core->set = 'm';
	/*
	ft_strlowcase(argv[1]);
	if (ft_strcmp(argv[1], "1") == 0
		|| ft_strcmp(argv[1], "julia") == 0)
		fract->core->set = 'j';
	else if (ft_strcmp(argv[1], "2") == 0
		|| ft_strcmp(argv[1], "mandelbrot") == 0)
		fract->core->set = 'm';
	else
		ft_help(fract);
	if (argv[2])
	{
		if (ft_strcmp(argv[2], "a") == 0)
			return ;
		else if (ft_strcmp(argv[2], "b") == 0)
			return ;
		else if (ft_strcmp(argv[2], "c") == 0)
			return ;
		else
			ft_help(fract);
	}
	*/
	return ;
}

void	ft_help(t_fract *fract)
{
	ft_printf(1, "\033[92m./fractol [sets] [version]\033[0m\n\n");
	ft_printf(1, "sets:\t\t[1] julia\t[2] mandelbrot\n");
	ft_printf(1, "version:\t[a] classic\t[b] colored\t[c] fade\n");
	ft_printf(1, "\n=>   do `make help` for more.   <=\n");
	exit(3);
}
