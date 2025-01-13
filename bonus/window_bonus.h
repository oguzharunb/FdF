/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:02:15 by obastug           #+#    #+#             */
/*   Updated: 2025/01/13 15:25:32 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_BONUS_H
# define WINDOW_BONUS_H

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
# define N_KEY 110
# define M_KEY 109
# define T_KEY 116
# define U_KEY 117
# define ARROT_LEFT_KEY 65361
# define ARROW_UP_KEY 65362
# define ARROW_RIGHT_KEY 65363
# define ARROW_DOWN_KEY 65364
# define SPACE_KEY 32

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image;
}				t_mlx;

#endif