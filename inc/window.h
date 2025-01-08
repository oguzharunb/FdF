/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:34:08 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/05 14:28:04 by obastug          ###   ########.fr       */
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