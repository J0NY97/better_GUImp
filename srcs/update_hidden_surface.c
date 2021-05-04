/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_hiden_surface.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 10:40:35 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/04 16:02:16 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

static inline void	blit_tooltip2(t_info *info, t_shapes l)
{
	SDL_Rect temp;

	if (info->brush.type == 5)
	{
		temp = (SDL_Rect) {l.x1 - l.size / 2, l.y1 - l.size / 2, l.size, l.size};
		SDL_BlitScaled(info->brush.stickers[info->brush.selected_sticker],
				NULL, info->hidden_surface->active_surface, &temp);
	}
	else if (info->brush.type == 6)
	{
		temp = (SDL_Rect){l.x1 - (20 / 2), l.y1 - (20 / 2), 20, 20};
		SDL_BlitSurface(info->tooltips.move, NULL, info->hidden_surface->active_surface, &temp);
	}
	else if (info->brush.type == 7)
		trace_shape(info);
	else if (info->brush.type == 8)
	{
		temp = (SDL_Rect){l.x1, l.y1 - 20, 20, 20};
		SDL_BlitSurface(info->tooltips.pipette, NULL, info->hidden_surface->active_surface, &temp);
	}
	
	/*
	SDL_Rect temp;
	if (info->brush.type == 5)
	{
		temp = ft_sdl_rect(l.x1 - 128 / 2, l.y1 - 128 / 2, 128, 128);
		SDL_BlitSurface(info->brush.stickers[info->brush.selected_sticker],
				NULL, HIDDEN_SURF, &temp);
	}
	else if (info->brush.type == 6)
	{
		temp = ft_sdl_rect(l.x1 - (20 / 2), l.y1 - (20 / 2), 20, 20);
		SDL_BlitSurface(info->tooltips.move, NULL, HIDDEN_SURF, &temp);
	}
	else if (info->brush.type == 7)
		trace_shape(info);
	else if (info->brush.type == 8)
	{
		temp = ft_sdl_rect(l.x1, l.y1 - 20, 20, 20);
		SDL_BlitSurface(info->tooltips.pipette, NULL, HIDDEN_SURF, &temp);
	}
	*/
}

static inline void	blit_tooltip(t_info *info, t_shapes l)
{
	SDL_Rect temp;

	if (info->brush.type == 1)
		ft_create_circle(info->hidden_surface->active_surface, info->brush.color, l);
	else if (info->brush.type == 2)
		text_to_screen(info->hidden_surface->active_surface, l, info->brush.str, info->brush.font_dir);
	else if (info->brush.type == 3)
	{
		l.fill = 0;
		ft_create_circle(info->hidden_surface->active_surface, 0xff000000, l);
	}
	else if (info->brush.type == 4)
	{
		temp = (SDL_Rect) {l.x1, l.y1 - 20, 20, 20};
		SDL_BlitSurface(info->tooltips.flood, NULL, info->hidden_surface->active_surface, &temp);
	}
	else
		blit_tooltip2(info, l);

	/* OLD
	if (info->brush.type == 1)
		ft_create_circle(HIDDEN_SURF, info->brush.color, l);
	else if (info->brush.type == 2)
		text_to_screen(HIDDEN_SURF, l, info->brush.str, info->brush.font_dir);
	else if (info->brush.type == 3)
	{
		ft_create_circle(HIDDEN_SURF,
				info->drawing_surface[info->brush.selected_layer]->bg_color, l);
	}
	else if (info->brush.type == 4)
	{
		temp = ft_sdl_rect(l.x1, l.y1 - 20, 20, 20);
		SDL_BlitSurface(info->tooltips.flood, NULL, HIDDEN_SURF, &temp);
	}
	else
		blit_tooltip2(info, l);
	*/
}

void				update_hidden_surface(t_info *info, t_bui_libui *libui)
{
	t_shapes	l;

	l = info->brush.shape;
	l.x1 = libui->mouse_x;
	l.y1 = libui->mouse_y;
	l.size = info->brush.size / info->brush.aspect_x;
	if (SDL_GetMouseFocus() == info->main->win)
	{
		SDL_FillRect(info->hidden_surface->active_surface, &(SDL_Rect) {0, 0, info->main->position.w, info->main->position.h}, 0x00000000);
		l.fill = info->brush.type == 1 ? 0 : 1;
		blit_tooltip(info, l);
	}

	/* OLD
	t_shapes	l;

	l = info->brush.shape;
	l.x1 = libui->event.button.x;
	l.y1 = libui->event.button.y;
	l.size = info->brush.size / info->brush.aspect_x;
	ft_update_background(info->hidden_surface->surface, 0x00000000);
	if (libui->event.window.windowID == info->main->window->id)
	{
		l.fill = info->brush.type == 1 ? 0 : 1;
		blit_tooltip(info, l);
	}
	*/
}
