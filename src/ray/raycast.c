/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:35:29 by nadesjar          #+#    #+#             */
/*   Updated: 2022/07/29 12:31:17 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3D.h"


int	raycast_01(t_game *game)
{
	game->ct.x = (((int)game->pos_real_p1.x + (game->utils.tile_size / 2)) / game->utils.tile_size);
	game->ct.y = (int)game->pos_real_p1.y / game->utils.tile_size;
	game->ct.i = -1;
	while (++game->ct.i < (float)game->ray.nbr_ray)
	{
		first_ray(game, game->ct.i, ((int)game->pos_real_p1.x + (game->utils.tile_size / 2)),
				(int)game->pos_real_p1.y - (game->utils.tile_size / 2));
	}

	return (0);
}

void	first_ray(t_game *game, float i, float x, float y)
{
	game->ray.xx = game->pos_p1_min_map.x;
	game->ray.yy = game->pos_p1_min_map.y;
	game->ray.pi = game->utils.pi / 180;
	game->ct.kk = (int)y / game->utils.tile_size;
	game->ct.ii = (int)x / game->utils.tile_size;

	ray_again(game, i, x, y + game->utils.tile_size);
}

void	ray_again(t_game *game, float i, float x, float y)
{
	// int start_x;
	// int	start_y;
	
	// start_x = (int)x;
	// start_y = (int)y;
	while (game->map[game->ct.kk][game->ct.ii] != '1')
	{
		game->ct.kk = (int)y / game->utils.tile_size;
		game->ct.ii = (int)x / game->utils.tile_size;
		// if (game->map[game->ct.kk][game->ct.ii] == '1')
		// 	break;
		if (((int)x % game->utils.tile_size == 0
				|| (int)y % game->utils.tile_size == 0)
				&& game->ray.xx > (int)(game->utils.whide - game->utils.x_case * 6)
				&& game->ray.yy < (int)game->utils.y_case * 6)
		{
			mlx_pixel_put(game->mlx, game->win, game->ray.xx + 3,
					game->ray.yy + 3, 100000);
		}
		if ((int)x % game->utils.tile_size == 0
				|| (int)y % game->utils.tile_size == 0)
		{
			mlx_pixel_put(game->mlx, game->win, x,
					y, 100000);	
		}
		x += cosf(game->ray.angle * game->ray.pi + i * game->ray.pi / 12);
		y += sinf(game->ray.angle * game->ray.pi + i * game->ray.pi / 12);
		game->ray.xx += cosf(game->ray.angle * game->ray.pi + i * game->ray.pi / 12) / 32 * 6;
		game->ray.yy += sinf(game->ray.angle * game->ray.pi + i * game->ray.pi / 12) / 32 * 6;
	}
	// calculate_rays(start_x, (int)x, start_y, (int)y);
}

// void	calculate_rays(int start_x, int x, int start_y, int y)
// {
	
// }
