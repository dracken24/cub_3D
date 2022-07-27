/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:00:53 by nadesjar          #+#    #+#             */
/*   Updated: 2022/07/26 16:43:51 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3D.h"

void	init_var(t_game *game)
{
	printf("INIT_VAR\n");
	game->utils.pi = 3.14159265358979f;
	game->utils.x_case = 42;
	game->utils.y_case = 28;
	game->utils.tile_size = 32;
	game->utils.wait = 5;
	game->utils.whide = game->utils.x_case * game->utils.tile_size;
	game->utils.height = game->utils.y_case * game->utils.tile_size;
	game->ray.radius = 5;
	game->ray.move_speed = 200.0f;
	game->ray.angle_speed = 100.0f;
	game->ray.fov = 60;
	game->ray.ray_len = 277.29f;
	game->ray.nbr_ray = 680;
	game->ct.move_x = 0;
	game->ct.move_y = 0;
	game->ct.time = 0.0f;
	game->ct.last_x = 0;
	game->ct.last_y = 0;
	game->len.max_len_x = 0;
	game->move_mini.x = 0;
	game->move_mini.y = 0;
	printf("INIT_VAR\n");
}
