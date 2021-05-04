/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tool_buttons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:13:39 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/04 12:34:42 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

static inline void	tool_buttons(t_info *info)
{
	t_xywh coord;
	info->buttons = NULL;
	info->active_tool_button = NULL;
	int minim = min(100, 50);  // aka all the elements w and h

	// Circle
	coord = ui_init_coords(25, 25, 100, 50);
	info->pencil_button = bui_new_element(info->brush_menu, NULL, coord);
	bui_set_element_image(info->pencil_button, ELEMENT_ALL, info->tooltips.circle, &(t_xywh){coord.w - minim - (minim / 2), 0, minim, minim});
	add_to_list(&info->buttons, info->pencil_button, sizeof(t_bui_element));

	coord = ui_init_coords(150, 25, 100, 50);
	info->text_button = bui_new_element(info->brush_menu, "Text", coord);
	bui_set_element_text_font(info->text_button, "DroidSans.ttf", 20, info->text_button->text_color);
	info->text_button->text_x = (info->text_button->position.w / 2) - (info->text_button->text_surface->w / 2);
	info->text_button->text_y = (info->text_button->position.h / 2) - (info->text_button->text_surface->h / 2);
	add_to_list(&info->buttons, info->text_button, sizeof(t_bui_element));

	coord = ui_init_coords(275, 25, 100, 50);
	info->deletion_button = bui_new_element(info->brush_menu, NULL, coord);
	bui_set_element_image(info->deletion_button, ELEMENT_ALL, info->tooltips.deletion, &(t_xywh){coord.w - minim - (minim / 2), 0, minim, minim});
	add_to_list(&info->buttons, info->deletion_button, sizeof(t_bui_element));

	coord = ui_init_coords(25, 100, 100, 50);
	info->flood_button = bui_new_element(info->brush_menu, NULL, coord);
	bui_set_element_image(info->flood_button, ELEMENT_ALL, info->tooltips.flood, &(t_xywh){coord.w - minim - (minim / 2), 0, minim, minim});
	add_to_list(&info->buttons, info->flood_button, sizeof(t_bui_element));

	coord = ui_init_coords(150, 100, 100, 50);
	info->sticker_button = bui_new_element(info->brush_menu, NULL, coord);
	bui_set_element_image(info->sticker_button, ELEMENT_ALL, info->tooltips.sticker, &(t_xywh){coord.w - minim - (minim / 2), 0, minim, minim});
	add_to_list(&info->buttons, info->sticker_button, sizeof(t_bui_element));

	coord = ui_init_coords(275, 100, 100, 50);
	info->move_button = bui_new_element(info->brush_menu, NULL, coord);
	bui_set_element_image(info->move_button, ELEMENT_ALL, info->tooltips.move, &(t_xywh){coord.w - minim - (minim / 2), 0, minim, minim});
	add_to_list(&info->buttons, info->move_button, sizeof(t_bui_element));

	coord = ui_init_coords(25, 175, 100, 50);
	info->shape_button = bui_new_element(info->brush_menu, NULL, coord);
	bui_set_element_image(info->shape_button, ELEMENT_ALL, info->tooltips.shapes, &(t_xywh){coord.w - minim - (minim / 2), 0, minim, minim});
	add_to_list(&info->buttons, info->shape_button, sizeof(t_bui_element));

	coord = ui_init_coords(150, 175, 100, 50);
	info->pipette_button = bui_new_element(info->brush_menu, NULL, coord);
	bui_set_element_image(info->pipette_button, ELEMENT_ALL, info->tooltips.pipette, &(t_xywh){coord.w - minim - (minim / 2), 0, minim, minim});
	add_to_list(&info->buttons, info->pipette_button, sizeof(t_bui_element));
	/*
	info->buttons[0] = ui_create_button(info->toolbox->window,
			ui_init_coords(25, 25, 100, 50), info->brush_menu);
	ft_set_element_image(info->buttons[0], info->tooltips.circle);
	info->buttons[1] = ui_create_button(info->toolbox->window,
		ui_init_coords(150, 25, 100, 50), info->brush_menu);
	ft_set_text(&info->buttons[1]->text, "Text");
	info->buttons[2] = ui_create_button(info->toolbox->window,
		ui_init_coords(275, 25, 100, 50), info->brush_menu);
	ft_set_element_image(info->buttons[2], info->tooltips.deletion);
	info->buttons[3] = ui_create_button(info->toolbox->window,
		ui_init_coords(25, 100, 100, 50), info->brush_menu);
	ft_set_element_image(info->buttons[3], info->tooltips.flood);
	info->buttons[4] = ui_create_button(info->toolbox->window,
		ui_init_coords(150, 100, 100, 50), info->brush_menu);
	ft_set_element_image(info->buttons[4], info->tooltips.sticker);
	info->buttons[5] = ui_create_button(info->toolbox->window,
		ui_init_coords(275, 100, 100, 50), info->brush_menu);
	ft_set_element_image(info->buttons[5], info->tooltips.move);
	info->buttons[6] = ui_create_button(info->toolbox->window,
		ui_init_coords(25, 175, 100, 50), info->brush_menu);
	ft_set_element_image(info->buttons[6], info->tooltips.shapes);
	info->buttons[7] = ui_create_button(info->toolbox->window,
		ui_init_coords(150, 175, 100, 50), info->brush_menu);
	ft_set_element_image(info->buttons[7], info->tooltips.pipette);
	*/
}

void				tool_buttons_init(t_info *info)
{
	int			i;
	SDL_Rect	temp;

	tool_buttons(info);
	/*
	i = -1;
	tool_buttons(info);
	info->buttons[0]->default_state = 1;
	ui_create_scrollbar(info->toolbox->window, info->buttons[7]);
	info->brush_button_amount = 8;
	while (++i < info->brush_button_amount)
	{
		info->buttons[i]->f = &ft_toggle_elem_group;
		info->buttons[i]->extra_info = info->buttons;
		info->buttons[i]->text.centered = 1;
		((t_button *)info->buttons[i]->info)->extra =
			&info->brush_button_amount;
	}
	*/
}
