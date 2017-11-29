//
// Created by guiforge on 29/11/17.
//


#include <libtcaps.h>

BOOL	is_escape_enter(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_ESC_ENTER))
		return (true);
	return (false);
}