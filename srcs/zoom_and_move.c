/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_and_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:39:16 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/04 11:46:32 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

void	zoom_and_move(t_bui_element *elem, t_bui_libui *libui, t_brush *brush)
{
	t_xywh new_coord;
	SDL_Surface	*surface;
	int org_w = elem->position.w;
	int org_h = elem->position.h;

	if (mouse_wheel(libui))
	{
		new_coord = elem->position;
		new_coord.h = ((org_w - (libui->mouse_wheel_y * 10)) / ((float)org_w / (float)org_h));
		new_coord.w = (new_coord.h * ((float)org_w / (float)org_h));
		if (new_coord.h > 10 && new_coord.w > 10)
		{
			brush->zoom += libui->mouse_wheel_y * 10;
			bui_resize_element(elem, new_coord);
		}
	}
	else if (libui->mouse_drag)
	{
		elem->position.x = libui->mouse_x - (elem->position.w / 2);
		elem->position.y = libui->mouse_y - (elem->position.h / 2);
	}
}
