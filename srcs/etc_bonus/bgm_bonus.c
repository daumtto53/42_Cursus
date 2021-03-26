#include "../../includes/raycasting.h"

void	play_background_music()
{
	int	a;

	a = system("canberra-gtk-play -f ./animal_crossing.wav --loop=100 &");
	a += 1;
}

void	kill_background_music()
{
	int	a;

	a = system("pkill canberra-gtk-pl");
	a += 1;
}
