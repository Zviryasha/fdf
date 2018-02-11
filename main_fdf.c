/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 14:43:23 by opanchen          #+#    #+#             */
/*   Updated: 2018/02/11 14:43:27 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int button(int key, void *param)
{
	param = NULL;
	printf("%d\n", key);
	return (key);
}

void	fdf(char *s)
{
	void	*mlx_ptr;
	void	*win_ptr;


	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fdf");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xffffff);
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 251, 0xffffff);
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 252, 0xffffff);
	mlx_key_hook(win_ptr, button, (void *)0);
	printf("%s\n", s);
	printf("OK!\n");
	mlx_loop(mlx_ptr);
}