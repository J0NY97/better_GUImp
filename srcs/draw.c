/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:15:07 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/03 12:05:28 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

Uint32  get_color(SDL_Surface *surface, int x, int y)
{
    Uint32 *pixels;

	pixels = surface->pixels;
	return (pixels[y * surface->w + x]);
}

static inline void	pencil(SDL_Surface *surf, t_brush *brush, Uint32 color)
{
	if (brush->shape.x2 == -1 && brush->shape.y2 == -1)
		ft_create_circle(surf, color, brush->shape);
	if (brush->shape.x2 != -1 && brush->shape.y2 != -1)
		ft_create_line(surf, color, brush->shape);
}

static inline void	set_sticker(SDL_Surface *surf, t_brush *brush)
{
	SDL_Rect temp;

	temp.h = 0;
	temp.w = 0;
	temp.x = brush->shape.x1 -
		(brush->stickers[brush->selected_sticker]->w / 2);
	temp.y = brush->shape.y1 -
		(brush->stickers[brush->selected_sticker]->h / 2);
	SDL_BlitSurface(brush->stickers[brush->selected_sticker],
			NULL, surf, &temp);
}

static inline void	activate_draw(SDL_Surface *surface, t_brush *brush)
{
	if (brush->type == 1)
		pencil(surface, brush, brush->color);
	else if (brush->type == 2)
		text_to_screen(surface, brush->shape, brush->str, brush->font_dir);
	else if (brush->type == 4)
		flood_fill(surface, get_color(surface, brush->shape.x1,
			brush->shape.y1), brush->color, brush->shape.x1, brush->shape.y1);
	else if (brush->type == 5)
		set_sticker(surface, brush);
	else if (brush->type == 7)
		return (select_shape(surface, brush));
	else if (brush->type == 8)
		brush->color = get_color(surface, brush->shape.x1, brush->shape.y1);
	brush->shape.x2 = brush->shape.x1;
	brush->shape.y2 = brush->shape.y1;
}

static inline void	deactivate_draw(SDL_Surface *surface, t_brush *brush)
{
	if (brush->type == 7 && brush->shape.x2 != -1 && brush->shape.y2 != -1)
	{
		brush->shape.fill = 0;
		if (brush->shape_type == 1)
		{
			brush->shape.size = POS(brush->shape.y1 - brush->shape.y2) +
								POS(brush->shape.x1 - brush->shape.x2);
			ft_create_circle(surface, brush->color, brush->shape);
		}
		else if (brush->shape_type == 2)
			ft_create_square(surface, brush->color, brush->shape);
		else if (brush->shape_type == 3)
			ft_create_line(surface, brush->color, brush->shape);
	}
	brush->shape.x2 = -1;
	brush->shape.y2 = -1;
}

void				draw_old(SDL_Event event, t_bui_element *elem)
{
	t_brush		*brush;
	t_bui_element	**drawing_surfaces;
	SDL_Surface	*surface;

	/*
	drawing_surfaces =. ((t_surface *)elem->info)->extra;
	brush =  (t_brush *)elem->extra_info;
	brush->shape.fill = 1;
	brush->shape.size = brush->size;
	surface =  drawing_surfaces[brush->selected_layer]->surface;
	brush->aspect_x =  ((float)surface->w / (float)elem->surface->w);
	brush->aspect_y = ((float)surface->h / (float)elem->surface->h);
	brush->shape.x1 = (event.button.x - elem->coord.x) * brush->aspect_x;
	brush->shape.y1 = (event.button.y - elem->coord.y) * brush->aspect_y;
	if (event.type == SDL_MOUSEBUTTONUP)
		brush->draw = 0;
	else if (event.type == SDL_MOUSEBUTTONDOWN)
		brush->draw = 1;
		*/
	/* TODO: not sure that this is but do it.
	if (brush->draw == 1 && brush->type == 3)
		pencil(surface, brush,
			drawing_surfaces[brush->selected_layer]->bg_color);
*/
	/*
	else if (brush->draw == 1 && brush->type == 6)
		zoom_and_move(elem, event, surface->w, surface->h);
	else
		brush->draw == 1 ? activate_draw(surface, brush) :
			deactivate_draw(surface, brush);
	*/
}

t_bui_element	*get_from_layers_with_id(t_list *list, char *id)
{
	t_list *curr;
	t_layer *layer;

	curr = list;
	while (curr)
	{
		layer = curr->content;
		if (layer->element->id && ft_strequ(layer->button->id, id))
			break ;
		curr = curr->next;	
	}
	return (layer->drawing);
}

// NOTE: in the old version of the program, this is the thing that triggers when you click on the screen_surface
void	draw(t_bui_libui *libui, t_info *info)
{
	t_bui_element *drawing;
	SDL_Surface *surface;
	t_brush *brush;

	if (!info->active_layer)
		return ;

	drawing = get_from_layers_with_id(info->all_layers, info->active_layer->id);
	surface = drawing->active_surface;
	brush = &info->brush;

	brush->shape.fill = 1;
	brush->shape.size = brush->size;
	brush->aspect_x =  ((float)surface->w / (float)info->screen_surface->position.w);
	brush->aspect_y = ((float)surface->h / (float)info->screen_surface->position.h);
	brush->shape.x1 = (libui->mouse_x - info->screen_surface->position.x) * brush->aspect_x;
	brush->shape.y1 = (libui->mouse_y - info->screen_surface->position.y) * brush->aspect_y;

	brush->draw = 0;
	if (bui_button_allow_duplicate(info->screen_surface))
	{
		brush->draw = 1;		
	}
	if (brush->draw && brush->type == 3)
		pencil(surface, brush, 0x00ffffff);
	else if (brush->type == 6)
		zoom_and_move(info->screen_surface, libui, brush);
	else
		brush->draw == 1 ? activate_draw(surface, brush) : deactivate_draw(surface, brush);
}
