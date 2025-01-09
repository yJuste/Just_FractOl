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
void		ft_parse_arguments_next(t_fract *fract, char **argv);
void		ft_help(t_fract *fract);
// -------------------------------------------------

void	ft_parse_arguments(t_fract *fract, char **argv)
{
	fract->core->flg_iter = '0';
	ft_strlowcase(argv[1]);
	if (ft_strcmp(argv[1], "1") == 0
		|| ft_strcmp(argv[1], "julia") == 0)
		fract->core->set = 'j';
	else if (ft_strcmp(argv[1], "2") == 0
		|| ft_strcmp(argv[1], "mandelbrot") == 0)
		fract->core->set = 'm';
	else
		ft_help(fract);
	ft_parse_arguments_next(fract, argv);
}

void	ft_parse_arguments_next(t_fract *fract, char **argv)
{
	if (argv[2])
	{
		fract->core->flg_iter = '1';
		if (fract->core->set == 'j')
		{
			if (ft_strcmp(argv[2], "a") == 0
				|| ft_strcmp(argv[2], "b") == 0
				|| ft_strcmp(argv[2], "c") == 0)
				ft_options_julia(fract, argv);
			else
				ft_help(fract);
		}
		else if (fract->core->set == 'm')
		{
			if (ft_strcmp(argv[2], "a") == 0
				|| ft_strcmp(argv[2], "b") == 0
				|| ft_strcmp(argv[2], "c") == 0
				|| ft_strcmp(argv[2], "d") == 0)
				ft_options_mandelbrot(fract, argv);
			else
				ft_help(fract);
		}
	}
}

void	ft_help(t_fract *fract)
{
	ft_printf(1, "\033[92m./fractol [sets] [version]\033[0m\n\n");
	ft_printf(1, "sets:\t\t[1] julia\t[2] mandelbrot\n");
	ft_printf(1, "version for julia:\t[a] The Anchor\t");
	ft_printf(1, "[b] The Kiss\t[c] The Void\n");
	ft_printf(1, "version for mandelbrot:\t[a] Killua\t");
	ft_printf(1, "[b] Spaceship\t[c] Irruption\t[d] Evergreen\n");
	ft_printf(1, "\n=>   do `make help` for more.   <=\n");
	exit(3);
}
