/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

// ----------------------------------PROTOTYPE----------------------------------
int			ft_mouse_hook(int button, int x, int y, t_fract *fract);
int			ft_mouse_tracker(int x, int y, t_fract *fract);
int			ft_mouse_tracker_next(int x, int y, t_fract *fract);
// -----------------------------------------------------------------------------

// Gère le scroll de la souris.
int	ft_mouse_hook(int button, int x, int y, t_fract *fract)
{
	if (button == SCROLL_UP)
		fract->cam->zoom *= 1.1;
	else if (button == SCROLL_DOWN)
		fract->cam->zoom *= 0.9;
	(void)x;
	(void)y;
	return (0);
}

// Gère le color shift lorsque la souris bouge.
int	ft_mouse_tracker(int x, int y, t_fract *fract)
{
	if (fract->core->statik == 1)
		return (0);
	if (fract->core->first_color == BLACK)
		fract->core->first_color = WHITE;
	else if (fract->core->first_color == WHITE)
		fract->core->first_color = RED;
	else if (fract->core->first_color == RED)
		fract->core->first_color = GREEN;
	else if (fract->core->first_color == GREEN)
		fract->core->first_color = BLUE;
	else if (fract->core->first_color == BLUE)
		fract->core->first_color = BLACK;
	if (fract->core->second_color == BLACK)
		fract->core->second_color = WHITE;
	else if (fract->core->second_color == WHITE)
		fract->core->second_color = RED;
	else if (fract->core->second_color == RED)
		fract->core->second_color = GREEN;
	else if (fract->core->second_color == GREEN)
		fract->core->second_color = BLUE;
	else if (fract->core->second_color == BLUE)
		fract->core->second_color = BLACK;
	ft_mouse_tracker_next(x, y, fract);
	return (0);
}

// Fonction qui track la souris et qui 'color shift'.
int	ft_mouse_tracker_next(int x, int y, t_fract *fract)
{
	int		max;
	int		min;

	max = fract->core->iteration + 20;
	min = fract->core->iteration - 20;
	if (fract->core->flg == 0)
	{
		fract->core->iteration++;
		if (fract->core->iteration == max)
			fract->core->flg = 1;
	}
	else if (fract->core->flg == 1)
	{
		fract->core->iteration--;
		if (fract->core->iteration == min)
			fract->core->flg = 0;
	}
	(void)x;
	(void)y;
	return (0);
}
