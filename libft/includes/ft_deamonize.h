#ifndef DEAMONIZE_H
# define DEAMONIZE_H

/*
** Bit-mask for `flags` argument of deamonize
*/

#define D_NO_CHDIR			01
#define D_NO_CLOSE_FILES	02
#define D_NO_REOPEN_STD_FDS	04

#define D_NO_UMASK0			10

#define D_MAX_CLOSE			8192

int	ft_deamonize(int flags);
#endif