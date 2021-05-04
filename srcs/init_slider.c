/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_slider.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:07:15 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/04 10:59:17 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

static inline void	r_slider(t_info *info)
{
	t_xywh	coord;

	coord = ui_init_coords(25, 50, 225, 20);
	info->r_slider = bui_new_slider_preset(info->col_menu, coord);
	info->r_slider->button->text_y = 2;
	coord = info->r_slider->button->position;
	coord.w = coord.w + 2;
	bui_resize_element(info->r_slider->button, coord);
	bui_set_slider_values(info->r_slider, 127, 0, 255);
	bui_set_element_color(info->r_slider->slider, 0xffffffff);
	bui_set_element_color(info->r_slider->button, 0xffff0000);
}

static inline void	g_slider(t_info *info)
{
	t_xywh	coord;

	coord = ui_init_coords(25, 76, 225, 20);
	info->g_slider = bui_new_slider_preset(info->col_menu, coord);
	info->g_slider->button->text_y = 2;
	coord = info->g_slider->button->position;
	coord.w = coord.w + 2;
	bui_resize_element(info->g_slider->button, coord);
	bui_set_slider_values(info->g_slider, 127, 0, 255);
	bui_set_element_color(info->g_slider->slider, 0xffffffff);
	bui_set_element_color(info->g_slider->button, 0xff00ff00);
}

static inline void	b_slider(t_info *info)
{
	t_xywh	coord;

	coord = ui_init_coords(25, 102, 225, 20);
	info->b_slider = bui_new_slider_preset(info->col_menu, coord);
	info->b_slider->button->text_y = 2;
	coord = info->b_slider->button->position;
	coord.w = coord.w + 2;
	bui_resize_element(info->b_slider->button, coord);
	bui_set_slider_values(info->b_slider, 127, 0, 255);
	bui_set_element_color(info->b_slider->slider, 0xffffffff);
	bui_set_element_color(info->b_slider->button, 0xff0000ff);
}

static inline void	a_slider(t_info *info)
{
	t_xywh	coord;

	coord = ui_init_coords(25, 154, 225, 20);
	info->a_slider = bui_new_slider_preset(info->col_menu, coord);
	info->a_slider->button->text_y = 2;
	coord = info->a_slider->button->position;
	coord.w = coord.w + 2;
	bui_resize_element(info->a_slider->button, coord);
	bui_set_slider_values(info->a_slider, 255, 0, 255);
	bui_set_element_color(info->a_slider->slider, 0xffffffff);
	bui_set_element_color(info->a_slider->button, 0xff535353);
}

static inline void	size_slider(t_info *info)
{
	t_xywh	coord;

	coord = ui_init_coords(25, 128, 225, 20);
	info->size_slider = bui_new_slider_preset(info->col_menu, coord);
	info->size_slider->button->text_y = 2;
	coord = info->size_slider->button->position;
	coord.w = coord.w + 2;
	bui_resize_element(info->size_slider->button, coord);
	bui_set_slider_values(info->size_slider, 3, 0, 255);
	bui_set_element_color(info->size_slider->slider, 0xffffffff);
	bui_set_element_color(info->size_slider->button, 0xffa9a9a9);
}

void				slider_init(t_info *info)
{
	r_slider(info);
	g_slider(info);
	b_slider(info);
	a_slider(info);
	size_slider(info);
}
