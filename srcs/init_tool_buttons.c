/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tool_buttons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:13:39 by nneronin          #+#    #+#             */
/*   Updated: 2021/04/27 15:05:48 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

static inline void	tool_buttons(t_info *info)
{
	t_xywh coord;
	// Circle
	coord = ui_init_coords(25, 25, 100, 50);
	info->buttons[0] = bui_new_element(info->brush_menu, NULL, coord);
	bui_set_element_image(info->buttons[0], ELEMENT_ALL, info->tooltips.circle);

	coord = ui_init_coords(150, 25, 100, 50);
	info->buttons[1] = bui_new_element(info->brush_menu, "Text", coord);
	bui_set_element_text_font(info->buttons[1], "DroidSans.ttf", 20, info->buttons[1]->text_color);

	coord = ui_init_coords(275, 25, 100, 50);
	info->buttons[2] = bui_new_element(info->brush_menu, NULL, coord);
	bui_set_element_image(info->buttons[2], ELEMENT_ALL, info->tooltips.deletion);

	coord = ui_init_coords(25, 100, 100, 50);
	info->buttons[3] = bui_new_element(info->brush_menu, NULL, coord);
	bui_set_element_image(info->buttons[3], ELEMENT_ALL, info->tooltips.flood);

	coord = ui_init_coords(150, 100, 100, 50);
	info->buttons[4] = bui_new_element(info->brush_menu, NULL, coord);
	bui_set_element_image(info->buttons[4], ELEMENT_ALL, info->tooltips.sticker);

	coord = ui_init_coords(275, 100, 100, 50);
	info->buttons[5] = bui_new_element(info->brush_menu, NULL, coord);
	bui_set_element_image(info->buttons[5], ELEMENT_ALL, info->tooltips.move);

	coord = ui_init_coords(25, 175, 100, 50);
	info->buttons[6] = bui_new_element(info->brush_menu, NULL, coord);
	bui_set_element_image(info->buttons[6], ELEMENT_ALL, info->tooltips.shapes);

	coord = ui_init_coords(150, 175, 100, 50);
	info->buttons[7] = bui_new_element(info->brush_menu, NULL, coord);
	bui_set_element_image(info->buttons[7], ELEMENT_ALL, info->tooltips.pipette);
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
