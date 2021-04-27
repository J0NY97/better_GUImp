/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_and_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:39:16 by nneronin          #+#    #+#             */
/*   Updated: 2021/04/27 12:49:51 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

void	zoom_and_move(t_bui_element *elem, SDL_Event event, int org_w, int org_h)
{
	int			w;
	int			h;
	t_brush		*brush;
	SDL_Surface	*surface;

	if (event.type == SDL_MOUSEWHEEL && event.wheel.y != 0)
	{
		brush = malloc(sizeof(t_brush));// TODO: elem->extra_info;
		brush->zoom += event.wheel.y > 0 ? -10 : 10;
		h = ((org_w - brush->zoom) / ((float)org_w / (float)org_h));
		w = (h * ((float)org_w / (float)org_h));
		surface = create_surface(w, h);
		SDL_FreeSurface(elem->active_surface);

		elem->position.w = surface->w;
		elem->position.h = surface->h;
		/*
		elem->rel_coord.w = surface->w;
		elem->rel_coord.h = surface->h;
		*/
		elem->active_surface = surface;
	}
	else
	{
		elem->position.x = event.button.x - (elem->position.w / 2);
		elem->position.y = event.button.y - (elem->position.h / 2);
		/*
		elem->rel_coord.x = event.button.x - (elem->surface->w / 2);
		elem->rel_coord.y = event.button.y - (elem->surface->h / 2);
		*/
	}
}
