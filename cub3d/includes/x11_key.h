/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x11_key.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:01:02 by mchun             #+#    #+#             */
/*   Updated: 2021/03/23 00:01:06 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X11_KEY_H
# define X11_KEY_H

# define KEYPRESS 02
# define KEYRELEASE 03
# define DESTORY_NOTIFY 17
# define CLIENTMESSAGE 33

# define KEYPRESSMASK 1L
# define KEYRELEASEMASK 2L
# define BUTTONRELEASEMASK 8L

# define L_KEYSYM_A 0x61
# define L_KEYSYM_S 0x73
# define L_KEYSYM_D 0x64
# define L_KEYSYM_W 0x77
# define L_KEYSYM_ESC 0xff1b
# define L_KEYSYM_LEFT 0xff51
# define L_KEYSYM_RIGHT	0xff53

# define M_KEYSYM_ESC		53
# define M_KEYSYM_W			13
# define M_KEYSYM_A			0
# define M_KEYSYM_S			1
# define M_KEYSYM_D			2
# define M_KEYSYM_LEFT		123
# define M_KEYSYM_RIGHT		124

#endif
