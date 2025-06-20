# include "cub3d.h"

void	draw_top_view_map(t_game *game, t_player *player)
{
	int	row;
	int col;

	(void)player;

	row = -1;
	while (game->map[++row])
	{
		col = -1;
		while (game->map[row][++col])
		{
			if (game->map[row][col] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->top_view->wall_img, col * TILE_SIZE, row * TILE_SIZE);
			else 
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->top_view->free_space_img, col * TILE_SIZE, row * TILE_SIZE);
		}
	}
}

void	draw_player_dot(t_player *player, t_game *game)
{
	int	pixel_x;
	int	pixel_y;
	int	radius;
	int	dx;
	int	dy;
	
	// >>> my question is i workd with the (TILE_SIZE = 32) in the 3d view and 2d
	pixel_x = player->p_x * TILE_SIZE; // column → horizontal → x
	pixel_y = player->p_y * TILE_SIZE; // row → vertical → y
	radius = 4;	// radius = 4 -> 8px
	dx = -radius;	// col
	while (dx <= radius)
	{
		// printf("dx = %d\n", dx);
		dy = -radius;	// row
		while (dy <= radius)
		{
			// printf("dy = %d\n", dy);
			if (dx * dx + dy * dy <= radius * radius)
			mlx_pixel_put(game->mlx_ptr, game->win_ptr,
				pixel_x + dx, pixel_y + dy, RED_COLOR);
				dy++;
			}
			dx++;
		}
}
