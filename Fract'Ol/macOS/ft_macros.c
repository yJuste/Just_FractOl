/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

// ----------------------------------PROTOTYPE----------------------------------
int			ft_key_hook(int keycode, t_fract *fract);
int			ft_mouse_hook(int button, int x, int y, t_fract *fract);
void		ft_key_zoom_and_precision(int keycode, t_fract *fract);
void		ft_key_translate(int keycode, t_fract *fract);
// -----------------------------------------------------------------------------

// Fonction principale qui appelle les différentes touches pressées.
int	ft_key_hook(int keycode, t_fract *fract)
{
	if (keycode == NUM_PAD_PLUS || keycode == MAIN_PAD_PLUS
		|| keycode == NUM_PAD_MINUS || keycode == MAIN_PAD_MINUS
		|| keycode == NUM_PAD_1 || keycode == NUM_PAD_4
		|| keycode == MAIN_PAD_1 || keycode == MAIN_PAD_2)
		ft_key_zoom_and_precision(keycode, fract);
	else if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT
		|| keycode == ARROW_UP || keycode == ARROW_DOWN
		|| keycode == KEY_R)
		ft_key_translate(keycode, fract);
	else if (keycode == MAIN_PAD_ESC)
		ft_close_window(fract);
	return (0);
}

// Gére les touches de ZOOM.
void	ft_key_zoom_and_precision(int keycode, t_fract *fract)
{
	if (keycode == NUM_PAD_PLUS
		|| keycode == MAIN_PAD_PLUS)
		fract->core->iteration += 5;
	else if (keycode == NUM_PAD_MINUS
		|| keycode == MAIN_PAD_MINUS)
		fract->core->iteration -= 5;
	else if (keycode == NUM_PAD_1
		|| keycode == MAIN_PAD_1)
		fract->cam->zoom *= 1.1;
	else if (keycode == NUM_PAD_4
		|| keycode == MAIN_PAD_2)
		fract->cam->zoom *= 0.9;
	if (fract->core->iteration <= 0)
		fract->core->iteration = 5;
}

// Gére les touches de TRANSLATION.
void	ft_key_translate(int keycode, t_fract *fract)
{
	if (keycode == KEY_R)
	{
		ft_fractol(fract);
		return ;
	}
	if (keycode == ARROW_LEFT)
		fract->cam->offset_x -= (0.5 * fract->cam->zoom);
	else if (keycode == ARROW_RIGHT)
		fract->cam->offset_x += (0.5 * fract->cam->zoom);
	else if (keycode == ARROW_DOWN)
		fract->cam->offset_y += (0.5 * fract->cam->zoom);
	else if (keycode == ARROW_UP)
		fract->cam->offset_y -= (0.5 * fract->cam->zoom);
}
