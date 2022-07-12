/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:35:29 by nadesjar          #+#    #+#             */
/*   Updated: 2022/07/02 18:14:34 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3D.h"


void	raycast_01(t_game *game)
{
	game->ct.x = (((int)game->pos_real_p1.x + (game->utils.tile_size / 2)) / game->utils.tile_size);
	game->ct.y = (int)game->pos_real_p1.y / game->utils.tile_size;
	game->ct.i = -1;
	while (++game->ct.i < 1)
	{
		put_ray(game, ((int)game->pos_real_p1.x + (game->utils.tile_size / 2)),
				(int)game->pos_real_p1.y - (game->utils.tile_size / 2));
		game->ct.y--;
	}
	// printf("p1_X: %f  p1_Y: %f\n", game->pos_real_p1.x, game->pos_real_p1.y);
}

void put_ray(t_game *game, float x, float y)
{
	float i;
	float k;
	float yy;
	float xx;
	float pi;

	// printf("RAY_2\n");
	pi = game->utils.pi / 180;
	yy = y + game->utils.tile_size;
	xx = x;
	i = -1.0f;
	while (++i < (float)game->ray.half_nbr_ray / 4)
	{
		// printf("COS: %f\n", cosf(game->ray.angle + i / 600));

		k = -1;
		while (++k <= game->ray.ray_len)
		{
			game->ct.kk = (int)yy / game->utils.tile_size;
			game->ct.ii = (int)xx / game->utils.tile_size;
			if (game->map[game->ct.kk][game->ct.ii] == '1')
				break;
			mlx_pixel_put(game->mlx, game->win, xx, yy, 100000);
			xx += cosf(game->ray.angle * pi  + i * pi / 1.3);
			yy += sinf(game->ray.angle * pi  + i * pi / 1.3);
		}

		yy = y + game->utils.tile_size;
		xx = x;
		k = -1;
		while (++k <= game->ray.ray_len)
		{
			game->ct.kk = (int)yy / game->utils.tile_size;
			game->ct.ii = (int)xx / game->utils.tile_size;
			if (game->map[game->ct.kk][game->ct.ii] == '1')
				break ;
			mlx_pixel_put(game->mlx, game->win, xx, yy, 100000);
			xx += cosf(game->ray.angle * pi - i * pi / 1.3);
			yy += sinf(game->ray.angle * pi - i * pi / 1.3);
		}
		yy = y + game->utils.tile_size;
		xx = x;
	}
}
