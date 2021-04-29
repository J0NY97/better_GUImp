/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_brush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 11:54:40 by nneronin          #+#    #+#             */
/*   Updated: 2021/04/29 16:40:31 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

static inline void	pipette(t_info *info)
{
	t_rgba color;

	color = hex_to_rgba(info->brush.color);
	bui_set_slider_values(info->r_slider, color.r, info->r_slider->min, info->r_slider->max);
	bui_set_slider_values(info->g_slider, color.g, info->g_slider->min, info->g_slider->max);
	bui_set_slider_values(info->b_slider, color.b, info->b_slider->min, info->b_slider->max);
	bui_set_slider_values(info->a_slider, color.a, info->a_slider->min, info->a_slider->max);
	/*
	SDL_Color color;

	color = hex_to_rgba(info->brush.color);
	ft_set_slider_value(info->r_slider, color.r);
	ft_set_slider_value(info->g_slider, color.g);
	ft_set_slider_value(info->b_slider, color.b);
	ft_set_slider_value(info->a_slider, color.a);
	*/
}

static inline void	color_combine(t_info *info)
{
	info->brush.color = rgba_to_hex((t_rgba) {
							.r = info->r_slider->value,
							.g = info->g_slider->value,
							.b = info->b_slider->value,
							.a = info->a_slider->value});
	info->brush.shape.color = info->brush.color;
	/*
	info->brush.color = rgb_to_hex(((t_slider *)info->r_slider->info)->value,
								((t_slider *)info->g_slider->info)->value,
								((t_slider *)info->b_slider->info)->value,
								((t_slider *)info->a_slider->info)->value);
	info->brush.shape.color = info->brush.color;
	*/
}

static inline void	while_loops(t_info *info)
{
	int i;

	// Tool Button Event Handling.
	i = only_one_button_toggled_at_a_time(info->buttons, &info->active_tool_button);
	if (bui_button_toggle(info->pencil_button))
		info->brush.type = 1;
	else if (bui_button_toggle(info->text_button))
		info->brush.type = 2;
	else if (bui_button_toggle(info->deletion_button))
		info->brush.type = 3;
	else if (bui_button_toggle(info->flood_button))
		info->brush.type = 4;
	else if (bui_button_toggle(info->sticker_button))
		info->brush.type = 5;
	else if (bui_button_toggle(info->move_button))
		info->brush.type = 6;
	else if (bui_button_toggle(info->shape_button))
		info->brush.type = 7;
	else if (bui_button_toggle(info->pipette_button))
		info->brush.type = 8;

	// Layer Button Event handling.
	only_one_button_toggled_at_a_time(info->all_layer_buttons, &info->active_layer);
	if (info->active_layer)
		info->brush.selected_layer = ft_atoi(&(info->active_layer->id[ft_strlen("layer")]));

	//ft_printf("Active Layer ID : %d.\n", info->brush.selected_layer);

	// Sticker Selection Drop Down
	preset_dropdown_events(info->drop_down);
	if (info->drop_down->active)
		info->brush.selected_sticker = ft_atoi(&(info->drop_down->active->id[ft_strlen("sticker")]));

	//ft_printf("Active Sticker ID : %d.\n", info->brush.selected_sticker);

	// Font Selection Drop Down
	preset_dropdown_events(info->font_down);
	if (info->font_down->active)
			info->brush.font_dir = ft_strjoiner("libui/TTF/", info->font_down->active->text, NULL);

	//ft_printf("Active Font : %s.\n", info->brush.font_dir);
	
	only_one_button_toggled_at_a_time(info->shapes, &info->active_shape);
	if (bui_button_toggle(info->orb_shape))
		info->brush.shape_type = 0;
	else if (bui_button_toggle(info->square_shape))
		info->brush.shape_type = 1;
	else if (bui_button_toggle(info->tube_shape))
		info->brush.shape_type = 2;
	
	//ft_printf("Active Shape ID : %d.\n", info->brush.shape_type);
	
	if (bui_button(info->new_layer_button))
		layer_create(info, info->layer_menu, &info->all_layers, info->layer_amount++);
	
	/*
	int	i;

	i = -1;
	while (++i < info->brush_button_amount)
		if (info->buttons[i]->state == 1)
			info->brush.type = i + 1;
	i = -1;
	while (++i < info->layer_amount)
		if (info->layer_buttons[i]->state == 1)
			info->brush.selected_layer = i;
	i = -1;
	while (++i < ((t_drop_down *)info->drop_down->info)->item_amount)
		if (((t_drop_down *)info->drop_down->info)->items[i]->state == 1)
			info->brush.selected_sticker = i;
	i = -1;
	while (++i < ((t_drop_down *)info->font_down->info)->item_amount)
		if (((t_drop_down *)info->font_down->info)->items[i]->state == 1)
			info->brush.font_dir = ft_strjoiner("libui/TTF/",
					((t_drop_down *)info->font_down->info)->items[i]->text.text,
					NULL);
	i = -1;
	while (++i < info->shapes_nbr)
		if (info->shapes[i]->state == 1)
			info->brush.shape_type = i + 1;
	*/
}

void				update_brush(t_info *info)
{
	while_loops(info);
	if (info->brush.type == 8)
		pipette(info);
	else
	{
		color_combine(info);
		if (info->brush.type == 2) 
		{
			ft_strdel(&info->brush.str);
			info->brush.str = ft_strdup(info->text_area->text);
		}
	}
	bui_set_element_color(info->brush_color, info->brush.color);
	info->brush.size = info->size_slider->value;
	/*
	if (info->brush.type == 8)
		pipette(info);
	else
		color_combine(info);
	info->brush.size = ((t_slider *)info->size_slider->info)->value;
	while_loops(info);
	free(info->brush.str);
	info->brush.str = ft_strdup(info->text_area->text.text);
	ft_update_background(info->brush_color->surface, info->brush.color);
	*/
}
