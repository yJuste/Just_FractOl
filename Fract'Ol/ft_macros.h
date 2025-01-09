/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Gestion des touches du clavier.                                        */
/* ************************************************************************** */
#ifndef FT_MACROS_H
# define FT_MACROS_H

// Utilise la même valeure pour ne pas déformer la fractale.
# define WIDTH			800
# define HEIGHT			800

// Colors

# define BLACK			0x000000
# define WHITE			0xffffff
# define RED			0xff0000
# define GREEN			0x00ff00
# define BLUE			0x0000ff

// For exiting and Reset.

# define MAIN_PAD_ESC		53
# define KEY_R			15

// For the ZOOM.

# define SCROLL_UP		4
# define SCROLL_DOWN		5

# define NUM_PAD_1		83
# define NUM_PAD_4		86
# define MAIN_PAD_1		18
# define MAIN_PAD_2		19

// For the TRANSLATION.

# define ARROW_LEFT		123
# define ARROW_RIGHT		124
# define ARROW_DOWN		125
# define ARROW_UP		126

// For the PPRECISION.

# define NUM_PAD_PLUS		69
# define MAIN_PAD_PLUS		24

# define NUM_PAD_MINUS		78
# define MAIN_PAD_MINUS		27

#endif
