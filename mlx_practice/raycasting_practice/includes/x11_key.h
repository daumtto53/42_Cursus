#ifndef X11_KEY_H
# define X11_KEY_H

/* LINUX X11_EVENTS & MASK */
# define KEYPRESS 02
# define KEYRELEASE 03
# define DESTORY_NOTIFY 17
# define CLIENTMESSAGE 33

# define KEYPRESSMASK 1L << 0
# define KEYRELEASEMASK 1L << 1
# define BUTTONRELEASEMASK 1L<<3

# define	L_KEYSYM_A 0x61
# define	L_KEYSYM_S 0x73
# define	L_KEYSYM_D 0x64
# define	L_KEYSYM_W 0x77
# define	L_KEYSYM_ESC 0xff1b
# define	L_KEYSYM_LEFT 0xff51
# define	L_KEYSYM_RIGHT	0xff53

/* MAC X11_EVENTS ##NO MASKS REQUIRED IN MAC## **/

# define	M_KEYSYM_ESC		53
# define 	M_KEYSYM_W			13
# define 	M_KEYSYM_A			0
# define 	M_KEYSYM_S			1
# define 	M_KEYSYM_D			2

#endif
