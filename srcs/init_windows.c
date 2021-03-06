/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:38:29 by nneronin          #+#    #+#             */
/*   Updated: 2021/04/27 14:26:19 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

void	window_init(t_bui_libui *libui, t_info *info)
{
	t_xywh coord;

	coord = new_xywh(0, 0, 500, 1250);
	info->toolbox = bui_new_window(libui, "Toolbox", coord, 0);
	bui_set_window_color(info->toolbox, 0xffd3d3d3);

	coord = new_xywh(501, 0, 1000, 1250);
	info->main = bui_new_window(libui, "Canvas", coord, 0);
	bui_set_window_color(info->main, 0xffd3d3d3);

	coord = new_xywh(1502, 0, 500, 1250);
	info->layers = bui_new_window(libui, "Layers", coord, 0);
	bui_set_window_color(info->layers, 0xffd3d3d3);

	SDL_RaiseWindow(info->toolbox->win);
	SDL_RaiseWindow(info->main->win);
	SDL_RaiseWindow(info->layers->win);
}
