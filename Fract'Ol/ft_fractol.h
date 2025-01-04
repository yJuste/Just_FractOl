/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

/*
 * NOTE:
 * - La minilibx sur MacOS n'a pas été entièrement développé et c'est pour cette
 *	raison qu'il y a 1 leak de 32 bytes non atteignable dû au comportement
 *	de la lib.
 */

// Standard Libraries

# include <unistd.h>
# include <stdlib.h>

// strerror, errno
# include <string.h>
# include <errno.h>

# include <math.h>

// My libraries

// minilibX
# include "minilibx_macos/mlx.h"

# include "Get_Next_Line/get_next_line.h"
# include "Printf_fd/ft_printf.h"

# include "ft_macros.h"

// Structures

typedef struct s_fract	t_fract;
typedef struct s_img	t_img;

typedef struct s_fract
{
	void		*mlx;
	void		*win;
	t_img		*img;
}	t_fract;

typedef struct s_img
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			size;
	int			endian;
	int			red;
	int			green;
	int			blue;
}	t_img;

//	----------MY CODE----------

// ft_fractol.c


// ft_fractol_next.c

void		ft_fractol(t_fract *fract, t_img *img);
void		ft_fractol_next(t_fract *fract);
void		ft_help(t_fract *fract);

// ft_lib.c

void		*ft_calloc(size_t count, size_t size);

#endif
