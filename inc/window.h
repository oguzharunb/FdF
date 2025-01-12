/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:34:08 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/12 15:48:31 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define PADDED_WIDTH 1800
# define PADDED_HEIGHT 900

# define ON_DESTROY 17

# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define J_KEY 106
# define K_KEY 107
# define Q_KEY 113
# define E_KEY 101
# define ARROT_LEFT_KEY 65361
# define ARROW_UP_KEY 65362
# define ARROW_RIGHT_KEY 65363
# define ARROW_DOWN_KEY 65364
# define N_KEY 110
# define M_KEY 109
# define SPACE_KEY 32

// enum {
// 	ON_KEYDOWN = 2,
// 	ON_KEYUP = 3,
// 	ON_MOUSEDOWN = 4,
// 	ON_MOUSEUP = 5,
// 	ON_MOUSEMOVE = 6,
// 	ON_EXPOSE = 12,
// 	ON_DESTROY = 17
// };

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image;
}				t_mlx;

#endif