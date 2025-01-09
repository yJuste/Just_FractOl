/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated: 2025/01/09 20:34:59 by jlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Gestion des touches du clavier.                                        */
/* ************************************************************************** */
#ifndef FT_MACROS_H
# define FT_MACROS_H

// Utilise la même valeure pour ne pas déformer la fractale.
# define WIDTH			1300
# define HEIGHT			1300

// Colors

# define BLACK			0x000000
# define WHITE			0xffffff
# define RED			0xff0000
# define GREEN			0x00ff00
# define BLUE			0x0000ff

// For exiting and Reset.

# define MAIN_PAD_ESC		65307
# define KEY_R			114

// For the ZOOM.

# define SCROLL_UP		5
# define SCROLL_DOWN		4

# define NUM_PAD_1		65436
# define NUM_PAD_4		65430
# define MAIN_PAD_1		49
# define MAIN_PAD_2		50

// For the TRANSLATION.

# define ARROW_LEFT		65361
# define ARROW_RIGHT		65363
# define ARROW_DOWN		65364
# define ARROW_UP		65362

// For the PPRECISION.

# define NUM_PAD_PLUS		65451
# define MAIN_PAD_PLUS		61

# define NUM_PAD_MINUS		65453
# define MAIN_PAD_MINUS		45

#endif
