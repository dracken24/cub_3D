/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:29:24 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/30 15:58:54 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3D.h"

int	key_pressed(int key, t_game *game, t_imgs *imgs)
{
	// init_imgs(game, imgs);
	if (key == KEY_ESC_LINUX || key == KEY_ESC_MAC)
		kill_game(game, imgs, "Why did you kill me !#*@**#?");
	if (key == KEY_D_LINUX || key == KEY_D_MAC)
	{
		if (game->pos_real_p1.x > game->utils.whide - (game->utils.tile_size * 2))
			game->pos_real_p1.x -= 12;
		game->pos_real_p1.x += 12;
		printf("D\n");
	}
	if (key == KEY_A_LINUX || key == KEY_A_MAC)
	{
		if (game->pos_real_p1.x < game->utils.tile_size / 1.5)
			game->pos_real_p1.x += 12;
		game->pos_real_p1.x -= 12;
		printf("A\n");
	}
	if (key == KEY_W_LINUX || key == KEY_W_MAC)
	{
		if (game->pos_real_p1.y < game->utils.tile_size)
			game->pos_real_p1.y += 12;
		game->pos_real_p1.y -= 12;
		printf("W\n");
	}
	if (key == KEY_S_LINUX || key == KEY_S_MAC)
	{
		if (game->pos_real_p1.y > game->utils.height - (game->utils.tile_size * 2))
			game->pos_real_p1.y -= 12;
		game->pos_real_p1.y += 12;
		printf("S\n");
	}
	printf("KEY: %d\n", key);
	// mlx_clear_window(game->mlx, game->win);
	// game->pos_real_p1.x = game->pos_p1.x * game->utils.tile_size + game->ct.move_x;
	// game->pos_real_p1.y = game->pos_p1.y * game->utils.tile_size + game->ct.move_y;
	printf("X: %f  Y: %f\n", game->pos_real_p1.x, game->pos_real_p1.y);
	return (0);
}

int mouse_move(int x, int y, t_game *game)
{
	if (x < game->ct.last_x)
		game->ray.angle -= 1;
	if (x > game->ct.last_x)
		game->ray.angle += 1;
	printf("Mouse_Key: %f X: %d Y: %d\n", game->ray.angle, x, y);
	// mlx_mouse_hide();
	game->ct.last_x = x;
	game->ct.last_y = y;
	return (0);
}

// int	mouse_key(int key, int x, int y, t_game *game)
// {
// 	// mlx_mouse_move(game->win, x, y);

// 	if (key == KEY_M_L_LINUX)
// 	{
// 		game->ray.angle -= 6;
// 	}
// 	if (key == KEY_M_R_LINUX)
// 	{
// 		game->ray.angle += 6;
// 	}
// 	game->test = 0;
// 	printf("Mouse_Key: %f X: %d Y: %d\n", game->ray.angle, x, y);
// 	return (0);
// }

