/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 22:35:44 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/31 21:32:03 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOL_H
# define BOOL_H

# ifdef _STDBOOL_H
#  define BOOL bool
# else
#  define BOOL t_bool
	typedef enum	e_bool
	{
		false = (1 == 0),
		true = (!false)
	}				t_bool;
# endif

#endif
