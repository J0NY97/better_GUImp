#include "better_libui.h"

void	bui_element_set_id(t_bui_element *elem, char *id)
{
	if (elem->id)
		ft_strdel(&elem->id);
	elem->id = ft_strdup(id);
}
