/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:35:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 13:40:50 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx_handler.h"

int	loop_handler(t_sys *sys)
{
	void	*img;

	img = update(sys);
	mlx_put_image_to_window(sys->mlx, sys->win, img, 0, 0);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_sys *sys)
{
	//クリックした場所の色の情報などが取れるといいかもしれぬ
	return (0);
}

int	key_handler(int key, t_sys *sys)
{
	int	num;

	// printf("key: %d\n", key);
	num = sys->obj->num_of_camera;
	if (key == ESCAPE)
		exit_handler(sys);
	if (key == UP)
	{
		sys->obj->id_of_camera++;
		sys->obj->id_of_camera %= num;
	}
	if (key == DOWN)
	{
		sys->obj->id_of_camera--;
		sys->obj->id_of_camera += num;
		sys->obj->id_of_camera %= num;
	}
	if (0 <= key - '0' && key - '0' < num)
		sys->obj->id_of_camera = key - '0';
	printf("camera id %d\n", sys->obj->id_of_camera);
	return (0);
}

int	exit_handler(t_sys *sys)
{
	// mlx_destroy_image(sys->mlx, sys->img.img);
	system_exit(sys, 0);
	return (0);
}