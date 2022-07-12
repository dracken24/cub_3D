/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:06:40 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/28 18:16:12 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3D.h"

void	init_imgs(t_game *game, t_imgs *imgs)
{
	int	x;
	int	y;
	imgs->wall.wall_01 = mlx_xpm_file_to_image(game->mlx, "../imgs/wall.xpm", &x, &y);
	printf("INIT_IMG\n");
}
