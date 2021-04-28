/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_layers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:29:01 by nneronin          #+#    #+#             */
/*   Updated: 2021/04/28 16:34:28 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

static inline void	layer_background(t_info *info)
{
	int		i;
	t_xywh	coord;

	/*
	coord = ui_init_coords(51, 50,
		info->main->window->surface->w - 100,
		info->main->window->surface->h - 100);
	i = -1;
	while (++i < LAYER_NBR)
	{
		info->drawing_surface[i] = ui_create_surface(NULL, coord, NULL);
		info->drawing_surface[i]->statique = 1;
		ft_update_elem_background(info->drawing_surface[i], 0x00ffffff);
	}
	*/
}

static inline void	layer_create_old(t_info *info)
{
	t_xywh	coord;

	/*
	int		i;
	i = -1;
	while (++i < LAYER_NBR)
	{
		coord = ui_init_coords(50, i * 200 + (i * 25) + 25,
				info->layer_menu->surface->w - 100, 200);
		info->layer_buttons[i] = ui_create_button(info->layers->window,
				coord, info->layer_menu);
		info->layer_buttons[i]->f = &ft_toggle_elem_group;
		info->layer_buttons[i]->extra_info = info->layer_buttons;
		((t_button *)info->layer_buttons[i]->info)->extra = &info->layer_amount;

		coord = ui_init_coords(10, 10, info->layer_buttons[i]->surface->w - 20,
				info->layer_buttons[i]->surface->h - 20);
		info->layer_layers[i] = ui_create_surface(info->layers->window,
				coord, info->layer_buttons[i]);
		ft_update_elem_background(info->layer_layers[i], 0xfff9f9f9);
	}
	*/
}

void	layer_create(t_bui_element *parent, t_list **list, int count)
{
	t_layer *layer;
	t_xywh coord;

	layer = malloc(sizeof(t_layer));

	coord = ui_init_coords(50, count * 200 + (count * 25) + 25, parent->position.w - 100, 200);
	layer->button = bui_new_element(parent, NULL, coord);
	bui_set_element_color(layer->button, 0xff00ff00);

	coord = ui_init_coords(10, 10, layer->button->position.w - 20, layer->button->position.h - 20);
	layer->element = bui_new_element(layer->button, NULL, coord);

//	shadow(layer->element);
//	shadow(layer->button);

	add_to_list(list, layer, sizeof(t_layer));
}

void				layer_init(t_info *info)
{
	t_xywh	coord;

	coord = ui_init_coords(275, 50, 100, 100);
	info->brush_color = bui_new_element(info->col_menu, NULL, coord);

	info->all_layers = NULL;
	info->layer_amount = 0;	

	layer_create(info->layer_menu, &info->all_layers, info->layer_amount++);
	/*
	coord = ui_init_coords(0, 0,
		info->main->window->surface->w, info->main->window->surface->h);
	info->hidden_surface = ui_create_surface(info->main->window, coord, NULL);
	info->hidden_surface->shadow = 0;
	info->hidden_surface->event_handler = NULL;
	info->hidden_surface->statique = 1;
	ft_update_elem_background(info->hidden_surface, 0x00000000);
	layer_background(info);
	ft_update_elem_background(info->drawing_surface[0], 0xffffffff);
	coord = ui_init_coords(51, 50,
		info->main->window->surface->w - 100,
		info->main->window->surface->h - 100);
	info->screen_surface = ui_create_surface(info->main->window, coord, NULL);
	info->screen_surface->f = &draw;
	info->screen_surface->extra_info = &info->brush;
	info->screen_surface->statique = 1;
	((t_surface *)info->screen_surface->info)->extra = info->drawing_surface;
	ft_update_elem_background(info->screen_surface, 0xff000000);
	info->brush_color = ui_create_surface(info->toolbox->window,
			ui_init_coords(275, 50, 100, 100), info->col_menu);
	info->brush_color->f = NULL;
	info->brush_color->statique = 1;
	layer_create(info);
	*/
}
